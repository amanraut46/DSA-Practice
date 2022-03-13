#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

static bool comp(pair<int,int> p1,pair<int,int> p2)
{
    if(p1.second==p2.second)
        return p1.first<p2.first;

    return p1.second < p2.second;
}
int main()
{
    int N = 6;
    vector<int>start {1,3,0,5,8,5};
    vector<int>end  {2,4,6,7,9,9};

    vector<pair<int,int>> vt;

    for (size_t i = 0; i < N; i++)
    {
        vt.push_back({start[i],end[i]});
    }
    
    sort(vt.begin(),vt.end(),comp);

    
    pair<int,int> prev=vt[0];
    int ans=1;
    for (size_t i = 1; i < N; i++)
    {
        pair<int,int> curr=vt[i];
        if(prev.second < curr.first)
        {
            prev=curr;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}