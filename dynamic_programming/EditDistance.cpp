#include <iostream>
#include <vector>
using namespace std;
int editDistancUtl(string s1,int n,string s2,int m,vector<vector<int>> &dp);

int editDistance(string s, string t)
{
    // Code here
    int n=s.length();
    int m=t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    
    return editDistancUtl(s,n,t,m,dp);
}
int editDistancUtl(string s1,int n,string s2,int m,vector<vector<int>> &dp){

    
    if(n==0)
        return m;
    if(m==0)
        return n;
    if(dp[n][m]!=-1) return dp[n][m];
    if(s1[n-1]==s2[m-1])
    {
        if(dp[n-1][m-1]==-1)
            dp[n][m]=editDistancUtl(s1,n-1,s2,m-1,dp);
        else
            dp[n][m]=dp[n-1][m-1];
    }   
    else
    {
        int m1,m2,m3;

        if(dp[n-1][m]!=-1){
            m1=dp[n-1][m];
        }
        else{
            m1=editDistancUtl(s1,n-1,s2,m,dp);
        }
        if(dp[n][m-1]!=-1){
            m2=dp[n][m-1];
        }
        else{
            m2=editDistancUtl(s1,n,s2,m-1,dp);
        }
        if(dp[n-1][m-1]!=-1){
            m3=dp[n-1][m-1];
        }
        else{
            m3=editDistancUtl(s1,n-1,s2,m-1,dp);
        }
        return dp[n][m]=1+min(m1,min(m2,m3));
    }
        
}
int main()
{

    string s = "geek", t = "gesek";
    cout<<editDistance(s,t)<<endl;
    return 0;
}