#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;

class Graph
{
public:
    vector<int> *adj;
    int n;
    Graph(int v)
    {
        adj = new vector<int>[v];
        n = v;
    };
    void addEge(int u, int v)
    {
        adj[u].push_back(v);
        
    };
    void Topological(){
    
        stack<int> st;
        vector<int> vt(n,0);

        for (int i = 0; i < n; i++)
        {
            if(!vt[i]){
                dfsUtil(i,vt,st);
            }  
        }
        while (!st.empty())
        {
            cout<<st.top()<<" ";
            st.pop();
        }
        
    }
    void dfsUtil(int u,vector<int> &vt,stack<int> &st){

        vt[u]=1;
        for(auto i:adj[u]){
            if(!vt[i]){
                dfsUtil(i,vt,st);
            }
        }

        st.push(u);
        
    }
    
};
int main()
{
    Graph g(6);
    g.addEge(5, 2);
    g.addEge(5, 0);
    g.addEge(4, 0);
    g.addEge(4, 1);
    g.addEge(2, 3);
    g.addEge(3, 1);
    g.Topological();

    
    return 0;
}