#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
int median(vector<vector<int>> &matrix, int r, int c)
{
    // code here
    vector<int> vt;
    int rstart=0;
    int cstart=0;
    while(cstart<c){
        
        int row=0;
        while (row<r)
        {
            /* code */
            vt.push_back(matrix[row][cstart]);
            row++;
        }
        cstart++;
        
    }
    sort(vt.begin(),vt.end());
    //cout<<vt.size()<<endl;
    int mid=(vt.size()/2);
    //cout<<mid<<endl;
    return vt[mid];

}
int main()
{
    int R = 3; int C = 3;
    vector<vector<int>> vt{
        {1, 3, 5},
        {2, 6, 9},
        {3, 6, 9}};
       int i=median(vt,R,C);
       cout<<i<<endl;
    return 0;
}