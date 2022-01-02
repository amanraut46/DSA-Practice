#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include<unordered_map>
using namespace std;
vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    // Your code goes here
    unordered_map<int,pair<int,int>> mp;
    vector<vector<int>> quad;
    for(int i=0;i<arr.size()-1;i++){
        for(int j=i+1;j<arr.size();j++){
            mp[arr[i]+arr[j]]={i,j};
        }
    }
    const int N=arr.size();
    int temp[N];   

    for(int i=0;i<N;i++)
        temp[i]=0;    
    

    for(int i=0;i<N-1;i++){
        for(int j=i+1;j<N;j++){
            int sum=arr[i]+arr[j];

            if(mp.find(k-sum)!=mp.end()){
                pair<int,int> p=mp[k-sum];
                if(p.first != i && p.second != i
                    && p.first != j && p.second != j
                    && temp[p.first] == 0
                    && temp[p.second] == 0 && temp[i] == 0
                    && temp[j] == 0){
                    vector<int> vt={arr[i],arr[j],arr[p.first],arr[p.second]};
                    quad.push_back(vt);
                    temp[p.second]=1;
                    temp[i]=1;
                    temp[j]=1;
                    break;
                }
            }
        }
    }
    
    return quad;
}
int main()
{
    int N = 5, K = 3;
    vector<int> A = {0, 0, 2, 1, 1};
    vector<vector<int>> vt=fourSum(A,K);
    for(auto i:vt){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}