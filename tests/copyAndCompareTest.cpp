#include "graphs.cpp"
#include <cassert>
   
int main() {

    initGraphs();

    Graph<std::string> graphCopy(graph); 
    assert(graph == graphCopy);

    return 0;
}
