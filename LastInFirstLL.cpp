#include<iostream>

using namespace std;

struct Node
{
    /* data */
    int data;
    struct Node *next;
};
void PrintNode(struct Node *);
struct Node *LastFirst(struct Node *);
struct Node *Insert(int data){
    struct Node *new_node = new Node;
    new_node->data = data;
    new_node->next = nullptr;
    return new_node;
}

int main(){

    struct Node *head = Insert(1);
    head->next = Insert(2);
    head->next->next = Insert(3);
    head->next->next->next = Insert(4);
    PrintNode(head);
    cout << endl;
    PrintNode(LastFirst(head));
    cout << endl;
    return 0;
}
void PrintNode(struct Node *head){
    struct Node *current = head;
    while (current!=NULL)
    {
        /* code */
        cout << current->data << " ";
        current = current->next;
    }
}
struct Node *LastFirst(struct Node *head){

    struct Node *current = head;
    struct Node *prev = nullptr;

    while (current->next!=nullptr)
    {
        prev = current;
        current = current->next;
    }
    if(prev!=nullptr){
        struct Node *temp = current;
        
        cout << temp->data << endl;
        prev->next = nullptr;
        
        temp->next = head;

        return temp;
    }
    return head;
}
