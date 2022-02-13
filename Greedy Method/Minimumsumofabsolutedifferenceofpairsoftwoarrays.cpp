#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int findsum(vector<int> a,vector<int> b,int n){
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int sum=0;

    for (int i = 0; i < n; i++)
    {
        sum=sum+abs(a[i]-b[i]);
    }
    return sum;
}
int main(){
    vector<int> a{4,1,8,7};
    vector<int> b{2,3,6,5};
    int n=sizeof(a)/sizeof(a[0]);
    cout<<findsum(a,b,n);
    return 0;
}