#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
    int s,n,m;
    cin>>s>>n>>m;

    int x=s/7;
    int y=s-x;
    int sm=s*m;

    int days=sm/n;

    if(sm%n!=0) days++;

    if(days<=y) cout<<"Yes"<<" "<<days;
    else cout<<"No";

    return 0;
}
