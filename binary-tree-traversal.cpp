// C++ program for different tree traversals
#include <iostream>
#include <vector>

using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
struct Node
{
    int data;
    struct Node *left, *right;
};

// Utility function to create a new tree node
Node *newNode(int data)
{
    Node *temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

/* Given a binary tree, print its nodes in inorder*/
vector<int> st;

vector<int> printInorder(struct Node *node)
{
    if (node == NULL)
        return st;

    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    cout << node->data << " ";
    st.push_back(node->data);

    /* now recur on right child */
    printInorder(node->right);

    return st;
}

bool isSameTree(Node *p, Node *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }

    if (p == NULL && q != NULL)
    {
        return false;
    }

    if (p != NULL && q == NULL)
    {
        return false;
    }

    bool res = false;
    if (p->data == q->data)
    {
        res = true;
    }

    return res && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}

/* Driver code*/
int main()
{
    struct Node *root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);

    struct Node *root1 = newNode(10);
    root1->left = newNode(5);
    root1->left->right = newNode(15);

    bool res = isSameTree(root, root1);

    if (res)
    {
        cout << "Two trees are same" << endl;
    }
    else
    {
        cout << "Two trees are not same" << endl;
    }

    return 0;
}