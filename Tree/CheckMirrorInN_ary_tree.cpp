#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include<unordered_map>
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
int checkMirrorTree(int n, int e, int A[], int B[]) {
        // code here
        unordered_map<int,stack<int>> mp;
        
        for(int i=0;i<2*e;i+=2){
            mp[A[i]].push(A[i+1]);
        }
        for(int i=0;i<2*e;i+=2){
            if(mp[B[i]].top()!=B[i+1])
               return 0;
            mp[B[i]].pop();
        }
        return 1;
    }
int main()
{
    int n=3;
    int e=2;
    int A[] = {1, 2, 1, 3};
    int B[] = {1, 3, 1, 2};
    cout<<checkMirrorTree(n,e,A,B);
    return 0;
}