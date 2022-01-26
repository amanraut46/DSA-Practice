#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

struct Job
{
    char id;
    int dead;
    int profit;
};
static bool comparator(Job a, Job b)
{
    return (a.profit > b.profit);
}
// Function to find the maximum profit and the number of jobs done.
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    vector<int> ans;
    sort(arr, arr + n, comparator);
    int maxi = arr[0].dead;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i].dead);
    }
    int slot[maxi + 1];
    memset(slot, -1, sizeof(slot));

    int countjob = 0, jobprofit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                jobprofit += arr[i].profit;
                countjob++;
                break;
            }
        }
    }
    ans.push_back(countjob);
    ans.push_back(jobprofit);
    return ans;
}
int main()
{
    struct Job arr[] = {{'a', 4, 20}, {'b', 1, 10}, {'c', 1, 40}, {'d', 1, 30}};
    int n = 4;
    cout << "Following is maximum profit sequence of jobs \n";

    // Function call
    vector<int> vt=JobScheduling(arr, n);
    for (auto i:vt)
    {
        cout<<i<<endl;
    }
    
    return 0;
}