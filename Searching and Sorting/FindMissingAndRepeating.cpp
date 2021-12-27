#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
int *findTwoElement(int *arr, int n)
{
    // code here
    int a,b;
    for(int i=0;i<n;i++){
        if(arr[abs(arr[i])-1]<0){
            a=abs(arr[i]);
        }
        else{
            arr[abs(arr[i])-1]=-arr[abs(arr[i])-1];
        }
    }
    for(int i=0;i<n;i++){
        if(arr[i]>0){
            b=i+1;
            break;
        }
    }
    int* vt=new int[2];
    vt[0]=a;
    vt[1]=b;
    return vt;
}
int main()
{
    int N = 2;
    int Arr[] = {2, 2};
    return 0;
}