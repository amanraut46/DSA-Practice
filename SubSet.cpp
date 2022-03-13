#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;
void subset(string s,string curr,int n,vector<string> &vt)
{
    
    if(s.length()==n)
    {
        vt.push_back(curr);
        return;
    }
    subset(s,curr,n+1,vt);
     subset(s,curr+s[n],n+1,vt);
     
}
int main()
{
    string s = "abc";
    string curr="";
    
    vector<string> vt;
    subset(s,curr,0,vt);
    sort(vt.begin(),vt.end());
    for(string a: vt)
    {
        cout<<a<<" ";
    }
    return 0;
}