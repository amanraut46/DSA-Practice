#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;

//Time complexity O(n^2)
//Space complexity o(1)
void sortBySelectionSort(vector<int> &vt,int n){

    for (int i = 0; i < n; i++)
    {
        /* code */
        int min=i;

        for (int j = i; j < n; j++)
        {
            /* code */
            if(vt[min]>vt[j]){
                min=j;
            }
        }

        if(i!=min){
            int temp=vt[i];
            vt[i]=vt[min];
            vt[min]=temp;
        }    
    }
}
int main()
{
    vector<int> vt={82,42,49,8,25,52,36,93,59};
    int n=vt.size();
    sortBySelectionSort(vt,n);
    
    for(auto i:vt){
        cout<<i<<" ";
    }
    return 0;
}