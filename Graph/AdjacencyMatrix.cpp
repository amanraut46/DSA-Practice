#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
#define max 100
int main()
{
    int arr[max][max];
    int n;
    int max_edge,i,j,origin,destination;
    int graph_types;
    cout<<"Enter 1 for undirected graph and 2 directed graph"<<endl;
    cin>>graph_types;
    cout<<"Enter number of veritices"<<end;
    cin>>n;
    if(graph_types==1){
        max_edge=n*(n-1)/2;
    }
    else{
        max_edge=n*(n-1);
    }
    for (int i = 0; i < max_edge; i++)
    {
        cout<<"Enter Edge (-1 -1 to quit)"<<endl;
        cin>>origin>>destination;

        if(origin==-1 && destination==-1)
            break;
        if(origin>=n || destination>=n || origin<0 || destination<0){
            cout<<"Invalid Vertiex"<<endl;
            i--;
        }
        else{
            arr[origin][destination]=1;
            if(graph_types==1)
                arr[destination][origin]=1;
        }
    }
    cout<<"The adjacency matrix is:\n";
    for (int  i = 0; i <= n-1; i++)
    {
        /* code */
        for (int j = 0; j <= n-1; j++)
        {
            /* code */
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}