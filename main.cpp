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
    unordered_map<string, unordered_set<string> > edges; 
    unordered_map<string, unordered_set<Edge<string> > > edges2;

    unordered_set<string> vertex;

    string vertex1, vertex2, aux;

    while (cin >> vertex1 >> vertex2) {
        vertex.insert(vertex1);
        vertex.insert(vertex2);

        // only if it is not directed
        if (vertex1 > vertex2) {
            aux = vertex1;
            vertex1 = vertex2;
            vertex2 = vertex1;
        }
        Edge<string> edge(vertex2, 1.5F);
        edges2[vertex1].insert(edge);
    }
    
    Graph<string> graph;
    graph.createFromMapEdges(vertex, edges2);
    return graph;
}

DirectedGraph<string> readDirectedGraph() {
    unordered_map<string, unordered_set<Edge<string> > > edges; 
    unordered_set<string> vertex;
    float weight = 0;
    string parent, child;

    while (cin >> parent >> child >> weight) {
        vertex.insert(parent);
        vertex.insert(child);
        Edge<string> edge(child, weight);
        edges[parent].insert(edge);
    }
    
    DirectedGraph<string> directedGraph;
    directedGraph.createFromMapEdges(vertex, edges);
    
    return directedGraph;
}

int main() {

    //Graph<string> graph = readGraph();
    //cout << graph << endl;

    DirectedGraph<string> directedGraph = readDirectedGraph();
    cout << directedGraph << endl;

    vector<string> dijkstraPath = directedGraph.dijkstra("Brazil", "Chile");
    cout << dijkstraPath << endl;
    return 0;
}
