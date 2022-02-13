#include<iostream>

using namespace std;

int catalan(int n){
int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for (size_t i = 2; i <= n; i++)
    {
        dp[i]=0;
        for (size_t j = 0; j < i; j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    for (size_t i = 0; i < n; i++)
    {
        cout<<catalan(i)<<endl;
    }
    
    return 0;
}