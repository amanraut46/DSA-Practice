#include <iostream>
#include <list>
#include <vector>
using namespace std;

class Graph
{

public:
    int V;
    vector<int> *llist;

    Graph(int V)
    {
        this->V = V;
        llist = new vector<int>[V];
    }
    void addEdge(int u, int v)
    {
        llist[u].push_back(v);
    }
    bool isCyclic(int V, vector<int> adj[])
    {
        // code here
        vector<int> vis(V, 0);
        vector<int> order(V, 0);

        for (int i = 0; i < V; i++)
        {

            if (!vis[i])
            {
                bool c = solve(vis, order, adj, i);
                if (c == true)
                    return true;
            }
        }
        return false;
    }
    bool solve(vector<int> &vis, vector<int> &order, vector<int> nums[], int i)
    {
        vis[i] = 1;
        order[i] = 1;

        for (auto x : nums[i])
        {
            if (!vis[x])
            {
                bool conf = solve(vis, order, nums, x);
                if (conf == true)
                    return true;
            }
            else if (order[x])
                return true;
        }
        order[i] = 0;
        return false;
    }
};
int main()
{
    int v = 5;
    Graph g1(v);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic(v, g1) ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";
}