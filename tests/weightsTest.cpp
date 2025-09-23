#include "graphs.cpp"
#include <cassert>
   
int main() {

    initGraphs();

    assert(graphWithWeight.edgeWeight("A", "B") == 1);
    assert(graphWithWeight.edgeWeight("A", "C") == 2);
    assert(graphWithWeight.edgeWeight("C", "B") == 3);
    assert(graphWithWeight.edgeWeight("D", "A") == 4);
    assert(graphWithWeight.edgeWeight("D", "B") == 5);

    assert(directedGraphWithWeight.edgeWeight("A", "B") == 1);
    assert(directedGraphWithWeight.edgeWeight("A", "C") == 2);
    assert(directedGraphWithWeight.edgeWeight("C", "B") == 3);
    assert(directedGraphWithWeight.edgeWeight("D", "A") == 4);
    assert(directedGraphWithWeight.edgeWeight("D", "B") == 5);

    return 0;
}
