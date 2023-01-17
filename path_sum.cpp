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

vector<vector<int> > res;

bool helper(Node* root, int targetSum, bool flag, vector<int>st) {
        if(root==NULL) {
            return false;
        }

        if(root->left == NULL && root->right == NULL) {
            flag = true;
        }

        targetSum -= root->data;
        st.push_back(root->data);

        if(targetSum == 0 && flag) {
            res.push_back(st);

            return true;
        }

        // cout <<root->data << " " <<targetSum << endl;

        bool a = helper(root->left, targetSum, flag,st);
        bool b = helper(root->right,targetSum, flag,st);
        targetSum += root->data;
        st.pop_back();
        // flag = false;

        return a || b;
    }

 vector<vector<int> > hasPathSum(Node* root, int targetSum) {
    bool flag = false;
    vector<int>vec;
    helper(root, targetSum, flag,vec);
    return res;
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
    root->left = newNode(9);
    root->right->right = newNode(3);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(4);

    int t;

    cout << "Enter the target number"<< endl;

    cin >> t;
    

   // printInorder(root);

   vector<vector<int> >  rs = hasPathSum(root,t);
   // int rs = height(root);

    for (int i = 0; i < rs.size(); i++)
    {
        for (int j = 0; j < rs[i].size(); j++)
        {
           cout << rs[i][j] << " ";
        }
        cout << endl; 
    }
    
    return 0;
}