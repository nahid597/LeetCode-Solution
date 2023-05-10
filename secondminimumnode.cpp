#include<iostream>
#include<queue>
#include<set>
#include<iterator>

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

void dfs(TreeNode* root, set<int> &s) {
    if (root == NULL)
    {
        return;
    }

    s.insert(root->val);

    dfs(root->left, s);
    dfs(root->right, s);
        
}

  int findSecondMinimumValue(TreeNode* root) {

        if(root == NULL) {
            return 0;
        }

        set<int> s;

        dfs(root,s);

        if(s.size() < 2) {
            return -1;
        }

        set<int>::iterator itr;
        int cnt = 0, ans = -1;
        for ( itr = s.begin(); itr != s.end(); itr++)
        {
            cnt++;
            if (cnt == 2)
            {
                ans = *itr;
            }
            
        }
        
        return ans;
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

    TreeNode *root = new TreeNode(2);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->right = new TreeNode(2);

    cout << "Printed value" << endl;
    inOrder(root);
    cout << endl;

    int k = 2;

    int res = findSecondMinimumValue(root);

    cout << "final result " << res << endl;

    return 0;
}