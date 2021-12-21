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
vector<int> levelOrder(Node *node)
{
    // Your code here
    queue<Node *> st;
    vector<int> vt;

    st.push(node);

    while (!st.empty())
    {
        Node *temp = st.front();
        st.pop();
        vt.push_back(temp->data);

        if (temp->left != nullptr)
        {
            st.push(temp->left);
        }

        if (temp->right != nullptr)
        {
            st.push(temp->right);
        }
    }
    return vt;
}
int main()
{
    //    10
    //  /  \
    // 20   30
    // / \ 
   //40  60

    Node *root = new Node(10);

    root->left = new Node(20);

    root->right = new Node(30);

    root->left->left = new Node(40);
    root->left->right = new Node(60);
    vector<int> vt = levelOrder(root);
    for (auto i : vt)
    {
        cout << i << " ";
    }
    return 0;
}