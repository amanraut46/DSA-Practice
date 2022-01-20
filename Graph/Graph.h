#include<iostream>
#include<vector>
using namespace std;

class Graph{

    int V;
    vector<int> *vt;
    public:
        Graph(int V){
            this->V=V;
            this->vt=new vector<int>[V];
        }
        void DFS(int u){

            static vector<bool> visited(V,false);

            if(visited[u]==false){
                visited[u]=true;
                cout<<u<<" ";

                for (auto v: vt[u])
                {
                    DFS(v);
                }
                
            }
            
        }
        void addEdge(int u ,int v){

            vt[u].push_back(v);
        }
};