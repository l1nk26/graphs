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
    
    emptyDirectedGraph.addVertex("A");
    emptyDirectedGraph.addVertex("B");
    emptyDirectedGraph.addVertex("C");
    emptyDirectedGraph.addVertex("D");
 
    assert(emptyDirectedGraph.order() == 4);
    assert(emptyDirectedGraph.size() == 0);
    assert(emptyDirectedGraph.existVertex("A"));
    assert(emptyDirectedGraph.existVertex("B"));
    assert(emptyDirectedGraph.existVertex("C"));
    assert(emptyDirectedGraph.existVertex("D"));

    emptyDirectedGraph.addEdge("A", "B");
    emptyDirectedGraph.addEdge("A", "C");
    emptyDirectedGraph.addEdge("C", "B");
    emptyDirectedGraph.addEdge("D", "A");

    assert(emptyDirectedGraph.order() == 4);
    assert(emptyDirectedGraph.size() == 4);
    assert(emptyDirectedGraph.existEdge("A", "B"));
    assert(emptyDirectedGraph.existEdge("A", "C"));
    assert(emptyDirectedGraph.existEdge("C", "B"));
    assert(emptyDirectedGraph.existEdge("D", "A"));

    emptyDirectedGraph.removeEdge("A", "B");
    assert(!emptyDirectedGraph.existEdge("A", "B"));
    assert(emptyDirectedGraph.size() == 3);

    std::cout << emptyDirectedGraph << std::endl;
    emptyDirectedGraph.removeVertex("A");
    std::cout << emptyDirectedGraph << std::endl;
    emptyDirectedGraph.removeVertex("B");
    std::cout << emptyDirectedGraph << std::endl;
    emptyDirectedGraph.removeVertex("C");
    emptyDirectedGraph.removeVertex("D");
    std::cout << emptyDirectedGraph << std::endl;

    assert(emptyDirectedGraph.order() == 0);
    assert(emptyDirectedGraph.size() == 0);
    return 0;
}
