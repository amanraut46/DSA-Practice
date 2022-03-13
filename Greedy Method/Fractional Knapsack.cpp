#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
static bool comp(pair<int,int> p1,pair<int,int> p2){

    double d1=p1.first/p1.second;
    double d2=p2.first/p2.second;

    return d1>d2;
}
int main()
{
    int N = 3, W = 50;
    vector<int>values {60,100,120};
    vector<int>weight {10,20,30};

    vector<pair<int,int>> vt;

    for (size_t i = 0; i < N; i++)
    {
        vt.push_back({values[i],weight[i]});
    }
    sort(vt.begin(),vt.end(),comp);
    double score=0;
    for (size_t i = 0; i < N; i++)
    {
        if(vt[i].second<=W)
        {
            score+=vt[i].first;
            W-=vt[i].second;
        }
        else
        {
            score=score+(double)(vt[i].first*W)/vt[i].second;
            W=0;
            break;
        }
    }
    cout<<score<<endl;
}
