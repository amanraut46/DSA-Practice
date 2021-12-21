#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};
vector<vector<int>> sortedMatrix(int N, vector<vector<int>> &Mat)
{
    // code here
    vector<int> vt;
    for(auto it:Mat){
        for(auto i:it){
            vt.push_back(i);
        }
    }
    sort(vt.begin(),vt.end());
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            Mat[i][j]=vt.front();
        }
    }

}
int main()
{
    int n = 4;
    vector<vector<int>> vt = {{10, 20, 30, 40},
                              {15, 25, 35, 45},
                              {27, 29, 37, 48},
                              {32, 33, 39, 50}};
                              sortedMatrix(n,vt);
    for(auto it:vt){
        for(auto i:it){
            cout<<i<<" ";
        }
        cout<<endl;

    }               
    return 0;
}