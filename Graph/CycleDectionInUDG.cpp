#include <iostream>
#include <list>

using namespace std;

class Graph
{

public:
    int V;
    list<int> *llist;

    Graph(int V)
    {
        this->V = V;
        llist = new list<int>[V];
    }
    void addEdge(int u, int v)
    {

        llist[u].push_back(v);
        llist[v].push_back(u);
    }
    bool isCyclic()
    {

        bool visited[V]{false};

        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                if (iscyclicUtil(i, visited, -1))
                    return true;
            }
        }
        return false;
    }
    bool iscyclicUtil(int i, bool vist[], int parent)
    {

        vist[i] = true;

        list<int>::iterator j;

        for (j = llist[i].begin(); j != llist[i].end(); j++)
        {
            if (!vist[*j])
            {
                if (iscyclicUtil(*j, vist, i))
                    return true;
            }
            else if(*j!=parent)
                return true;
        }
        return false;
    }
};
int main()
{
    Graph g1(5);
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.isCyclic() ? cout << "Graph contains cycle\n" : cout << "Graph doesn't contain cycle\n";
}