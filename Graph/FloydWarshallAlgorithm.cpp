#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
#define V 4
#define INF 50
int main(){
    int graph[V][V] = { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    
    for (size_t k = 0; k < V; k++)
    {
        for (size_t i = 0; i < V; i++)
        {
            for (size_t j = 0; j < V; j++)
            {
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
            
        }
        
    }
    for (size_t i = 0; i < V; i++)
    {
        for (size_t j = 0; j < V; j++)
        {
            cout<<graph[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;

                        
}