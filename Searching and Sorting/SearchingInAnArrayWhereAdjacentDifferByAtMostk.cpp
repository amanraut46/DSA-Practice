#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

int main()
{
    int arr[] = {20, 40, 50, 70, 70, 60};
    int  k = 20;
    int  x = 50;
    int a=-1;
    int n=sizeof(arr)/sizeof(arr[0]);
    int i=0;
    while(i<n){

        if(arr[i]==x)
            a=i;

        i=i + max(1, abs(arr[i]-x)/k);
    }
    cout << "Element " << x  << " is present at index "
        <<a;
    return 0;
}