#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
#define V 9
int minDistance(int dist[V],bool sptset[V]);
void printSolution(int arr[V]){

    for(int i=0;i<V;i++){
        cout<<i<<"\t\t"<<arr[i]<<endl;
    }
}
int minDistance(int dist[V],bool sptset[V]){

    int mxvalue=INT32_MAX;
    int index=-1;
    for(int i=0;i<V;i++){
        if(sptset[i]==false && dist[i]<mxvalue){
            mxvalue=dist[i];
            index=i;  
        }
    }
    return index;
}
void dijkstra(vector<vector<int>> graph,int src){

    int dist[V];

    bool sptset[V];

    for(int i=0;i<V;i++){
        sptset[i]=false;
        dist[i]=INT32_MAX;
    }

    dist[src]=0;

    for(int count=0;count<V-1;count++){

        int u=minDistance(dist,sptset);

        sptset[u]=true;

        for(int v=0;v<V;v++){

            if(!sptset[v] && graph[u][v] && dist[u]!=INT32_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
            }
        }
    }
    printSolution(dist);
}
int main()
{
    vector<vector<int>> graph = {
         { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } 
                    };
            
    dijkstra(graph,0);
    return 0;
}