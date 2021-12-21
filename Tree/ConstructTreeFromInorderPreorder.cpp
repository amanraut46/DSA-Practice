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
int search(int[], int, int);
Node *buildTree(int in[], int pre[], int n)
{
    // Code here
    if (n == 0)
        return NULL;
    int root = search(in, pre[0], n);
    Node *temp = new Node(pre[0]);
    
    temp->left = buildTree(in, pre + 1, root);
    temp->right = buildTree(in + root + 1, pre + root + 1, n - root - 1);
}
int search(int in[], int x, int n)
{

    for (int i = 0; i < n; i++)
    {

        if (in[i] == x)
            return i;
    }
    return -1;
}
void InoderTravels(Node *node)
{

    if (node == NULL)
        return;
    InoderTravels(node->left);
    cout << node->data << " ";
    InoderTravels(node->right);
}
int main()
{
    int inorder[] = {3, 1, 4, 0, 5, 2};
    int preorder[] = {0, 1, 3, 4, 2, 5};
    int n = sizeof(inorder) / sizeof(inorder[0]);
    //cout<<n<<endl;
    Node *node = buildTree(preorder, inorder, n);
    InoderTravels(node);
    return 0;
}