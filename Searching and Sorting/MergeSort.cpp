#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
#define max 100
void mergearray(int vt[], int temp[], int low1, int end1, int low2, int end2);
void mergeSOrt(int vt[], int start, int end)
{
    int temp[max];
    if (start > end)
        return;
    if (start < end)
    {
        int temp[max];
        int mid = (start + end) / 2;
        mergeSOrt(vt, start, mid);
        mergeSOrt(vt, mid + 1, end);
        mergearray(vt, temp, start, mid, mid + 1, end);
    }

        copy(vt,temp,start,end);
}
 void copy(int vt[],int temp[],int start,int end){

     for(int i=start;i<end;i++){
         vt[i]=temp[i];
     }
 }
void mergearray(int vt[], int temp[], int low1, int end1, int low2, int end2)
{
    
    int i = low1;
    int j = low2;
    int k = low1;
    
     while (i <= end1 && j <= end2)
    {
         /* code */
         if (vt[i] < vt[j])
         {
             temp[k] = vt[i];
             i++;
         }
         else if (vt[i] > vt[j])
         {
             temp[k] = vt[j];
             j++;
         }
         else
         {
             temp[k] = vt[i];
             i++;
             j++;
         }
         k++;
     }
     while (i <= end1)
    {
         /* code */
         temp[k] = vt[i];
         i++;
         k++;
     }
     while (j <= end2)
    {
         /* code */
         temp[k] = vt[j];
         j++;
         k++;
     }
}
int main()
{
    int vt[] = {82, 42, 49, 8, 25, 52, 36, 93, 59};
    int start = 0;
    int end = sizeof(vt) / sizeof(vt[0]);
    mergeSOrt(vt, start, end - 1);
    //for (auto it : vt)
    //{
    //    cout << it << " ";
    //}
    return 0;
}