#include<iostream>
using namespace std;

int binomialCoeffutil(int n,int k,int **dp);
int binomialCoeff(int n,int k){

    int** dp=new int*[n+1];
    for (size_t i = 0; i < n+1; i++)
    {
        dp[i]=new int[k+1];
    }

    for (size_t i = 0; i < n+1; i++)
    {
        for (size_t j = 0; j < k+1; j++)
        {
            dp[i][j]=-1;
        }   
    }
    
    return binomialCoeffutil(n,k,dp);
}
int binomialCoeffutil(int n,int k,int **dp){

    if(dp[n][k]!=-1)
        return dp[n][k];
    if(k==n || k==0)
       return dp[n][k]=1;
    
    dp[n][k]=binomialCoeffutil(n-1,k-1,dp)+binomialCoeffutil(n-1,k,dp);
}
int main()
{
    int n=5;
    int k=2;
    cout<<binomialCoeff(n,k)<<endl;
    return 0;
}