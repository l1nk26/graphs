#include <VertexNode.hpp>
#include <stdexcept>

template <typename T>
VertexNode<T>::VertexNode() {
    neighbors = NULL;
    next = NULL;
    ID = vertexNodeInternals::id++;
}

template <typename T>
VertexNode<T>::VertexNode(const T& value, VertexNode<T>* next) {
    this->value = value;
    neighbors = NULL;
    this->next = next;
}

template <typename T>
VertexNode<T>::VertexNode(const T& value, std::list<VertexNode<T>*> neighbors, VertexNode<T>* next) {
    this->value = value;
    setNeighbors(neighbors);
    this->next = next;
}

template <typename T>
VertexNode<T>::VertexNode(const T& value, std::vector<VertexNode<T>*> neighbors, VertexNode<T>* next) {
    this->value = value;
    setNeighbors(neighbors);
    this->next = next;
}

template <typename T>
VertexNode<T>::~VertexNode() {
    cleanNeighbors();
}

template <typename T>
T& VertexNode<T>::getValue() { return value; }

template <typename T>
std::vector<VertexNode<T>*> VertexNode<T>::getNeighbors() { 
    std::vector<VertexNode<T>*> neighbors; 
    neighbors.reserve(neighborsSize);

    EdgeNode<T>* current = this->neighbors;
    while (current) {
        neighbors.push_back(current->getVertex());
        current = current->getNext();
    }

    return neighbors;
}

template <typename T>
std::vector<T> VertexNode<T>::getNeighborValues() {

    std::vector<VertexNode<T>*> neighborValues; 
    neighborValues.reserve(neighborsSize);

    EdgeNode<T>* current = this->neighbors;
    while (current) {
        neighborValues.push_back(current->getVertex()->getValue());
        current = current->getNext();
    }

    return neighborValues;
}

template <typename T>
int VertexNode<T>::getNeighborsSize() { return neighborsSize; }


template <typename T>
std::vector<EdgeNode<T>*> VertexNode<T>::getEdges() {

    std::vector<EdgeNode<T>*> edges; 
    edges.reserve(neighborsSize);

    EdgeNode<T>* current = this->neighbors;
    while (current) {
        edges.push_back(current);
        current = current->getNext();
    }

    return edges;

}

template <typename T>
std::vector<float> VertexNode<T>::getWeights() { 

    std::vector<float> weights; 
    weights.reserve(neighborsSize);

    EdgeNode<T>* current = this->neighbors;
    while (current) {
        weights.push_back(current->getWeight());
        current = current->getNext();
    }

    return weights;
}

template <typename T>
VertexNode<T>* VertexNode<T>::getNext() { return next; }

template <typename T>
void VertexNode<T>::setValue(const T& value) { this->value = value; }

template <typename T>
void VertexNode<T>::setNeighbors(std::list<VertexNode<T>*> neighbors) { 
    cleanNeighbors();
    neighborsSize = neighbors.size();
    EdgeNode<T>* dummy = new EdgeNode<T>();
    EdgeNode<T>* current = dummy;
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        current->next = new EdgeNode<T>(*it); 
        current = current->getNext();
    }
    neighbors = dummy->getNext();
    delete dummy;
}

template <typename T>
void VertexNode<T>::setNeighbors(std::list<VertexNode<T>*> neighbors, std::list<float> weights) { 

    cleanNeighbors();
    neighborsSize = neighbors.size();
    EdgeNode<T>* dummy = new EdgeNode<T>();
    EdgeNode<T>* current = dummy;
    auto that = weights.begin();
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        current->next = new EdgeNode<T>(*it, *that); 
        current = current->getNext();
        ++that;
    }
    neighbors = dummy->getNext();
    delete dummy;
}

template <typename T>
void VertexNode<T>::setNeighbors(std::vector<VertexNode<T>*> neighbors) { 

    cleanNeighbors();
    neighborsSize = neighbors.size();

    EdgeNode<T>* dummy = new EdgeNode<T>();
    EdgeNode<T>* current = dummy;
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        current->next = new EdgeNode<T>(*it); 
        current = current->getNext();
    }
    neighbors = dummy->getNext();
    delete dummy;
}

template <typename T>
void VertexNode<T>::setNeighbors(std::vector<VertexNode<T>*> neighbors, std::vector<float> weights) { 
  
    cleanNeighbors();
    neighborsSize = neighbors.size();
    EdgeNode<T>* dummy = new EdgeNode<T>();
    EdgeNode<T>* current = dummy;

    auto that = weights.begin();
    for (auto it = neighbors.begin(); it != neighbors.end(); ++it) {
        current->next = new EdgeNode<T>(*it, *that); 
        current = current->getNext();
        ++that;
    }
    neighbors = dummy->getNext();
    delete dummy;
}

template <typename T>
void VertexNode<T>::setNext(VertexNode<T>* next) { this->next = next; }

template <typename T>
void VertexNode<T>::addNeightbor(VertexNode<T>* newNeighbor, float weight ) {
    EdgeNode<T>* newEdge = new EdgeNode<T>(newNeighbor, weight, neighbors);
    neighbors = newEdge;
    neighborsSize++;
}

template <typename T>
void VertexNode<T>::removeNeightbor(VertexNode<T>* neighborToRemove) {
    EdgeNode<T>* dummy = new EdgeNode<T>();
    dummy->setNext(neighbors);
    EdgeNode<T>* current = dummy;
    while (current->getNext() && current->getNext()->getVertex() != neighborToRemove) {
        current = current->getNext();
    }
    if (current->getNext()) {
        EdgeNode<T>* toDelete = current->getNext();
        current->setNext(current->getNext()->getNext());
        delete toDelete;
        neighborsSize--;
    }
    neighbors = dummy->getNext();
    delete dummy;
}

template <typename T>
void VertexNode<T>::cleanNeighbors() { 
    EdgeNode<T>* current = neighbors;
    neighborsSize = 0;
    while (current) {
        EdgeNode<T>* next = current->getNext();
        delete current;
        current = next;
    }
}

template <typename T>
float VertexNode<T>::getWeightForVertex(VertexNode<T>* vertex) {
    return getWeightForValue(vertex->getValue());
}

template <typename T>
float VertexNode<T>::getWeightForValue(const T& value) {
    EdgeNode<T>* current = neighbors;
    while (current && current->getVertex()->getValue() != value) {
        current = current->getNext();
    }
    if (current) {
        return current->getWeight();
    } else {
        throw std::runtime_error("don't have a neightbor");
    }
}


template <typename T>
void VertexNode<T>::setWeightForVertex(VertexNode<T>* vertex, float weight) {
    EdgeNode<T>* current = neighbors;
    while (current && current->getVertex()->getValue() != vertex->getValue()) {
        current = current->getNext();
    }
    if (current) {
        current->setWeight(weight);
    }
}

template <typename T>
bool VertexNode<T>::existNeighbor(const T& value) {
    EdgeNode<T>* current = neighbors;
    while (current && current->getVertex()->getValue() != value) {
        current = current->getNext();
    }
    return current != NULL;
}
