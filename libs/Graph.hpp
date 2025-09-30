#pragma once

#include <VertexNode.hpp>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
#include <Edge.hpp>

template <typename T>
class Graph {
    public:
        Graph();
        Graph(const Graph<T>& other);
        ~Graph();

        void createFromMap(const std::unordered_set<T>& vertex, const std::unordered_map<T, std::unordered_set<T> >& edges);
        void createFromMapEdges(const std::unordered_set<T>& vertex, const std::unordered_map<T, std::unordered_set<Edge<T> > >& edges);

        int order();
        int size();
        bool empty();
        void clear();

        void addVertex(const T& vertex);
        void addEdge(const T& from, const T& to, float weight = 0.0F);

        void removeVertex(const T& vertex);
        void removeEdge(const T& from, const T& to);

        bool existVertex(const T& vertex);
        bool existEdge(const T& from, const T& to);

        std::vector<T> vertices();
        virtual std::vector<std::vector<T> > edges();

        float edgeWeight(const T& vertex1, const T& vertex2);

        virtual std::vector<T> neightbors(const T& vertex);
        std::vector<T> successors(const T& vertex);
        std::vector<T> predecessors(const T& vertex);

        std::vector<T> bfs(const T& inicial);
        std::vector<T> bfs(const T& inicial, std::unordered_set<T>& visited);
        std::vector<T> dfs(const T& inicial);
        std::vector<T> dfs(const T& inicial, std::unordered_set<T>& visited);

        std::vector<T> shortestPath(const T& start, const T& end);
        std::vector<T> dijkstra(const T& start, const T& end);

        Graph<T>& operator=(const Graph<T>& other);
        bool operator==(Graph<T>& other);

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, Graph<U>& graph); 

    protected:
        VertexNode<T>* head;
        std::string name;
        int vertexSize, edgeSize;

        VertexNode<T>* findVertex(const T& vertex);
        void findTwoVertices(const T& from, const T& to, VertexNode<T>*& fromNode, VertexNode<T>*& toNode);

        virtual void connectVertices(VertexNode<T>* fromNode, VertexNode<T>* toNode, float weight = 0.0F);
        virtual void unconnectVertices(VertexNode<T>* fromNode, VertexNode<T>* toNodeF);

        void copy(const Graph<T>& from, Graph<T>& to);

        bool existEdge(VertexNode<T>* from, VertexNode<T>* to);

        virtual void discountEdges(int numberOfEdge);

        void dfs(VertexNode<T>* ptr, std::unordered_set<T>& visited, std::vector<T>& result);
};

#include <Graph.cpp>
