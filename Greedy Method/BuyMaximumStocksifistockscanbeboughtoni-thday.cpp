#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int buyMaximumProducts(int n,int k,int price[]){
    vector<pair<int,int>> v;
    for (size_t i = 0; i < n; i++)
    {
        v.push_back({price[i],i+1});
    }
    sort(v.begin(),v.end());

    int ans=0;
    for (size_t i = 0; i < n; i++)
    {
        ans+=min(v[i].second,k/v[i].first);
        k-=v[i].first*min(v[i].second,k/v[i].first);
    }
    return ans;
}
int main()
{
    int price[] = { 10, 7, 19 };
    int n = sizeof(price)/sizeof(price[0]);
    int k = 45;
 
    cout << buyMaximumProducts(n, k, price) << endl;
 
    return 0;
    return 0;
}