#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{
    // code here
    int maxone=0;
    int row=-1;
    for (int i = 0; i < n; i++)
    {
        /* code */
        int coint=0;
        for (int j = 0; j < m; j++)
        {
            /* code */
            if(arr[i][j]==1)
                coint++;
            
        }
        if(coint>maxone){
            maxone=coint;
            row=i;
        }
        
    }
    return row;
    
}
int main()
{
    int N = 4 , M = 4;
    vector<vector<int>> vt = {{0, 1, 1, 1},
           {0, 0, 1, 1},
           {1, 1, 1, 1},
           {0, 0, 0, 0}};
    

    cout<<rowWithMax1s(vt,N,M);
    return 0;
}