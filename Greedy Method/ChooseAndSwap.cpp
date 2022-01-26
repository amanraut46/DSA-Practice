#include<iostream>
#include<vector>
#include<set>
using namespace std;
#define MAX 26
string smallestStr(string str,int n){
    set<char> s;
    for (size_t i = 0; i < n; i++)
    {
        s.insert(str[i]);
    }
    for (size_t i = 0; i < n; i++)
    {
        s.erase(str[i]);
        if(s.empty()) break;

        char ch=*s.begin();

        if(ch<str[i]){
            int ch2=str[i];

            for (int j = 0; j < n; j++)
            {
                if(str[j]==ch) str[j]=ch2;
                else if(str[j]==ch2) str[j]=ch;
            }
            break;
            
        }
    }
    return str;
    
}
int main(){
    
    string str="ccad";
    int n=str.length();
    cout<<smallestStr(str,n);
    return 0;
}