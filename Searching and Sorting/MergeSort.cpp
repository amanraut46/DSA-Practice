#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
#define max 100
void mergearray(int vt[],int low, int mid,int end);
void copy(int vt[], int temp[], int start, int end);
void mergeSOrt(int vt[], int start, int end)
{
    
    int mid;
    if (start >= end)
        return;
    mid = (start + end)/2;
    mergeSOrt(vt, start, mid);
    mergeSOrt(vt, mid + 1, end);
    mergearray(vt,start, mid,end);
    
}
void copy(int vt[], int temp[], int start, int end)
{

    for (int i = start; i < end; i++)
    {
        vt[i] = temp[i];
    }
}
void mergearray(int vt[],int low, int mid,int end)
{

    int const subArrayOne=mid-low+1;
    int const subArrayTwo=end-mid;

    int *leftarray=new int[subArrayOne];
    int *rightarray=new int[subArrayTwo];

    for(int i=0;i<subArrayOne;i++){
        leftarray[i]=vt[low+i];
    }
    for(int j=0;j<subArrayTwo;j++){
        rightarray[j]=vt[mid+1+j];
    }
    int k=low;
    int i=0;
    int j=0;
    while (i < subArrayOne && j < subArrayTwo)
    {
        /* code */
        if (leftarray[i] <= rightarray[j])
        {
            vt[k++] = leftarray[i++];
        }
        else
        {
            vt[k++] = rightarray[j++];
        }
    }
    while (i < subArrayOne)
    {
        /* code */
        vt[k++] = leftarray[i++];
    }
    while (j < subArrayTwo)
    {
        /* code */
        vt[k++] = rightarray[j++];
    }
}
int main()
{
    int vt[] = {82, 42, 49, 8, 25, 52, 36, 93, 59};
    int start = 0;
    int end = sizeof(vt) / sizeof(vt[0]);
    mergeSOrt(vt, start, end - 1);
    
    for(auto it:vt){
        cout<<it<<" ";
    }
    return 0;
}