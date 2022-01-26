#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define n 2
#define m 5
int maxStop(int arr[][3]){
    vector<pair<int,int>> vt[n+1];
    for (size_t i = 0; i < m; i++)
    {
        vt[arr[i][2]].push_back({arr[i][1],arr[i][0]});
    }
    for (size_t i = 0; i < n; i++)
    {
        sort(vt[i].begin(),vt[i].end());
    }
    int count=0;
    for (size_t i = 0; i <= n; i++)
    {
        if(vt[i].size()==0)
            continue;
        
        int x=0;
        count++;
        for (size_t j = 1; j < vt[i].size(); j++)
        {
            if(vt[i][j].second>=vt[i][x].first){
                x=j;
                count++;
            }
        }
        
    }
    return count;
}
int main(){
    int arr[m][3] = { 1000, 1030, 1,
                      1010, 1020, 1,
                      1025, 1040, 1,
                      1130, 1145, 2,
                      1130, 1140, 2 };
                      
        cout << "Maximum Stopped Trains = "
         << maxStop(arr);
}