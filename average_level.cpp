#include<iostream>
#include<vector>
#include<queue>

using namespace std;

 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int val1) {
        val = val1;
        left = right = NULL;
      }
 };

 TreeNode *newNode(int val) {
    TreeNode *temp = new TreeNode(val);

    // temp->val = val;
    // temp->left = temp->right = NULL;

    return temp;
 }


 void printInOrder(struct TreeNode *node)
{
    if (node == NULL)
        return;

    /* first recur on left child */
    printInOrder(node->left);

    /* then print the data of node */
    cout << node->val <<endl;

    /* now recur on right child */
    printInOrder(node->right);
    cout<<endl;
    //return st;
}


vector<double> averageOfLevels(TreeNode* root) {
    queue<TreeNode*> q;
    vector<double>res;
    int sum = 0;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp;
        int sz = q.size();
        sum = 0;

        // q = [15,7]

        for (int i = 0; i < sz; i++)
        {
            temp = q.front();
            q.pop();
            sum += temp->val;

            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }

        double avg = 1.00 * sum / sz;
        cout << avg << endl;
        res.push_back(avg);
        
    }

    return res;
        
}


int main() {

    struct  TreeNode *root =new TreeNode(3);
    root->right =new TreeNode(20);
    root->left =new TreeNode(9);
    root->right->left =new TreeNode(15);
    root->right->right =new TreeNode(7);

    cout << "printed value " <<endl;
    vector<double> res = averageOfLevels(root);

    return 0;
}

