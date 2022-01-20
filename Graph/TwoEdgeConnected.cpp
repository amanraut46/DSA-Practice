#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Graph
{
public:
    int V;
    vector<int> *adj;
    Graph(int V)
    {
        this->V = V;
        this->adj = new vector<int>[V];
    }
    void addEdge(int u, int v)
    {
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }
    void twoEdge(int v)
    {
        int noOfEdges[v];

        for (size_t i = 0; i < v; i++)
        {
            noOfEdges[i] = adj[i].size();
        }
        bool flag = true;

        for (size_t i = 0; i < v; i++)
        {
            if (noOfEdges[i] < 2)
            {
                flag = false;
                break;
            }
        }
        if (flag)
            cout << "yes";
        else
            cout << "No";
    }
};

int main()
{
    int V = 8;
    int E = 10;

    int edges[E][2] = {{1, 2}, {1, 8}, {1, 6}, {2, 3}, {2, 4}, {3, 7}, {3, 4}, {7, 5}, {7, 6}, {7, 8}};
    Graph g(V);
    for (int i = 0; i < E; i++)
    {
        g.addEdge(edges[i][0], edges[i][1]);
    }
    g.twoEdge(V);
 
    return 0;
}