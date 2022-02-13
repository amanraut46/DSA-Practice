#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int N=4;
    vector<int> a{4,2,1,8};
    sort(a.begin(),a.end());
    int sum=0;
    vector<int> rs;

    for (size_t i = 0; i < N/2; i++)
    {
        rs.push_back(a[i]);
        rs.push_back(a[N-i-1]);
    }
    if(N%2!=0) 
        rs.push_back(a[N/2]);
    
    for (size_t i = 1; i < N; i++)
    {
        sum+=abs(rs[i]-rs[i-1]);
    }
    sum+=abs(rs[N-1]-rs[0]);
    cout<<sum<<" ";
    
}