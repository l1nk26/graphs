#include "graphs.cpp"
#include <cassert>
   
int main() {

    initGraphs();

 
    Graph<std::string> copyGraph(graph);
    assert(graph == copyGraph);

    Graph<std::string> copyEmptyGraph(emptyGraph);
    assert(emptyGraph == copyEmptyGraph);

    Graph<std::string> copyDisconnectedGraph(disconnectedGraph);
    assert(disconnectedGraph == copyDisconnectedGraph);

    DirectedGraph<std::string> copyDirectedGraph(directedGraph);
    assert(directedGraph == copyDirectedGraph);

    DirectedGraph<std::string> copyEmptyDirectedGraph(emptyDirectedGraph);
    assert(emptyDirectedGraph == copyEmptyDirectedGraph);

    DirectedGraph<std::string> copyDisconnectedDirectedGraph(disconnectedDirectedGraph);
    assert(disconnectedDirectedGraph == copyDisconnectedDirectedGraph);


    return 0;
}
