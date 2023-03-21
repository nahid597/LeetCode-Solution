#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>

using namespace std;

struct  TreeNode
{
    int val;
    TreeNode *left, *right;

};

TreeNode *newNode(int val) {
    TreeNode *temp = new TreeNode();
    temp->val = val;
    temp->left = temp->right = NULL;

    return temp;
}

void printInOrder(TreeNode *root) {
    if(root == NULL) {
        return;
    }

    cout << root-> val << " ";
    printInOrder(root->left);
    printInOrder(root->right);
}

int leftSum (TreeNode *root, int sum) {
    if (root == NULL)
    {
        return sum;
    }

   if(root->left == NULL && root->right == NULL) {
        sum += root->val;
    }

    return sum;

}

int bfs(TreeNode *root, int sum) {
    if (root == NULL)
    {
        return sum;
    }

   sum = bfs(root->left, sum);
   sum = bfs(root->right, sum);
   sum = leftSum(root->left,sum);

   return sum;
    
}

int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL)
    {
       return 0;
    }

    if(root->left == NULL && root->right == NULL) {
        return 0;
    }

   int sum = 0;

   sum = bfs(root, sum);

   return sum;

     
}

int main() {
    struct  TreeNode *root = newNode(3);
    root->left =  newNode(9);
    root->right =  newNode(20);
    root->right->left =  newNode(15);
    root->right->right =  newNode(7);

    cout << "Printed valued" << endl;

    int res = sumOfLeftLeaves(root);

    cout <<res << endl;
    
}
