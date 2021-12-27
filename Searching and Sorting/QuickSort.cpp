#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
void PrintArray(int [],int,int);
int partition(int arr[],int start,int end){
    int i=start+1;
    int j=end;
    int privote=arr[start];

    while (i<=j)
    {
        /* code */
        while (arr[i]< privote && i<end)
        {
            i++;
        }
        while (arr[j]>privote)
        {
            j--;
        }
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
            j--;
        }
        else
            i++;
    }
    arr[start]=arr[j];
    arr[j]=privote;
    return j;
}
void quick(int arr[],int start,int end){
    int pivloc;

    if(start>=end) return;

    pivloc=partition(arr,start,end);
    
    quick(arr,start,pivloc-1);
    quick(arr,pivloc+1,end);
}
void PrintArray(int arr[],int s,int n){
    
    for (int i = s; i < n; i++)
    {
        /* code */
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
}
int main()
{
    int vt[] = {82, 42, 49, 8, 25, 52, 36, 93, 59};
    int start = 0;
    int end = sizeof(vt) / sizeof(vt[0]);
    quick(vt,start,end-1);
    //PrintArray(vt,start,end-1);
    return 0;
}