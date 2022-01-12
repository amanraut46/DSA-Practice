#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
#define V 5
void printMST(int parent[],int graph[V][V]){

    cout<<"Edge \tWeight\n";
    int sum=0;
    for (size_t i = 1; i < V; i++)
    {
        cout<<parent[i]<<"-"<<i<<"\t"<<graph[i][parent[i]]<<" \n";
        sum+=graph[i][parent[i]];
    }
    cout<<sum<<endl;
}
int minkey(int key[V],bool mstset[V]){

    int minvalue=INT32_MAX;
    int min_index;

    for (size_t v = 0; v < V; v++)
    {
        if(mstset[v]==false && key[v]<minvalue){
            minvalue=key[v];
            min_index=v;
        }
    }
    return min_index; 
}
void primMST(int graph[V][V]){

    int parent[V];
    int key[V];

    bool mstset[V];

    for (size_t i = 0; i < V; i++)
    {
        key[i]=INT32_MAX;
        mstset[i]=false;
    }
    key[0]=0;
    parent[0]=-1;

    for (size_t i = 0; i < V-1; i++)
    {
        int u=minkey(key,mstset);
        mstset[u]=true;

        for (size_t v = 0; v < V; v++)
        {
            if(graph[u][v] && mstset[v]==false && graph[u][v]<key[v]){
                parent[v]=u;
                key[v]=graph[u][v];
            }
        }
        
    }
    
    printMST(parent,graph);

}
int main(){

    /* Let us create the following graph 
        2 3 
    (0)--(1)--(2) 
    | / \ | 
    6| 8/ \5 |7 
    | / \ | 
    (3)-------(4) 
            9     */
    int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } }; 

    // Print the solution 
    primMST(graph); 
    return 0;
}