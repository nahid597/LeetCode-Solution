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

bool isMirror(Node *p, Node *q) {
    if(p == NULL && q == NULL) {
        return true;
    }

    if(p == NULL || q == NULL) {
        return false;
    }

    if(p->data != q->data) {
        return false;
    }

    return isMirror(p->left,q->right) && isMirror(p->right, q->left);

}

bool isSymmetric(Node *root)
{
   if(root == NULL) {
    return true;
   }

   return isMirror(root->left, root->right);
   
}

/* Driver code*/
int main()
{
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(30);
   

    bool res = isSymmetric(root);

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