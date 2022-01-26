#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
int findPlatform(int arr[],int dep[],int n){
    sort(arr, arr + n); sort(dep, dep + n);
        int j = 0, ans = 0;
        for(int i=0; i<n; i++) {
            if(arr[i]>dep[j]) {
                j++;
            }
            else {
                ans++;
            }
        }
        return ans;
}
int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}