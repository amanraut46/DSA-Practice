#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> candyStore(vector<int> candey,int n,int k){

    sort(candey.begin(),candey.end());
    
    int min=0;
    int max=0;
    int temp=0;
    for (size_t i = 0; i < n; i++)
    {
       if(temp>=n)
            break;
        min=min+candey[i];
        max=max+candey[n-1-i];
        temp++;
        temp=temp+k;
    }
    return {min,max};
}
int main(){
    int n=4;
    int k=2;
    vector<int> candey{3,2,1,4};

    for(auto i:candyStore(candey,n,k)){
        cout<<i<<" ";
    };
    return 0;
}