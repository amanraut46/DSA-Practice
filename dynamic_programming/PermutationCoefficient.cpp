#include<iostream>

using namespace std;

int permutationCoeff(int n,int k){

//    int fact[n+1];
//
//    fact[0]=1;
//    for (size_t i = 1; i <= n; i++)
//    {
//        fact[i]=i*fact[i-1];
//    }
//    return fact[n]/fact[n-k];

    int p=1;

    for (size_t i = 0; i < k; i++)
    {
        p*=(n-i);
    }
    return p;

}
int main()
{
    int n = 10, k = 2;
     
    cout << "Value of P(" << n << ", "
        << k << ") is "
        << permutationCoeff(n, k);
 
    return 0;
}