#include<iostream>

using namespace std;
class StackNode{
    public:
    int data;
    StackNode* next;
};
StackNode* newNode(int data){

    StackNode* st=new StackNode();
    st->data=data;
    st->next=NULL;
}
int isEmpty(StackNode* root){

    return !root;
}
void push(StackNode** root,int data){

    StackNode* newel=newNode(data);

    newel->next=*root;
    *root=newel;
    cout<<data<<"Pushed to stack\n";
}
int pop(StackNode** root){

    if(isEmpty(*root)){
        return INT_MIN;
    }
    StackNode *temp=*root;
    *root=(*root)->next;
    int popped=temp->data;
    free(temp);

    return popped;
}
int peek(StackNode* root){

    if(isEmpty(root)){
        return INT_MIN;
    }
    return root->data;
}
int main()
{
    StackNode* root=NULL;
    push(&root,10);
    push(&root,20);
    push(&root,30);

    cout<<pop(&root)<<"Popped from";
    
}