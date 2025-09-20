#pragma once

#include <VertexNode.hpp>
#include <cstddef>

template <typename T>
class VertexNode;

template <typename T>
class EdgeNode {
    public:
        EdgeNode();
        EdgeNode(VertexNode<T>* vertex, float weight = 0, EdgeNode<T>* next = NULL);
        EdgeNode(VertexNode<T>* vertex, EdgeNode<T>* next = NULL, float weight = 0);

        VertexNode<T>* getVertex();
        float getWeight();
        EdgeNode<T>* getNext();

        void setVertex(VertexNode<T>* vertex);
        void setWeight(float weight);
        void setNext(EdgeNode<T>* next);

    private:
        float weight;
        VertexNode<T>* vertex;
        EdgeNode<T>* next;
};

#include <EdgeNode.cpp>
