#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int MaxSumDifference(int arr[],int n){
    sort(arr,arr+n);
    vector<int> sample;

    for (size_t i = 0; i < n/2; i++)
    {
        sample.push_back(arr[i]);
        sample.push_back(arr[n-i-1]);
    }
    if(n%2!=0)
        sample.push_back(arr[n/2]);

    int maxsum=0;

    for (size_t i = 0; i < n-1; i++)
    {
        maxsum=maxsum+abs(sample[i]-sample[i+1]);
    }
    maxsum=maxsum+abs(sample[n-1]-sample[0]);
    return maxsum;
}

int main()
{
    int a[] = { 1, 2, 4, 8 };
    int n = sizeof(a) / sizeof(a[0]);
 
    cout << MaxSumDifference(a, n) << endl;
    return 0;
}