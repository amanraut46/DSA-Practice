#include<iostream>

using namespace std;
class Node
{
    public:
        int item;
        Node *next;

        Node(int item){
            this->item = item;
            next = NULL;
        }
        void PrintList(Node *head);
        int GetFirstNode(Node *head);
};
void Node::PrintList(Node *head){
    Node *top = head;
    if (top!=NULL)
    {
        cout << top->item << " ";
        PrintList(top->next);
    } 
}
int Node ::GetFirstNode(Node *head){
    Node *slow = head;
    Node *fast = head;

    while (fast!=NULL && fast->next!=NULL)
    {
        /* code */

        slow = slow->next;
        fast = fast->next->next;

        if (slow==fast)
        {
            /* code */
            break;
        }
    }
    if (slow!=fast)
    {
        /* code */
        return 0;
    }
    slow = head;
    while (slow!=fast)
    {
        /* code */
        slow = slow->next;
        fast = fast->next;
    }
    return slow->item;
};
int main()
{
    Node* head = new Node(50);
    head->next = new Node(20);
    head->next->next = new Node(15);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(10);
 
    /* Create a loop for testing */
    head->next->next->next->next->next = head->next->next;

    cout <<head->GetFirstNode(head) << endl;
}