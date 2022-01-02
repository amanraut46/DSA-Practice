#include<iostream>
#include<vector>
#include<stack>
#include <algorithm>
#include<queue>
using namespace std;
void Insert(int H[],int n){
    int i=n;
    int temp;
    temp=H[i];
    while (i>1 && temp>H[i/2])
    {
        H[i]=H[i/2];
        i=i/2;
    }
    H[i]=temp;
    
}
int Delete(int H[],int n){
    int i,j,x,temp,val;
    val=H[1];
    x=H[n];

    H[1]=H[n];
    i=1;
    j=i*2;

    while (j<=n-1)
    {
        if(j<n-1 && H[j+1]>H[j]){
            j=j+1;
        }
        if(H[i]<H[j]){
            temp=H[i];
            H[i]=H[j];
            H[j]=temp;
            i=j;
            j=2*j;
        }
        else 
            break;
        
    }
    return val;
    
}
int main()
{
    int H[]={0,14,15,5,20,30,8,40};
    int i;
    for (int i = 2; i <=7; i++)
    {
        Insert(H,i);
    }
    for (int i = 7; i >0; i--)
    {
        cout<<Delete(H,i)<<" ";
    }
    
    return 0;
}