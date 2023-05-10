#include<iostream>
#include<queue>
#include<cmath>

using namespace std;

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node(int val1) {
    val = val1;
  }
};

Node* connect(Node *root) {

    if (root == NULL)
    {
        return NULL;
    }

    Node *current = root;

    while (current!= NULL)
    {
        Node *dummy = new Node(0);
        Node *temp = dummy;

        while (current != NULL)
        {
             if (current->left != NULL)
             {
                temp->next = current->left;
                temp = temp->next;
             }

             if (current->right != NULL)
             {
                temp->next = current->right;
                temp = temp->next;
             }

             current = current->next;
             
        }

        current = dummy->next;

    }

    return root;
    
}

void printInOrder(Node *root) {
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->next);
    cout << root->val << endl;
    
}

int main() {

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    root = connect(root);


    return 0;
}