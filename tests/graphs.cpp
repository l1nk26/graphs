#include <Graph.hpp>
#include <DirectedGraph.hpp>
#include <string>
#include <Edge.hpp>

Graph<std::string> emptyGraph;
DirectedGraph<std::string> emptyDirectedGraph;

Graph<std::string> graph;
DirectedGraph<std::string> directedGraph;

Graph<std::string> disconnectedGraph;
DirectedGraph<std::string> disconnectedDirectedGraph;

Graph<std::string> graphWithWeight;
DirectedGraph<std::string> directedGraphWithWeight;

void initGraphs() {

    graph.createFromMap(
        {"A", "B", "C", "D"},
        {
          {"A", {"B", "C"}},
          {"C", {"B"}},
          {"D", {"A", "B"}}
        }
    );
    directedGraph.createFromMap(
        {"A", "B", "C", "D"},
        {
          {"A", {"B", "C"}},
          {"C", {"B"}},
          {"D", {"A", "B"}}
        }
    );
    disconnectedGraph.createFromMap(
        {"A", "B", "C", "D"},
        {
          {"A", {"B", "C"}},
          {"C", {"D"}}
        }
    );
    disconnectedDirectedGraph.createFromMap(
        {"A", "B", "C", "D"},
        {
          {"A", {"B", "C"}},
          {"C", {"B"}}
        }
    );

    graphWithWeight.createFromMapEdges(
        {"A", "B", "C", "D"},
        {
            {"A", {Edge<std::string>("B", 1), Edge<std::string>("C", 2)} },
            {"C", {Edge<std::string>("B", 3)} },
            {"D", {Edge<std::string>("A", 4), Edge<std::string>("B", 5)} }
        }
    );

    directedGraphWithWeight.createFromMapEdges(
        {"A", "B", "C", "D"},
        {
            {"A", {Edge<std::string>("B", 1), Edge<std::string>("C", 2)} },
            {"C", {Edge<std::string>("B", 3)} },
            {"D", {Edge<std::string>("A", 4), Edge<std::string>("B", 5)} }
        }
    );
}
