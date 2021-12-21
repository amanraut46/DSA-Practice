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
Node* BuildTree(int arr[],int *preIndex,int key,int min,int max,int size){
    if(*preIndex>=size)
        return NULL;

    Node* root=NULL;
    if(key>min && key<max){
        root=new Node(key);
        *preIndex = *preIndex + 1;

        if(*preIndex<size){
            root->left=BuildTree(arr,preIndex,arr[*preIndex],min,key,size);
        }
        if(*preIndex<size){
            root->right=BuildTree(arr,preIndex,arr[*preIndex],key,max,size);
        }
    }
    return root;
}
void Preorder(Node * root){
    if(!root) return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
    int arr[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    Node *root=nullptr;
    int preIndex=0;
    root = BuildTree(arr,&preIndex,arr[0],INT32_MIN,INT32_MAX, size);
    Preorder(root);
    return 0;
}