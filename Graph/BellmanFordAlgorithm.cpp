#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){

    int v=5;
    int e=8;
    vector<int> dist(v,INT32_MAX);
    vector<vector<int>> vt;
    vt.push_back({0,1,-1});
    vt.push_back({0,2,4});
    vt.push_back({1,2,3});
    vt.push_back({1,3,2});
    vt.push_back({1,4,2});
    vt.push_back({3,2,5});
    vt.push_back({3,1,1});
    vt.push_back({4,3,-3});

    bool isnegative=false;
    dist[0]=0;
    for (size_t i = 1; i < v; i++)
    {
        
        for(auto j: vt){
            int u=j[0];
            int v=j[1];
            int w=j[2];

            if(dist[v]>w+dist[u]){
                isnegative=true;
            }
            dist[v]=min(dist[v],w+dist[u]);
        }
    }
    if(isnegative){
        cout<<"Negative weight found"<<endl;
    }
    else{
        cout<<"Negative weight not found"<<endl;
    }
    for (size_t i = 0; i < v; i++)
    {
        cout<<i<<"\t\t"<<dist[i]<<endl;
    }
    
    
    //BellManFord(v,e,vt,0);
    return 0;
}