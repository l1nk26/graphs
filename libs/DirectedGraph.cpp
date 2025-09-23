#include <DirectedGraph.hpp>

template <typename T>
DirectedGraph<T>::DirectedGraph() : Graph<T>() {
    this->name = "DirectedGraph";
}

template <typename T>
DirectedGraph<T>::DirectedGraph(const DirectedGraph& other) : DirectedGraph<T>() {
    this->copy(other, *this);
}

template <typename T>
void DirectedGraph<T>::connectVertices(VertexNode<T>* node1, VertexNode<T>* node2, float weight) {
    node1->addNeightbor(node2, weight); 
}

template <typename T>
void DirectedGraph<T>::unconnectVertices(VertexNode<T>* node1, VertexNode<T>* node2) {
    node1->removeNeightbor(node2); 
}

template <typename T>
void DirectedGraph<T>::discountEdges(int numberOfEdge) {
    this->edgeSize -= numberOfEdge;
}

template <typename T>
DirectedGraph<T>::~DirectedGraph() {}
        
template <typename T>
std::vector<T> DirectedGraph<T>::neightbors(const T& value) {
    std::vector<T> successors = this->successors(value);
    std::vector<T> predecessors = this->predecessors(value);
    std::unordered_set<T> aux;
    std::vector<T> result;

    for (const T& value : successors) {
        aux.insert(value);
    }
    for (const T& value : predecessors) {
        aux.insert(value);
    }
    result.reserve(aux.size());
    for (const T& value : aux) {
        result.push_back(value);
    }
    
    return result;
}

template <typename T>
std::vector<std::vector<T> > DirectedGraph<T>::edges() {
    std::vector<std::vector<T> > result;
    result.reserve(this->edgeSize);

    VertexNode<T>* current = this->head;
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
