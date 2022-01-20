#include<iostream>
#include "Graph.h"

using namespace std;

int main(){

    Graph g(5);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);

    g.DFS(1);
    return 0;
}