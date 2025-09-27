#include "graphs.cpp"
#include <cassert>
#include <unordered_set>
#include <vector>
#include <containersOverload.hpp>

std::unordered_set<std::string> toSet(const std::vector<std::string>& v) {
    std::unordered_set<std::string> u;
    for (const std::string& value : v) {
       u.insert(value); 
    }
    return u;
}

int main() {

    initGraphs();
    assert(toSet(graph.neightbors("A")) == toSet({"B", "C", "D"}));
    assert(toSet(graph.neightbors("C")) == toSet({"B", "A"}));
    assert(toSet(graph.neightbors("D")) == toSet({"B", "A"}));
    assert(toSet(graph.neightbors("B")) == toSet({"A", "C", "D"}));

    assert(toSet(directedGraph.successors("A")) == toSet({"B", "C"}));
    assert(toSet(directedGraph.successors("D")) == toSet({"A", "B"}));
    assert(toSet(directedGraph.successors("C")) == toSet({"B"}));

    assert(toSet(directedGraph.predecessors("A")) == toSet({"D"}));
    assert(toSet(directedGraph.predecessors("B")) == toSet({"A", "C", "D"}));
    assert(toSet(directedGraph.predecessors("C")) == toSet({"A"}));

    return 0;
}
