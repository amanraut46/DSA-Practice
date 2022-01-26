#include<iostream>
#include<vector>

using namespace std;

int maxProductSubset(int arr[],int n){

    if(n==1)
        return arr[0];
    int negc=0;
    int zeroc=0;
    int product=1;
    int max_neg=INT32_MIN;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]==0)
        {
            zeroc++;
            continue;
        }
        if(arr[i]<0)
        {
            negc++;
            max_neg=max(max_neg,arr[i]);
        }
        product=product*arr[i];
    }
    if(zeroc==n)
        return 0;

    cout<<"zeroc:"<<zeroc<<endl;
    cout<<"negc:"<<negc<<endl;
    cout<<"negc&1:"<<(negc&1)<<endl;
    if(negc &1)
    {
        if(negc==1 && zeroc>0 && zeroc+negc==n)
            return 0;
    
        product=product/max_neg;
    }
    
    return product;
}
int main()
{

    int a[] = {  -1, -1, -2, 4, 3  };
    int n = sizeof(a) / sizeof(a[0]);
    cout << maxProductSubset(a, n);
}
