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



vector<vector<int> >levelOrder(Node *root)
{
    vector<vector<int> > res;

    if (root == NULL)
    {
        return res;
    }

    vector<int> vec;
    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int x = q.size();

        for (int i = 0; i < x; i++)
        {
            Node *front = q.front();
            vec.push_back(front->data);
            cout << front->data << " ";
            if(front->left != NULL) q.push(front->left);
            if(front->right != NULL) q.push(front->right);
            q.pop();
        }

        res.push_back(vec);
    }

    return res;
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

   // printInorder(root);

   vector<vector<int> > rs = levelOrder(root);

    return 0;
}