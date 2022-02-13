#include <iostream>
#include <vector>
#include <algorithm>

const int N = 1e5 + 10;
int dp[N];
using namespace std;

int fib(long long int n)
{

    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = fib(n - 1) + fib(n - 2);
}

int main()
{

    for (size_t i = 0; i < N; i++)
    {
        dp[i] = -1;
    }

    
    for (size_t i = 0; i <= 20; i++)
    {
        cout << fib(i) << endl;
    }

    return 0;
}