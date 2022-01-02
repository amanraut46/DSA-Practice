#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
void DFS(int u,int A[][8],int n){
    static int visited[8]{0};

    if(visited[u]==0){
        cout<<u<<","<<flush;
        visited[u]=1;

        for (int v = 1; v < n; v++)
        {
            /* code */
            if(A[u][v]==1 && visited[v]==0){
                DFS(v,A,n);
            }
        } 
    }
}
void BFS(int vtx,int A[][8],int n){
    queue<int> q;
    int visted[8] {0};

    cout<<vtx<<",";

    visted[vtx]=1;

    q.push(vtx);

    while (!q.empty())
    {
        /* code */
        int u=q.front();
        q.pop();

        for(int v=1;v<=n;v++){
            if(A[u][v]==1 && visted[v]==0){
                cout<<v<<",";
                visted[v]=1;
                q.push(v);
            }
        }
    }
    cout<<endl;
}
int main()
{
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
    cout<<"---------------BFS--------------------"<<endl;
    BFS(6,A,8);
    cout<<"---------------DFS--------------------"<<endl;
    DFS(6,A,8);
    return 0;
}