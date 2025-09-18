#include <EdgeNode.hpp>

template <typename T>
EdgeNode<T>::EdgeNode() {
    vertex = NULL;
    next = NULL;
}

template <typename T>
EdgeNode<T>::EdgeNode(VertexNode<T>* vertex, float wheight, EdgeNode<T>* next) {
    this->vertex = vertex;
    this->wheight = wheight;
    this->next = next;
}

template <typename T>
EdgeNode<T>::EdgeNode(VertexNode<T>* vertex, EdgeNode<T>* next, float wheight) {
    this->vertex = vertex;
    this->next = next;
    this->wheight = wheight;
}

template <typename T>
VertexNode<T>* EdgeNode<T>::getVertex() { 
    return vertex;
}

template <typename T>
float EdgeNode<T>::getWheight() {
    return wheight;
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
void EdgeNode<T>::setWheight(float wheight) {
    this->wheight = wheight;
}

template <typename T>
void EdgeNode<T>::setNext(EdgeNode<T>* next) {
    this->next = next;
}
