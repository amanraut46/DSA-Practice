#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

void changeOnesConnectedToBorder(vector<vector<int>> &matrix,int row,int col);
vector<vector<int>> getNeigbhors(vector<vector<int>> matrix,int i,int j);
vector<vector<int>> removeIslands(vector<vector<int>> matrix) {
  // Write your code here.
  for (size_t i = 0; i < matrix.size(); i++)
  {
      for (size_t j = 0; j < matrix[i].size(); j++)
      {
          bool rowvalid = i==0 || i==matrix[0].size()-1;
          bool colvalid = j==0 || j==matrix[i].size()-1;
          bool isborder=rowvalid || colvalid;

          if(!isborder)
            continue;
          if(matrix[i][j]!=1)
            continue;

        changeOnesConnectedToBorder(matrix,i,j);
      }  
  }
  for (size_t i = 0; i < matrix.size(); i++)
  {
      for (size_t j = 0; j < matrix[i].size(); j++)
      {
          int color=matrix[i][j];

          if(color==1)
            matrix[i][j]=0;
          else if(color==2)
            matrix[i][j]=1;
      }
      
  }
  
  return matrix;
}
void changeOnesConnectedToBorder(vector<vector<int>> &matrix,int row,int col){
    stack<vector<int>> st;
    st.push({row,col});

    while (!st.empty())
    {
        vector<int> vt=st.top();
        st.pop();

        int currRow=vt[0];
        int currCol=vt[1];

        matrix[currRow][currCol]=2;
        vector<vector<int>> neighbors=getNeigbhors(matrix,currRow,currCol);

        for (auto neigbor:neighbors)
        {
            int row=neigbor[0];
            int col=neigbor[1];

            if(matrix[row][col]!=1)
                continue;
            
            st.push(neigbor);
        }    
    } 
}
vector<vector<int>> getNeigbhors(vector<vector<int>> matrix,int i,int j){
        int row=matrix.size();
        int col=matrix[row].size();
        vector<vector<int>> vt;
        if(i-1>=0)
            vt.push_back({i-1,j});
        if(i+1 < row)
            vt.push_back({i+1,j});
        
        if(j-1>=0)
            vt.push_back({i,j-1});
        if(j+1<col)
            vt.push_back({i,j+1});

        return vt;
}
int main(){

    vector<vector<int>> vt{
        {1,0,0,0,0,0},
        {0,1,0,1,1,1},
        {0,0,1,0,1,0},
        {1,1,0,0,1,0},
        {1,0,1,1,0,0},
        {1,0,0,0,0,1}
    };

    vector<vector<int>> result=removeIslands(vt);

    for (auto i:result)
    {
        for (auto j:i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}