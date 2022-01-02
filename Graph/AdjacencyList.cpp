#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include <list>
using namespace std;

class Graph
{
public:
    list<int> *adj;
    int n;
    Graph(int v)
    {
        adj = new list<int>[v];
        n = v;
    };
    void addEge(int u, int v, bool bi)
    {
        adj[u].push_back(v);
        if (bi)
        {
            adj[v].push_back(u);
        }
    };
    void print()
    {
        for (int i = 0; i < n; i++)
        {
            /* code */
            cout << i << "-->";
            for (auto j : adj[i])
            {
                cout << j << " ";
            }
            cout << endl;
        }
        cout << endl;
    };
};
int main()
{
    Graph g(4);
    g.addEge(0, 1, true);
    g.addEge(1, 2, true);
    g.addEge(2, 3, true);
    g.addEge(3, 0, true);
    g.addEge(3, 1, true);

    g.print();
    return 0;
}