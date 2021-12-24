#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
void Inserationsort(vector<int> &,int);
int main()
{
    vector<int> vt={82, 42, 49, 8, 25, 52, 36, 93, 59};
    Inserationsort(vt,vt.size());
    for(auto it: vt){
        cout<<it<<" ";
    }
    return 0;
}
void Inserationsort(vector<int> &vt,int n){
    int i,j ,k;
    for (i = 1; i < n; i++)
    {
        /* code */
        k=vt[i];
        cout<<"vt["<<i<<"]"<<vt[i]<<endl;
        for (j = i-1; j >=0 && k<vt[j]; j--)
        {
            /* code */
            
            vt[j+1]=vt[j];
        }
        vt[j+1]=k;
    }
    
}