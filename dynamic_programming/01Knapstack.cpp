#include<iostream>

using namespace std;
int knapstackRec(int W,int wt[],int val[],int n,int** dp);
int knapstack(int W,int wt[],int val[],int n){

    int** dp=new int*[n];
    for (size_t i = 0; i < n; i++)
    {
        dp[i]=new int[W+1];
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < W+1; j++)
        {
            dp[i][j]=-1;
        }
    }
    return knapstackRec(W,wt,val,n-1,dp);
    
}
int knapstackRec(int W,int wt[],int val[],int n,int** dp){

    if(n<0)
        return 0;
    if(dp[n][W]!=-1)
        return dp[n][W];
    
    if(wt[n]>W){
         dp[n][W]=knapstackRec(W,wt,val,n-1,dp);
         return dp[n][W];
    }
       
    else{
        dp[n][W]=max(val[n]+knapstackRec(W-wt[n],wt,val,n-1,dp),knapstackRec(W,wt,val,n-1,dp));
        return dp[n][W];
    }
    
}
int main()
{
    int val[]={60,100,120};
    int wt[]={10,20,30};
    int W=50;
    int n=sizeof(val)/sizeof(val[0]);
    cout<<knapstack(W,wt,val,n)<<endl;
    return 0;
}