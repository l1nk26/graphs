#include <Graph.hpp>
#include <DirectedGraph.hpp>
#include <string>

Graph<std::string> emptyGraph;
DirectedGraph<std::string> emptyDirectedGraph;

Graph<std::string> graph;
DirectedGraph<std::string> directedGraph;

Graph<std::string> disconnectedGraph;
DirectedGraph<std::string> disconnectedDirectedGraph;

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
}
