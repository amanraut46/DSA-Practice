#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
#include<unordered_map>
#include<string>
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
unordered_map<string,int> mp;
string solve(Node* root){

    if(!root) return "$";

    string s="";

    if(!root->left && !root->right){
        s=to_string(root->data);
        return s;
    }
    s=s+to_string(root->data);
    s=s+solve(root->left);
    s=s+solve(root->right);
    mp[s]++;
    return s;  
}
int dupSub(Node* root){
    mp.clear();
    solve(root);
    for(auto i:mp)
    {
        if(i.second>=2) return 1;
    }
    return 0;
}
int main()
{
    Node* root=new Node(1);
    root->left=new Node(2);
    root->right=new Node(3);

    root->left->left=new Node(4);
    root->left->right=new Node(5);

    root->right->right=new Node(2);
    root->right->right->left=new Node(4);
    root->right->right->right=new Node(5);
    int i=dupSub(root);
    cout<<i<<endl;
    return 0;
}