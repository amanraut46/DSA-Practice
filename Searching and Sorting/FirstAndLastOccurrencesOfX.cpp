#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
vector<int> find(int arr[], int n, int x);
int last(int arr[], int n, int x);
int first(int arr[], int n, int x);
int main()
{
    int n = 9, x = 7;
    int arr[] = {1, 3, 5, 5, 5, 5, 7, 123, 125};
    vector<int> vt=find(arr, n, x);
    for (int i : vt)
    {
        cout << i << " ";
    }
    return 0;
}
vector<int> find(int arr[], int n, int x)
{
    // code here
    vector<int> vt(2);
    //vt[0] = first(arr, n, x);
    //vt[1] = last(arr, n, x);
    return {first(arr, n, x),last(arr, n, x)};
}
int first(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;
    int res = -1;

    while (low <= high)
    {
        /* code */
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
int last(int arr[], int n, int x)
{
    int low = 0;
    int high = n-1;
    int res = -1;

    while (low <= high)
    {
        /* code */
        int mid = (low + high) / 2;

        if (arr[mid] > x)
            high = mid - 1;
        else if (arr[mid] < x)
            low = mid + 1;
        else
        {
            res = mid;
            low = mid + 1;
        }
    }
    return res;
}
