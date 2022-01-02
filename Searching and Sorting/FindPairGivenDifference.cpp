#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
bool findPair(int arr[], int size, int n){
    
    sort(arr,arr+size);
    int i=0;
    int j=1;
    while (i<size && j<size)
    {
        if(i!=j && (arr[j]-arr[i]==n || arr[i]-arr[j]==n)){
            return true;
        }
        else if(arr[j]-arr[i]<n){
            j++;
        }
        else{
            i++;
        }
    }
    return false;
    
}
int main()
{
    int L = 6, N = 78;
    int arr[]={5, 20, 3, 2, 5, 80};
    cout<<findPair(arr,L,N);
    return 0;
}