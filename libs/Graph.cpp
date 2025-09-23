#include <Graph.hpp>
#include <queue>

template <typename T>
Graph<T>::Graph() {
    head = NULL;  
    vertexSize = 0;
    edgeSize = 0;
    name = "Graph";
}


template <typename T>
Graph<T>::Graph(const Graph<T>& other) : Graph<T>() {
    copy(other, *this); 
}

template <typename T>
void Graph<T>::createFromMap(const std::unordered_set<T>& vertex, const std::unordered_map<T, std::unordered_set<T> >& edges) {

    vertexSize = vertex.size();
    std::unordered_map<T,VertexNode<T>*> aux;

    for (auto it = vertex.begin(); it != vertex.end(); ++it) {
        VertexNode<T>* newVertext = new VertexNode<T>(*it, head);
        aux[*it] = newVertext;
        head = newVertext;
    }

    for (auto it = edges.begin(); it != edges.end(); ++it) {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            this->connectVertices(aux[it->first], aux[*it2]);
            edgeSize++;
        }
    }
}


template <typename T>
void Graph<T>::createFromMapEdges(const std::unordered_set<T>& vertex, const std::unordered_map<T, std::unordered_set<Edge<T> > >& edges) {
    
    vertexSize = vertex.size();
    std::unordered_map<T,VertexNode<T>*> aux;

    for (auto it = vertex.begin(); it != vertex.end(); ++it) {
        VertexNode<T>* newVertext = new VertexNode<T>(*it, head);
        aux[*it] = newVertext;
        head = newVertext;
    }

    for (auto it = edges.begin(); it != edges.end(); ++it) {
        for (auto it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
            this->connectVertices(aux[it->first], aux[it2->getValue()], it2->getWeight());
            edgeSize++;
        }
    }

}

template <typename T>
Graph<T>::~Graph() {
    clear();
}

template <typename T>
int Graph<T>::order() {
    return vertexSize;
}

template <typename T>
int Graph<T>::size() {
    return edgeSize;
}

template <typename T>
bool Graph<T>::empty() {
    return vertexSize == 0;
}

template <typename T>
void Graph<T>::clear() {
    VertexNode<T>* current = head;
    while (current) {
        VertexNode<T>* next = current->getNext();
        delete current;
        current = next;
    }
    head = NULL;
    vertexSize = 0;
    edgeSize = 0;
}

template <typename T>
void Graph<T>::addVertex(const T& vertex) {
    VertexNode<T>* newVertext = new VertexNode<T>(vertex, head);
    head = newVertext;
    vertexSize++;
}
template <typename T>
void Graph<T>::addEdge(const T& from, const T& to, float weight) {

  VertexNode<T>* fromNode = NULL;
  VertexNode<T>* toNode = NULL;
  
  findTwoVertices(from, to, fromNode, toNode);

  if (fromNode != NULL && toNode != NULL) {
      edgeSize++;
      connectVertices(fromNode, toNode, weight);
  }
}
template <typename T>
void Graph<T>::removeVertex(const T& vertex) {

    VertexNode<T>* dummy = new VertexNode<T>();
    dummy->setNext(head);
    VertexNode<T>* current = dummy;
    VertexNode<T>* prevToNodeToDelete;

    while (current->getNext() != NULL && current->getNext()->getValue() != vertex) {
        int neighborsSize = current->getNeighborsSize();
        current->removeNeightbor(vertex);
        if (neighborsSize - current->getNeighborsSize() != 0) {
            edgeSize--;
        }
        current = current->getNext();
    }
    prevToNodeToDelete = current;

    while (current != NULL) {
        int neighborsSize = current->getNeighborsSize();
        current->removeNeightbor(vertex);
        if (neighborsSize - current->getNeighborsSize() != 0) {
            edgeSize--;
        }
        current = current->getNext();
    }

    if (prevToNodeToDelete->getNext() != NULL) {
        VertexNode<T>* toDelete = prevToNodeToDelete->getNext();
        int neighborsSize = toDelete->getNeighborsSize();
        discountEdges(neighborsSize);
        prevToNodeToDelete->setNext(prevToNodeToDelete->getNext()->getNext());
        delete toDelete;
        vertexSize--;
    }
    head = dummy->getNext();
    delete dummy;
}

template <typename T>
void Graph<T>::removeEdge(const T& from, const T& to) {

  VertexNode<T>* fromNode = NULL;
  VertexNode<T>* toNode = NULL;
  
  findTwoVertices(from, to, fromNode, toNode);

  if (fromNode != NULL && toNode != NULL) {
      edgeSize--;
      this->unconnectVertices(fromNode, toNode);
  }
}
template <typename T>
bool Graph<T>::existVertex(const T& vertex) {

    VertexNode<T>* current = findVertex(vertex);

    return current != NULL;
}

