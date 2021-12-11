#include<iostream>
using namespace std;

void RearrangeArray(int arr[],int n){
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        /* code */
        if (arr[i]<0)
        {
            /* code */
            if (i!=j)
            {
                /* code */
                Swap(arr[i], arr[j]);
            }
            j++;
        }
        
    }  
}
void Swap(int a,int b){
    int temp = a;
    a = b;
    b = temp;
}
void printarray(int arr[]){
    for (int i = 0; i <sizeof(arr); i++)
    {
        /* code */
        cout << arr[i] << " ";
    }
    
}
int main()
{
    int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
    int n = sizeof(arr) / sizeof(arr[0]);
    RearrangeArray(arr, n);
    printarray(arr);
    return 0;
}