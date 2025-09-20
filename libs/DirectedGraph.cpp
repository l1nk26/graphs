#include <DirectedGraph.hpp>

template <typename T>
DirectedGraph<T>::DirectedGraph() : Graph<T>() {
    this->name = "DirectedGraph";
}

template <typename T>
DirectedGraph<T>::DirectedGraph(const DirectedGraph& other) 
:
    Graph<T>(other)
{}

template <typename T>
void DirectedGraph<T>::connectVertices(VertexNode<T>* node1, VertexNode<T>* node2, float weight) {
    node1->addNeightbor(node2, weight); 
}

template <typename T>
void DirectedGraph<T>::unconnectVertices(VertexNode<T>* node1, VertexNode<T>* node2) {
    node1->removeNeightbor(node2); 
}

template <typename T>
DirectedGraph<T>::~DirectedGraph() {}
