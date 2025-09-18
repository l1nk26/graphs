#pragma once

#include <list>
#include <EdgeNode.hpp>
#include <vector>
#include <cstddef>

template <typename T>
class EdgeNode;

template <typename T>
class VertexNode {
    public:

        VertexNode();
        VertexNode(const T& value, VertexNode<T>* next = NULL);
        VertexNode(const T& value, std::list<VertexNode<T>*> neighbors, VertexNode<T>* next = NULL);
        VertexNode(const T& value, std::vector<VertexNode<T>*> neighbors, VertexNode<T>* next = NULL);
        ~VertexNode();

        T& getValue();
        int getID();
        std::vector<VertexNode<T>*> getNeighbors();
        std::vector<T> getNeighborValues();
        int getNeighborsSize();
        std::vector<EdgeNode<T>*> getEdges();
        std::vector<float> getWeights();
        VertexNode<T>* getNext(); 

        void setValue(const T& value);
        void setNeighbors(std::list<VertexNode<T>*> neighbors);
        void setNeighbors(std::list<VertexNode<T>*> neighbors, std::list<float> wheights);
        void setNeighbors(std::vector<VertexNode<T>*> neighbors);
        void setNeighbors(std::vector<VertexNode<T>*> neighbors, std::vector<float> wheights);
        void setNext(VertexNode<T>* next);

        void addNeightbor(VertexNode<T>* newNeighbor, float wheight = 0.0F);
        void removeNeightbor(VertexNode<T>* neighborToRemove);
        void cleanNeighbors();

        float getWheightForVertex(VertexNode<T>* vertex);
        float getWheightForValue(const T& value);

        void setWheightForVertex(VertexNode<T>* vertex, float wheight);
        bool existNeighbor(const T& value);

    private:
        T value;
        EdgeNode<T>* neighbors;
        int neighborsSize;
        VertexNode<T>* next;
        int ID;
};

namespace vertexNodeInternals {
  static int id = 0;
}

#include <VertexNode.cpp>
