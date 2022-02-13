#include<iostream>

using namespace std;
#define max 100

int dp[max];

void initalize(){
    for (size_t i = 0; i < max; i++)
    {
        dp[i]=-1;
    }
    
}
int solve(int n,int arr[]){

    if(n<0)
        return 0;
    if(n==0)
        return 1;
    if(dp[n]!=-1)
        return dp[n];
    
    return dp[n]=solve(n-1,arr)+solve(n-3,arr)+solve(n-5,arr);
}

int main(){

    int arr[]={1,3,5};
    int n=6;
    initalize();
    cout<<solve(n,arr);
    return 0;
}