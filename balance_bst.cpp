// C++ program for different tree traversals
#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>

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

//   1
//  /  \
// 2    3

int maxDepth(Node* root) {
    if (root == NULL)
    {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right)); 
    
}

int height(Node* root) {
    if (root == NULL)
    {
        return 0;
    }

    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }

    return 1 + max(height(root->left),height(root->right)); 
    
}

bool isBalanced(Node* root) {
     if(root == NULL) {
        return true;
     } 

     if(abs(height(root->left) - height(root->right)) > 1) {
        return false;
     }

    return isBalanced(root->left) && isBalanced(root->right); 
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

    struct  Node *root = newNode(1);
    root->right = newNode(2);
    root->right->right = newNode(3);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(5);
    

   // printInorder(root);

   bool rs = isBalanced(root);
   // int rs = height(root);

   cout << rs << endl;

    return 0;
}