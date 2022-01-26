#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        int i=0;
        while(i<n){
            if(k>0){
                if(a[i]<0){
                    a[i]=-a[i];
                    k--;
                }
            }
            i++;
        }
        sort(a,a+n);
        
        while(k>0)
        {
            a[0]=-a[0];
            k--;
        }
        long long int sum=0;
        for(int i=0;i<n;i++){
            sum+=a[i];
        }
        return sum;
    }
int main()
{
    int n=5;
    int k=1;

    long long int vt[n]={
        1,2,-3,4,5
    };

    cout<<maximizeSum(vt,n,k);
}
