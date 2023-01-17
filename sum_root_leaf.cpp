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

int sum = 0, st2 = 0;

int sumNumbers(Node* root) {
    if (root == NULL )
    {
       return 0;  
    }

    st2 = (st2 * 10) + root->data;

    if (root->left == NULL && root->right == NULL)
    {
        int s = st2;
        cout << "st2 = " << st2 << endl;
        st2 = st2 / 10;
       return s;  
    }


   int a = sumNumbers(root->left);
   int b = sumNumbers(root->right);
   st2 = st2 / 10;

   cout << a << " " << b << endl;



   sum = a + b;

   return sum;
        
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

    struct  Node *root = newNode(4);
    root->right = newNode(0);
    root->left = newNode(9);
    root->left->left = newNode(5);
    root->left->right = newNode(1);
    // root->right->right = newNode(3);
    // root->right->right->left = newNode(4);
    // root->right->right->right = newNode(4);

  
   int res = sumNumbers(root);

   cout << res << endl;

    return 0;
}