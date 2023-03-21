#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

struct bstNode
{
    int data;
    bstNode *left;
    bstNode *right;
};

bstNode *newNode(int data)
{
    bstNode *new_Node = new bstNode();

    new_Node->data = data;
    new_Node->left = NULL;
    new_Node->right = NULL;

    return new_Node;
}

int maxIndex(vector<int>&nums, int l, int r) {
    int mx = nums[l];
    int ind = l;

    for (int i = l + 1; i <= r; i++)
    {
        mx = max(mx, nums[i]);
        if(mx == nums[i]) {
            ind = i;
        }
    }

    return ind;
}

bstNode *insert(bstNode *root, int l, int r, vector<int>&nums)
{
    if (l > r )
    {
        return NULL;
    }

    int ind = maxIndex(nums, l, r);

    // cout << l << " "<< r << endl;
    
    if (root == NULL)
    {
        root = newNode(nums[ind]);
    }
    
    root->left = insert(root->left, l, ind - 1, nums);
    root->right = insert(root->right, ind + 1, r, nums);

    return root;
}

bstNode* constructMaximumBinaryTree(vector<int>& nums) {
    bstNode* root = NULL;
    
   return insert(root, 0, nums.size() -1, nums);
}

void printInOrder(bstNode *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    printInOrder(root->left);
    printInOrder(root->right);
}

int main()
{

   vector<int> vec;

   int n, t;

   cout << "Enter the number of elements" << endl;
   cin >> n;

   for (int i = 0; i < n; i++)
   {
        cin >> t;
        vec.push_back(t);
   }

//    int ind = maxIndex(vec, 2, vec.size());

//    cout << "idnex " << ind << endl;
   
   bstNode* res =  constructMaximumBinaryTree(vec);

   printInOrder(res);
   cout << endl;


    return 0;
}