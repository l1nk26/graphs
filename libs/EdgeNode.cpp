#include <EdgeNode.hpp>

template <typename T>
EdgeNode<T>::EdgeNode() {
    vertex = NULL;
    next = NULL;
}

template <typename T>
EdgeNode<T>::EdgeNode(VertexNode<T>* vertex, float weight, EdgeNode<T>* next) {
    this->vertex = vertex;
    this->weight = weight;
    this->next = next;
}

template <typename T>
EdgeNode<T>::EdgeNode(VertexNode<T>* vertex, EdgeNode<T>* next, float weight) {
    this->vertex = vertex;
    this->next = next;
    this->weight = weight;
}

template <typename T>
VertexNode<T>* EdgeNode<T>::getVertex() { 
    return vertex;
}

template <typename T>
float EdgeNode<T>::getWeight() {
    return weight;
}

template <typename T>
EdgeNode<T>* EdgeNode<T>::getNext() {
    return next;
}

template <typename T>
void EdgeNode<T>::setVertex(VertexNode<T>* vertex) {
    this->vertex = vertex;
}

template <typename T>
void EdgeNode<T>::setWeight(float weight) {
    this->weight = weight;
}

template <typename T>
void EdgeNode<T>::setNext(EdgeNode<T>* next) {
    this->next = next;
}
