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
class LinkedList
{
public:
    int data;
    LinkedList *next;
    LinkedList *prev;
    LinkedList(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
void bToDLL(Node *root,Node **head)
{
    // your code here
    if(!root) return;

    static Node* prev=NULL;
    bToDLL(root->left,head);

    if(prev==NULL)
        *head=root;
    else{
        root->left=prev;
        prev->right=root;
    }

    prev=root;

    bToDLL(root->right,head);
    
    
}
int main()
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);
    Node* head=NULL;
    bToDLL(root,&head);

    while(head){
        cout<<head->data<<",";
        head=head->right;
    }
    
    return 0;
}