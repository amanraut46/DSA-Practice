#include <iostream>
#include <list>
#include<queue>
using namespace std;

class Graph
{
public:
    int V;
    list<int> *adj;
    int* vist;
    Graph(int V){
        this->V=V;
        this->adj=new list<int>[V];
        vist=new int[V]{0};
    }
    void addEdge(int u ,int v){
        adj[u].push_back(v);
    }
    void DFS(int u){
        
        
        vist[u]=1;
        cout<<u<<" ";

        list<int>:: iterator i;

        for ( i = adj[u].begin(); i !=adj[u].end(); i++)
        {
            if (vist[*i]==0)
            {
               DFS(*i); 
            }
            
        }
        
    }
    void BFS(int s){
        bool *visted=new bool[V];

        for (int i = 0; i < V; i++)
        {
            visted[i]=false;
        }
        list<int> q;
        q.push_back(s);
        visted[s]=true;

        list<int> :: iterator i;
        while (!q.empty())
        {
            s=q.front();
            cout<<s<<" ";
            q.pop_front();

            for ( i = adj[s].begin(); i !=adj[s].end(); i++)
            {
                if(!visted[*i]){
                    visted[*i]=true;
                    q.push_back(*i);
                }
            }   
        }
        
    }
};
int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
 
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n";
    g.DFS(2);
 
    return 0;
}