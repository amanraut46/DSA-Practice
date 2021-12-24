#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

// Time complexity O(n^2)
// Space complexity o(1)
void sortByBubbleSort(vector<int> &vt, int n)
{

    int xchange = 0;
    for (int i = 0; i < n - 1; i++)
    {
        /* code */
        xchange = 0;
        for (int j = i + 1; j < n; j++)
        {
            /* code */
            if (vt[i] > vt[j])
            {
                int temp = vt[i];
                vt[i] = vt[j];
                vt[j] = temp;
                xchange++;
            }
        }
        if (xchange == 0)
            break;
    }
}
int main()
{
    vector<int> vt = {82, 42, 49, 8, 25, 52, 36, 93, 59};
    int n = vt.size();
    sortByBubbleSort(vt, n);

    for (auto i : vt)
    {
        cout << i <<" ";
    }
    return 0;
}