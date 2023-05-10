#include<iostream>
#include<queue>

using namespace std;

struct  TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int val1) {
        val = val1;
    }
};

int cnt = 0,result = 0;

int kthSmallest(TreeNode* root, int k) {
    if (root == NULL)
    {
        return 0;
    }

    kthSmallest(root->left, k);
    cnt++;
    if (cnt == k)
    {
        result = root->val;
        return result;
    }

    kthSmallest(root->right, k);

    return result;
        
}

void inOrder (TreeNode *root) {
    if (root == NULL)
    {
        return;
    }

    inOrder(root->left);
    cout << root->val << " ";
    inOrder(root->right);
}



int main() {

    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);

    cout << "Printed value" << endl;
    inOrder(root);
    cout << endl;

    int k = 2;

    int res = kthSmallest(root, k);

    cout << "final result " << res << endl;

    return 0;
}