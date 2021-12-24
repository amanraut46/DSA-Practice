#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
void ShellSort(vector<int> &, int);
int main()
{
    vector<int> vt = {82, 42, 49, 8, 25, 52, 36, 93, 59};
    int n = vt.size();
    ShellSort(vt,n);
    for(auto it:vt){
        cout<<it<<" ";
    }
    return 0;
}
void ShellSort(vector<int> &vt, int n)
{
    int gap;
    for (gap = n / 2; gap >= 1;gap= gap / 2)
    {
        for (int j = gap; j < n; j++)
        {
            /* code */
            for (int i = j - gap; i >= 0; i = i - gap)
            {
                if (vt[i + gap] > vt[i])
                {
                    break;
                }
                else
                {
                    swap(vt[i + gap], vt[i]);
                }
            }
        }
    }
}