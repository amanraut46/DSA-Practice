#include<iostream>
#include<vector>
using namespace std;

void solve(vector<vector<int>> &vt,int x,int y,int prevC,int newc);
void floodFill(vector<vector<int>> &vt,int x,int y,int newc){
    int prevC=vt[x][y];

    if(prevC==newc) return;

    solve(vt,x,y,prevC,newc);
}
void solve(vector<vector<int>> &vt,int x,int y,int prevC,int newc){

    int row=vt.size();
    int col=vt[0].size();
    if(x<0 || x>=row || y<0 || y>=col)
        return;
    
    if(vt[x][y]!=prevC)
        return;
    if(vt[x][y]==newc)
        return;

    vt[x][y]=newc;

    solve(vt,x+1,y,prevC,newc);
    solve(vt,x-1,y,prevC,newc);
    solve(vt,x,y+1,prevC,newc);
    solve(vt,x,y-1,prevC,newc);
}
int main(){

    vector<vector<int>> vt{{1, 1, 1, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 1, 1, 0, 0},
                      {1, 0, 0, 1, 1, 0, 1, 1},
                      {1, 2, 2, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 0, 1, 0},
                      {1, 1, 1, 2, 2, 2, 2, 0},
                      {1, 1, 1, 1, 1, 2, 1, 1},
                      {1, 1, 1, 1, 1, 2, 2, 1},
                     };
    
    int x=4;
    int y=4;
    int newC=3;

    floodFill(vt,x,y,newC);
    int M=vt.size();
    int N=vt[0].size();
    for (int i=0; i<M; i++)
    {
        for (int j=0; j<N; j++)
           cout << vt[i][j] << " ";
        cout << endl;
    }
}