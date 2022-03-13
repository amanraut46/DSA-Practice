#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
const int N=1e5+10;
int i=0;
int arr[100][100];
int solve(int coins[],int numberOfCoins,int value)
{
    
    if(value==0)
        return 1;
    if(value<0)
        return 0;
    if(numberOfCoins<=0 && value>=1)
        return 0;
    
        return solve(coins,numberOfCoins-1,value)+solve(coins,numberOfCoins-1,value-coins[numberOfCoins-1]);
}
int main()
{
    int value = 4;
    
    int coins[] = {1, 2, 3};
    int numberOfCoins =sizeof(coins) / sizeof(coins[0]);
    cout<<solve(coins,numberOfCoins,value)<<endl;
    return 0;
}