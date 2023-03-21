// C++ program for different tree traversals
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

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

    cout << node->data << " ";
    /* first recur on left child */
    printInorder(node->left);

    /* then print the data of node */
    //cout << node->data << " ";
    st.push_back(node->data);

    /* now recur on right child */
    printInorder(node->right);

    return st;
}

Node *invertTree(Node *root)
{
    if (root == NULL)
    {
        return root;
    }

      TreeNode* temp;

        temp = root->right;
        root->right = root->left;
        root->left = temp;

        invertTree(root->left);
        invertTree(root->right);

    return root;
}

/* Driver code*/
int main()
{
    // struct Node *root = newNode(1);
    // root->left = newNode(2);
    // root->right = newNode(2);
    // root->left->left = newNode(3);
    // root->left->right = newNode(4);
    // root->right->left = newNode(4);
    // root->right->right = newNode(30);
    // root->right->right->left = newNode(30);
    // root->right->right->left->left = newNode(30);

    struct Node *root = newNode(4);
    root->right = newNode(7);
    root->left = newNode(2);
    root->left->left = newNode(1);
    root->left->right = newNode(3);
    root->right->left = newNode(6);
    root->right->right = newNode(9);

    root = invertTree(root);

    printInorder(root);

    return 0;
}