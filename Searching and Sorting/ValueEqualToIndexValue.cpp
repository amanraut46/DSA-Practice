#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> valueEqualToIndex(int arr[], int n);
int main()
{
    int N = 5;
    int Arr[] = {15, 2, 45, 12, 7};
    for(auto it:valueEqualToIndex(Arr,N))
        cout<<it<<" ";
    return 0;
}
vector<int> valueEqualToIndex(int arr[], int n)
{
    // code here
    vector<int> vt;
    for (int i = 0; i < n; i++)
    {
        if (i + 1 == arr[i])
            vt.push_back(arr[i]);
    }
    return vt;
}