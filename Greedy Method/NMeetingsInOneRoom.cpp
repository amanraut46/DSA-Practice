#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
static bool comp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}
int main()
{
    int N = 6;
    vector<int> start{1, 3, 0, 5, 8, 5};
    vector<int> end{2, 4, 6, 7, 9, 9};
    vector<pair<int,int>> vt;
    for (size_t i = 0; i < N; i++)
    {
        vt.push_back({start[i],end[i]});
    }
    sort(vt.begin(),vt.end(),comp);
    int i=0;
    int j=1;
    int c=1;
    while (j<N)
    {
        if(vt[i].second<vt[j].first){
            i=j;
            j++;
            c++;
        }
        else{
            j++;
        }
    }
    cout<<c<<endl;
    return 0;
}