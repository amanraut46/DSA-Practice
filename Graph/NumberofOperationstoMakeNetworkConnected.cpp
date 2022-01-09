#include<iostream>
#include<vector>
using namespace std;

void dfs(int src,vector<int> g[],vector<int> &vis){

    vis[src]=1;
    for (auto it:g[src])
    {
        if(![vis[x]]){
            dfs(it,g,vis);
        }
    }
    
}
int makeConnected(int n, vector<vector<int>>& connections) {
    vector<int> g[n];

    int m=connections.size();

    if(m<n) return -1;
    
    for (size_t i = 0; i < connections.size() ; i++)
    {
        g[connections[i][0]].push_back(connections[i][1]);
        g[connections[i][1]].push_back(connections[i][0]);
    }
    vector<int> vis(n,0);

    int c=0;

    for (size_t i = 0; i < n; i++)
    {
        if(!vis[i]){
            c++;
            dfs(i,g,vis);
        }
    }
    return c-1;
}