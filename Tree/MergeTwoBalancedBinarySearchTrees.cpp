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
void InorderTravesal(Node*,vector<int>&);
vector<int> mergearray(vector<int>,vector<int>,int,int);
Node* sortedArrayToBST(vector<int>,int,int);
void Preorder(Node*);
Node* mergeTrees(Node* root1,Node* root2,int m,int n){

    vector<int> arr1;
    vector<int> arr2;

    InorderTravesal(root1,arr1);
    InorderTravesal(root2,arr2);
    vector<int> mergevector=mergearray(arr1,arr2,m,n);
    
    return sortedArrayToBST(mergevector,0,m+n-1);
}
void InorderTravesal(Node* root,vector<int> &vt){

    if(!root) return;

    InorderTravesal(root->left,vt);
    vt.push_back(root->data);
    InorderTravesal(root->right,vt);
}
vector<int> mergearray(vector<int> vt1,vector<int> vt2,int m,int n){
    vector<int> mergearray;
    
    int i=0;
    int j=0;
    int k=0;
    
    while (i< m && j< n)
    {
        /* code */
        
        if(vt1[i] < vt2[j]){
            
            mergearray.push_back(vt1[i]);
            i++;
        }
        else if(vt1[i]>vt2[j]){
            mergearray.push_back(vt2[j]);
            j++;
        }
        else{
            mergearray.push_back(vt1[i]);
            i++;
            j++;
        }
        k++;
    }
    while (i<m)
    {
        /* code */
        mergearray.push_back(vt1[i]);
        k++;i++;

    }
    while (j<n)
    {
        /* code */
        mergearray.push_back(vt2[j]);
        k++;j++;

    }
    return mergearray;
    
}
Node* sortedArrayToBST(vector<int> vt,int start,int end){

    if(start>end)
        return NULL;
    int mid=(start+end)/2;

    Node* root=new Node(vt[mid]);

    root->left=sortedArrayToBST(vt,start,mid-1);
    root->right=sortedArrayToBST(vt,mid+1,end);

    return root;
}
void Preorder(Node* root){

    if(!root) return;

    cout<<root->data<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
int main()
{
    /* Create following tree as first balanced BST
        100
        / \
        50 300
    / \
    20 70
    */
    Node *root1 = new Node(100);
    root1->left = new Node(50);
    root1->right = new Node(300);
    root1->left->left = new Node(20);
    root1->left->right = new Node(70);

    /* Create following tree as second balanced BST
            80
        / \
        40 120
    */
    Node *root2 = new Node(80);
    root2->left = new Node(40);
    root2->right = new Node(120);

    Node *mergedTree = mergeTrees(root1, root2, 5, 3);
    Preorder(mergedTree);
    return 0;
}