template <typename T>
bool Graph<T>::existEdge(const T& from, const T& to) {

    VertexNode<T>* fromNode;
    VertexNode<T>* toNode;
    findTwoVertices(from, to, fromNode, toNode);

    return existEdge(fromNode, toNode);
}


template <typename T>
std::vector<T> Graph<T>::vertices() {
    std::vector<T> result;
    result.reserve(vertexSize);

    VertexNode<T>* current = head;

    while (current) {
        result.push_back(current->getValue());
        current = current->getNext();
    }

    return result;
}

template <typename T>
std::vector<std::vector<T> > Graph<T>::edges() {
    std::vector<std::vector<T> > result;
    result.reserve(edgeSize);

    VertexNode<T>* current = head;
    while (current) {
        std::vector<EdgeNode<T>* > edges = current->getEdges();
        for (EdgeNode<T>* edge : edges) {
            result.push_back(std::vector<T>());
            result[result.size() - 1].push_back(current->getValue());
            result[result.size() - 1].push_back(edge->getVertex()->getValue());
        }
        current = current->getNext();
    }

    return result;
}

template <typename T>
float Graph<T>::edgeWeight(const T& vertex1, const T& vertex2) {

    VertexNode<T>* node1, node2;

    findTwoVertices(vertex1, vertex2, node1, node2);

    if (node1 == NULL || node2 == NULL) {
        throw std::runtime_error("edge doesn't exist");
    } 
    return vertex1->getWeightForVertex(node2);
}

template <typename T>
std::vector<T> Graph<T>::neightbors(const T& value) {

    return successors(value);
}

template <typename T>
std::vector<T> Graph<T>::successors(const T& value) {

    VertexNode<T>* node = findVertex(value);
    if (node == NULL) {
        throw std::runtime_error("does'n have neightbors");
    }
    return node->getNeighborValues();
}

template <typename T>
std::vector<T> Graph<T>::predecessors(const T& value) {

    std::vector<T> result;
    result.reserve(vertexSize);
    VertexNode<T>* current = head;

    while (current) {
        if (current->existNeighbor(value)) {
            result.push_back(current->getValue());
        }
        current = current->getNext();
    }

    return result;
}


template <typename T>
std::vector<T> Graph<T>::bfs(const T& inicial) {

    std::vector<T> result;
    result.reserve(vertexSize);

    std::unordered_set<T> visited;
    std::queue<VertexNode<T>*> aux;
    VertexNode<T>* current = findVertex(inicial);

    if (current != NULL) {
        aux.push(current);
    }

    while (aux.empty()) {
        current = aux.front();
        aux.pop();
        result.push_back(current->getValue());

        std::vector<VertexNode<T>*> neighbors = current->getNeighbors();

        for (VertexNode<T>* neighbor : neighbors) {
            if (visited.find(neighbor->getValue()) == visited.end()) {
                visited.insert(neighbor->getValue());
                aux.push(neighbor);
            }
        }
    }

    return result; 
}
template <typename T>
std::vector<T> Graph<T>::dfs(const T& inicial) {

    std::vector<T> result;
    result.reserve(vertexSize);
    VertexNode<T>* nodoIncial = findVertex(inicial);

    if (nodoIncial != NULL) {
        std::unordered_set<T> visited;
        dfs(nodoIncial, visited, result);
    }

    return result; 
}


template <typename T>
void Graph<T>::dfs(VertexNode<T>* ptr, std::unordered_set<T>& visited, std::vector<T>& result) {

    if (visited.find(ptr->getValue()) != visited.end()) {
        return;
    }

    result.push_back(ptr->getValue());
    std::vector<T> neighbors = ptr->getNeighbors();

    for (VertexNode<T>* neighbor : neighbors) {
        dfs(neighbor, visited, result); 
    }
}


template <typename T>
Graph<T>& Graph<T>::operator=(const Graph<T>& other) {
    if (this == &other) {
        return *this;
    }
    copy(other, *this);    
}

