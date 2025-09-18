#include <iostream>
#include <Graph.hpp>
#include <DirectedGraph.hpp>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <Edge.hpp>
#include <containersOverload.hpp>

using namespace std;

Graph<string> readGraph() {
    unordered_map<string, std::unordered_set<string> > edges; 
    unordered_map<string, std::unordered_set<Edge<string> > > edges2;

    unordered_set<string> vertex;

    string parent, child;

    while (cin >> parent >> child) {
        vertex.insert(parent);
        vertex.insert(child);
        Edge<string> edge(child, 1.5F);
        edges2[parent].insert(edge);
    }
    
    Graph<string> graph;
    graph.createFromMapEdges(vertex, edges2);
    return graph;
}

DirectedGraph<string> readDirectedGraph() {
    unordered_map<string, std::unordered_set<string> > edges; 
    unordered_set<string> vertex;
    string parent, child;

    while (cin >> parent >> child) {
        vertex.insert(parent);
        vertex.insert(child);
        edges[parent].insert(child);
    }
    
    DirectedGraph<string> directedGraph;
    directedGraph.createFromMap(vertex, edges);
    
    return directedGraph;
}

int main() {

    //Graph<string> graph = readGraph();
    //cout << graph << endl;

    DirectedGraph<string> directedGraph = readDirectedGraph();
    cout << directedGraph << endl;

    vector<vector<string> > v = directedGraph.edges();
    cout << v << endl;

    return 0;
}
