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

bstNode *insert(bstNode *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
    }
    else if (data <= root->data)
    {
        root->left = insert(root->left, data);
    }
    else
    {
        root->right = insert(root->right, data);
    }

    return root;
}

void print(bstNode *root)
{
    if (root == NULL)
    {
        return;
    }

    print(root->left);
    cout << root->data << " ";
    print(root->right);
}

vector<int> helper(vector<int> &arr, int left, int right)
{

    if(left > right) {
        return NULL;
    }

    int mid = (left + right) / 2;

    bstNode *rootNode = newNode(arr[mid]);

    rootNode->left = helper(arr, left, mid - 1);
    rootNode->right = helper(arr, mid + 1, right);

    return rootNode;
}

bstNode *sortedArrayToBST(vector<int> &nums)
{

    if (nums.size() == 1)
        return newNode(nums[0]);
    if (nums.size() == 0)
        return NULL;

    return helper(nums, 0, nums.size() - 1);
}

int main()
{

    bstNode *root = NULL;
    vector<int> vec;

    int p, n;
    cout << "Enter the number of elements" << endl;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p;
        vec.push_back(p);
    }

    sortedArrayToBST(vec);
}