template <typename T>
bool Graph<T>::operator==(Graph<T>& other) {
    if (edgeSize != other.edgeSize) {
        return false;
    }
    if (vertexSize != other.vertexSize) {
        return false;
    }

    VertexNode<T>* current1 = head; 
    VertexNode<T>* current2 = other.head;  
    std::unordered_map<T, VertexNode<T>*> aux1, aux2;
    std::unordered_set<T> values1, values2;

    while (current1 != NULL) {
    
        values1.insert(current1->getValue());
        values2.insert(current2->getValue());
        aux1[current1->getValue()] = current1;
        aux2[current2->getValue()] = current2;

        current1 = current1->getNext();
        current2 = current2->getNext();
    }
      
    bool isEqual = values1 == values2;

    if (isEqual) {
        int i = 0;
        auto it = values1.begin();
        while (i < vertexSize && isEqual) {
            const T& value = *it;
            std::unordered_set<Edge<T> > edges1, edges2;

            std::vector<EdgeNode<T>*> neighbors1 = aux1[value]->getEdges();
            std::vector<EdgeNode<T>*> neighbors2 = aux2[value]->getEdges();
            
            for (EdgeNode<T>* neighbor : neighbors1) {
                edges1.insert(Edge<T>(neighbor->getVertex()->getValue(), neighbor->getWeight()));
            }
            for (EdgeNode<T>* neighbor : neighbors2) {
                edges2.insert(Edge<T>(neighbor->getVertex()->getValue(), neighbor->getWeight()));
            }

            isEqual = edges1 == edges2;

            i++;
            it++;
        }
    }

    return isEqual;
}

template <typename T>
VertexNode<T>* Graph<T>::findVertex(const T& vertex) {
    VertexNode<T>* current = head;
    while (current) {
        if (current->getValue() == vertex) return current;
        current = current->getNext();
    }
    return NULL;
}

template <typename T>
void Graph<T>::findTwoVertices(const T& from, const T& to, VertexNode<T>*& fromNode, VertexNode<T>*& toNode) {
    fromNode = NULL;
    toNode = NULL;
    VertexNode<T>* current = head;
    while (current != NULL && (fromNode == NULL || toNode == NULL)) {
        if (current->getValue() == from) {
            fromNode = current;
        }
        if (current->getValue() == to) {
            toNode = current;
        }
        current = current->getNext();
    }
}

template <typename T>
void Graph<T>::connectVertices(VertexNode<T>* fromNode, VertexNode<T>* toNode, float weight) {
    fromNode->addNeightbor(toNode, weight);
    toNode->addNeightbor(fromNode, weight);
}

template <typename T>
void Graph<T>::unconnectVertices(VertexNode<T>* fromNode, VertexNode<T>* toNode) {
    fromNode->removeNeightbor(toNode);
    toNode->removeNeightbor(fromNode);
}

template <typename T>
void Graph<T>::copy(const Graph<T>& from, Graph<T>& to) {

    to.clear();

    VertexNode<T>* current = from.head;
    std::unordered_map<T,VertexNode<T>*> aux;
    to.vertexSize = from.vertexSize;
    to.edgeSize = from.edgeSize;

    while (current) {
        VertexNode<T>* newVertext = new VertexNode<T>(current->getValue(), to.head);
        to.head = newVertext;
        aux[current->getValue()] = newVertext;
        current = current->getNext();
    }

    current = from.head;
    while (current) {
        std::vector<VertexNode<T>*> neighbors = current->getNeighbors();
        for (VertexNode<T>* neighbor : neighbors) {
            if (existEdge(aux[current->getValue()], aux[neighbor->getValue()])) continue;

            to.connectVertices(aux[current->getValue()], aux[neighbor->getValue()]);
        }
        current = current->getNext();
    }
}

template <typename T>
bool Graph<T>::existEdge(VertexNode<T>* from, VertexNode<T>* to) {
    return from->existNeighbor(to->getValue());
}


template <typename T>
void Graph<T>::discountEdges(int numberOfEdge) {
    edgeSize = edgeSize - numberOfEdge + numberOfEdge; // solo hago esto para que se comporte diferencete en el grafo dirigido por el polimorfismo 
    // esto nadie lo va entender quiza haya una mejor manera de aplicar el polimorfismo para este caso pero en 
    // momento no lo veo
}

template <typename T>
std::ostream& operator<<(std::ostream& os, Graph<T>& graph) {
    VertexNode<T>* current = graph.head;

    os << graph.name << std::endl;
    os << "edgeSize: " << graph.edgeSize << std::endl;
    os << "vertexSize: " << graph.vertexSize << std::endl;
    while (current) {
        os << "Vertex: ";
        os << current->getValue() << ", neighbors -> ";
        std::vector<VertexNode<T>*> neighbors = current->getNeighbors();
        std::vector<float> weights = current->getWeights();

        auto that = weights.begin();
        for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
            os << "(" << (*it)->getValue() << " " << *that << ") ";
            ++that;
        }
        os << std::endl;
        current = current->getNext();
    }
    return os;
}


