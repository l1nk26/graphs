#include "graphs.cpp"
#include <cassert>
   
int main() {

    initGraphs();

    emptyGraph.addVertex("A");
    emptyGraph.addVertex("B");
    emptyGraph.addVertex("C");
    emptyGraph.addVertex("D");
 
    assert(emptyGraph.order() == 4);
    assert(emptyGraph.size() == 0);
    assert(emptyGraph.existVertex("A"));
    assert(emptyGraph.existVertex("B"));
    assert(emptyGraph.existVertex("C"));
    assert(emptyGraph.existVertex("D"));

    emptyGraph.addEdge("A", "B");
    emptyGraph.addEdge("A", "C");
    emptyGraph.addEdge("C", "B");
    emptyGraph.addEdge("D", "A");

    assert(emptyGraph.order() == 4);
    assert(emptyGraph.size() == 4);
    assert(emptyGraph.existEdge("A", "B"));
    assert(emptyGraph.existEdge("A", "C"));
    assert(emptyGraph.existEdge("C", "B"));
    assert(emptyGraph.existEdge("D", "A"));
    assert(emptyGraph.existEdge("B", "A"));
    assert(emptyGraph.existEdge("C", "A"));
    assert(emptyGraph.existEdge("B", "C"));
    assert(emptyGraph.existEdge("A", "D"));

    emptyGraph.removeEdge("A", "B");
    assert(!emptyGraph.existEdge("A", "B"));
    assert(!emptyGraph.existEdge("B", "A"));
    assert(emptyGraph.size() == 3);

    emptyGraph.removeVertex("A");
    emptyGraph.removeVertex("B");
    emptyGraph.removeVertex("C");
    emptyGraph.removeVertex("D");

    assert(emptyGraph.order() == 0);
    assert(emptyGraph.size() == 0);

    return 0;
}
