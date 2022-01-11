#include <iostream>
#include <vector>
using namespace std;
bool solve(int u,vector<int> arr[],vector<bool> &visited,vector<bool> &st);
bool iscyclic(int n,vector<int> adk[]){
    vector<bool> visted(n,false);
    vector<bool> st(n,false);

    for (int i = 0; i < n; i++)
    {
        if(solve(i,adk,visted,st)){
           
           return true;
        }
    }
    return false;
}
bool solve(int u,vector<int> arr[],vector<bool> &visited,vector<bool> &st){

    visited[u]=true;
    st[u]=true;

    for (auto i: arr[u])
    {
        if(st[i])
            return true;
        else if(!visited[i] && solve(i,arr,visited,st)){
            return true;
        }
    }
    st[u] = false;
    return false;
}
int main()
{

    int n = 2;
    vector<int> l[n];
    

    l[1].push_back(0);
    //l[0].push_back(1);
    
    if(iscyclic(n,l)){
        cout << "Impossible to finish all tasks";
    }
    else{
        cout << "Possible to finish all tasks";
    }
    return 0;
}