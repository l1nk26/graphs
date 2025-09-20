#include "graphs.cpp"
#include <cassert>
   
int main() {

    initGraphs();

    assert(emptyGraph.size() == 0);
    assert(emptyGraph.order() == 0);
    
    assert(emptyDirectedGraph.size() == 0);
    assert(emptyDirectedGraph.order() == 0);

    assert(graph.size() == 5);
    assert(graph.order() == 4);

    assert(directedGraph.size() == 5);
    assert(directedGraph.order() == 4);

    assert(disconnectedGraph.size() == 3);
    assert(disconnectedGraph.order() == 4);

    assert(disconnectedDirectedGraph.size() == 3);
    assert(disconnectedDirectedGraph.order() == 4);

    graph.clear();
    assert(graph.size() == 0);
    assert(graph.order() == 0);

    directedGraph.clear();
    assert(directedGraph.size() == 0);
    assert(directedGraph.order() == 0);

    disconnectedGraph.clear();
    assert(disconnectedGraph.size() == 0);
    assert(disconnectedGraph.order() == 0);

    disconnectedDirectedGraph.clear();
    assert(disconnectedDirectedGraph.size() == 0);
    assert(disconnectedDirectedGraph.order() == 0);

    return 0;
}
