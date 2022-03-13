#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool comp(pair<int,int> a,pair<int,int> b)
{
    if(a.second==b.second)
        return a.first < b.first;

    return a.second < b.second;
}
int activitySelection(vector<int> start, vector<int> end, int N)
{
    vector<pair<int,int>> vt;

    for (int i = 0; i < N; i++)
    {
        vt.push_back({start[i],end[i]});
    }

    sort(vt.begin(),vt.end(),comp);
    for (size_t i = 0; i < N; i++)
    {
        cout<<vt[i].first<<" "<<vt[i].second<<endl;
    }
    
    int ans=1;
    pair<int,int> pre=vt[0];
    for (size_t i = 1; i < N; i++)
    {
        pair<int,int> curr=vt[i];
        if(pre.second<curr.first)
        {
            ans++;
            pre=curr;
        }
    }
    return ans;
}
int main()
{
    int N = 4;
    vector<int> start {1, 3, 2, 5};
    vector<int> end {2, 4, 3, 6};

    
   
    cout<<activitySelection(start,end,N)<<endl;
    

    return 0;
}