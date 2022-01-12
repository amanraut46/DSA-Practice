#include<iostream>
#include<vector>
using namespace std;
void DFS(vector<vector<int>> &M, int i, int j, int ROW,
         int COL)
{
    //Base condition
    //if i less than 0 or j less than 0 or i greater than ROW-1 or j greater than COL-  or if M[i][j] != 1 then we will simply return
    if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1)
    {
        return;
    }

    if (M[i][j] == 1)
    {
        M[i][j] = 0;
        DFS(M, i + 1, j, ROW, COL);     //right side traversal
        DFS(M, i - 1, j, ROW, COL);     //left side traversal
        DFS(M, i, j + 1, ROW, COL);     //upward side traversal
        DFS(M, i, j - 1, ROW, COL);     //downward side traversal
        DFS(M, i + 1, j + 1, ROW, COL); //upward-right side traversal
        DFS(M, i - 1, j - 1, ROW, COL); //downward-left side traversal
        DFS(M, i + 1, j - 1, ROW, COL); //downward-right side traversal
        DFS(M, i - 1, j + 1, ROW, COL); //upward-left side traversal
    }
}
 void dfs(vector<vector<int>>& grid , int i , int j , int n , int m)
   {
       if(i>=0 and j>=0 and i<n and j<m and grid[i][j]==1 )
       {
           grid[i][j]=0;
           dfs(grid , i-1 , j , n , m);
           dfs(grid , i , j-1 , n , m);
           dfs(grid , i+1 , j , n , m);
           dfs(grid , i , j+1 , n , m);
           
           dfs(grid , i+1 , j+1 , n , m);
           dfs(grid , i-1 , j+1 , n , m);
           dfs(grid , i+1 , j-1 , n , m);
           dfs(grid , i-1 , j-1 , n , m);
           
       }
   }
int countIslands(vector<vector<int>>& M){

    int c=0;
    int ROW=M.size();
    int COL=M[0].size();

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if(M[i][j]==1){
                c++;
                dfs(M,i,j,ROW,COL);
                //dfs(M, i + 1, j, ROW, COL);     //right side traversal
                //dfs(M, i - 1, j, ROW, COL);     //left side traversal
                //dfs(M, i, j + 1, ROW, COL);     //upward side traversal
                //dfs(M, i, j - 1, ROW, COL);     //downward side traversal
                //dfs(M, i + 1, j + 1, ROW, COL); //upward-right side traversal
                //dfs(M, i - 1, j - 1, ROW, COL); //downward-left side traversal
                //dfs(M, i + 1, j - 1, ROW, COL); //downward-right side traversal
                //dfs(M, i - 1, j + 1, ROW, COL); //upward-left side traversal
            }
        }
        
    }
    return c;
    
}
int main(){

    vector<vector<int>> m{
        {1,1,0,0,0},
        {0,1,0,0,1},
        {1,0,0,1,1},
        {0,0,0,0,0},
        {1,0,1,0,1}
    };

    cout<<countIslands(m);
    return 0;
}