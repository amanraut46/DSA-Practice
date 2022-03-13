#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int N = 6, S = 9;

    if(9*N < S)
        return -1;
    string ans="";

    while (ans.size()<N)
    {
        int dig=min(S,9);
        S-=dig;
        ans+=to_string(dig);
    }
    
    cout<<ans<<endl;
}