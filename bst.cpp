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

bool search(bstNode *root, int data)
{

    if (root == NULL)
    {
        return false;
    }
    else if (root->data == data)
    {
        return true;
    }
    else if (data <= root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

bstNode* minNode(bstNode *root) {
    if (root->left == NULL)
    {
        return root;
    }

    return minNode(root->left);
}

bstNode *deleteNode(bstNode *root, int data)
{

    if (root == NULL)
    {
        return root;
    }
    else if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        // if root has no child
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }
        // if root has one child
        else if (root->left == NULL)
        {
            bstNode *temp = root;
            root = root->right;
            delete temp;
        }
        else if (root->right == NULL)
        {
            bstNode *temp = root;
            root = root->left;
            delete temp;
        }
        // if root has two child
        else {
            bstNode *temp = minNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

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

int main()
{

    bstNode *root = NULL;
    root = insert(root, 15);
    root = insert(root, 10);
    root = insert(root, 26);
    root = insert(root, 6);
    root = insert(root, 35);
    root = insert(root, 5);

    int n;

    cout << "Enter the delete number" << endl;

    cin >> n;

    cout << "List of Numbers" << endl;

    print(root);

    cout << endl;

    root = deleteNode(root, n);

    cout << "List of Numbers after deleted" << endl;

    print(root);

    cout << endl;

    //  cout << "Minimum value" << endl;

    // int mn =  minValue(root);

    // cout << mn << endl;

    // bool res = search(root, n);

    // if (res)
    // {
    //     cout << "Found the number" << endl;
    // }
    // else
    // {
    //     cout << "Not found the number" << endl;
    // }

    return 0;
}