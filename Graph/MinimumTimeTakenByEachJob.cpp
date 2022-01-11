#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define maxN 10000

vector<int> graph[maxN];
vector<int> indegree(maxN,0);
vector<int> job(maxN,0);

void addEdge(int u, int v)
{

    graph[u].push_back(v);

    indegree[v]=indegree[v]+1;
}
void printTimeTaken(int n, int m)
{

    queue<int> q;

    for (int i = 1; i <= m; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            job[i] = 1;
        }
    }

    while (!q.empty())
    {
        int f = q.front();
        q.pop();

        for (auto i :graph[f])
        {
            indegree[i]--;
            if (indegree[i] == 0)
            {
                q.push(i);
                job[i] =job[f]+ 1;
            }
        }
    }
    for(int i=1;i<=n;i++){
        cout<<job[i]<<" "; 
    }
}
int main(){
    // Given Nodes N and edges M
    int n, m;
    n = 10;
    m = 13;
 
    // Given Directed Edges of graph
    addEdge(1, 3);
    addEdge(1, 4);
    addEdge(1, 5);
    addEdge(2, 3);
    addEdge(2, 8);
    addEdge(2, 9);
    addEdge(3, 6);
    addEdge(4, 6);
    addEdge(4, 8);
    addEdge(5, 8);
    addEdge(6, 7);
    addEdge(7, 8);
    addEdge(8, 10);
 
    // Function Call
    printTimeTaken(n, m);
    return 0;
}
