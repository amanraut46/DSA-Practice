#include<iostream>
using namespace std;

void Swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void ReArrange(int arr[],int n){
    int j = 0; 
    for (int i = 0; i < n; i++)
    {
        if (arr[i]<0)
        {
            Swap(&arr[j],&arr[i]);
            j++;
        } 
    }
    
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    ReArrange(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout<< arr[i] <<" ";
    }
    return 0;
}