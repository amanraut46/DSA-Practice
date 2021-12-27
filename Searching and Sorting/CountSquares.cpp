#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include<math.h>
using namespace std;
int countSquares(int N)
{
    // code here
    int a=sqrt(N);
    if(a*a==N) return a-1;
    else return a;
}
int main()
{
    cout<<countSquares(9)<<"\n";
    return 0;
}