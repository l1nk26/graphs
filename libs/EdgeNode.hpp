#pragma once

#include <VertexNode.hpp>
#include <cstddef>

template <typename T>
class VertexNode;

template <typename T>
class EdgeNode {
    public:
        EdgeNode();
        EdgeNode(VertexNode<T>* vertex, float wheight = 0, EdgeNode<T>* next = NULL);
        EdgeNode(VertexNode<T>* vertex, EdgeNode<T>* next = NULL, float wheight = 0);

        VertexNode<T>* getVertex();
        float getWheight();
        EdgeNode<T>* getNext();

        void setVertex(VertexNode<T>* vertex);
        void setWheight(float wheight);
        void setNext(EdgeNode<T>* next);

    private:
        float wheight;
        VertexNode<T>* vertex;
        EdgeNode<T>* next;
};

#include <EdgeNode.cpp>
