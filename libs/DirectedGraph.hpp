#pragma once

#include <Graph.hpp>
#include <unordered_set>
#include <unordered_map>
#include <Edge.hpp>

template <typename T>
class DirectedGraph : public Graph<T> {
    public:

        DirectedGraph();
        DirectedGraph(const DirectedGraph& graph);
        ~DirectedGraph();

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, Graph<U>& graph); 
    protected:

        void connectVertices(VertexNode<T>* node1, VertexNode<T>* node2, float weight = 0.0F) override;
        void unconnectVertices(VertexNode<T>* node1, VertexNode<T>* node2) override;
        void discountEdges(int numberOfEdge) override;
};

#include <DirectedGraph.cpp>
