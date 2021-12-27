#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
#define MAX 100
void restoreDown(int arr[],int i,int size);
void BuildHeap(int arr[],int size);
void display(int arr[],int n);
int delete_root(int arr[],int *n);
void BuildHeap(int arr[],int size){
    int i;
    for (i=size/2;i>=1;i--){
        restoreDown(arr,i,size);
    }
}
void restoreDown(int arr[],int i,int size){
    int left=i+2;
    int right=left+1;
    int num=arr[i];
    while (right<=size)
    {
        /* code */
        if(num>=arr[left] && num>=arr[right]){
            arr[i]=num;
            return;
        }
        else if(arr[left]>arr[right]){
            arr[i]=arr[left];
            i=left;
        }
        else{
            arr[i]=arr[right];
            i=right;
        }
    left=2*i;
    right=left+1;
    }
    if (left==size && num<arr[left])
    {
        /* code */
        arr[i]=arr[left];
        i=left;
    }
    arr[i]=num;
}
void display(int arr[],int n){
    int i;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
void heap_sort(int arr[],int n){
    BuildHeap(arr,n);
    
    while (n>1)
    {
        /* code */
        int max=delete_root(arr,&n);
        arr[n+1]=max;
    }
    
}
int delete_root(int arr[],int *n){
    int max=arr[1];
    arr[1]=arr[*n];
    (*n)--;
    restoreDown(arr,1,*n);
    return max;
}
int main()
{
    int i,n;
    int arr[] = {82, 42, 49, 8, 25, 52, 36, 93, 59};
    n=sizeof(arr)/sizeof(arr[0]);

    heap_sort(arr,n);
    display(arr,n);
    return 0;
}