#include<iostream>
#include<stack>
#include<vector>
using namespace std;
//2
//4
//2 1 4 3
//3
//1 3 2
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    //2 1 4 3
    //1 -1 3 -1
    vector<int> vt;
    int i,j;
    for (i = 0; i < n; i++)
    {
        for (j = i+1; j < n; j++)
        {
            if(arr[i]>arr[j]){
                arr[i]=arr[j];
                continue;
            }
        }
        
        if(arr[i]<arr[j]){
            arr[i]=-1;
        }
        continue;
    }
    return arr;
    
}
int main()
{
    int n=4;
    vector<int> arr{2,1,4,3};
    vector<int> vt=nextSmallerElement(arr,n);
    for(auto i:vt){
        cout<<i<<" ";
    }
    return 0;
}