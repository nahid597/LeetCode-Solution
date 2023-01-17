#include <iostream>

using namespace std;

struct node
{
    int data;
    node *next;
};

node *newNode(int data)
{
    node *temp = (node *)malloc(sizeof(node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}

node *insert(int data, node *head)
{

    node *new_Node = newNode(data);
    // insert at 1st place
    if (head == NULL)
    {
        head = new_Node;
        return head;
    }

    // insert at end position
    node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = new_Node;

    return head;
}

node *insertAtAnyPosition(int data, node *head, node *pos)
{
    node *new_Node = newNode(data);
    // insert at 1st place
    if (head == NULL)
    {
        head = new_Node;
        return head;
    }

    node *temp = head;

    while (temp->next != NULL && temp->next != pos)
    {
        temp = temp->next;
    }

    new_Node->next = temp->next;
    temp->next = new_Node;

    return head;
}

void print(node *head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

node *helper (node *head, int k) {
    
    if (k == 0)
    {
        return head;
    }
    
    node * current = head;
    node *next = NULL;

    while (current->next->next != NULL)
    {
        current = current->next;
    }

     next = current->next;
     current->next = NULL;

     next->next = head;
     head = next;

     head = helper(head, k-1);

     return head;
}

node *rotateRight(node *head, int k) {
    
     if (head == NULL)
    {
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }
    
    node * current = head;
    int cnt = 0;

    while (current->next->next != NULL)
    {
        current = current->next;
        cnt++;
    }

    k = k % (cnt+2);

    head = helper(head, k);

   return head;
    
}


int main()
{

    node *head1 = NULL;
    head1 = insert(0, head1);
    head1 = insert(1, head1);
    head1 = insert(2, head1);
    head1 = insert(5, head1);
    head1 = insert(6, head1);
   //  head1 = insert(7, head1);
    // head1 = insert(7, head1);
    // head1 = insert(8, head1);
    // head1 = insert(8, head1);
    // head1 = insert(3, head1);
    // head1 = insert(3, head1);
    // head1 = insertAtAnyPosition(10,head1,head1->next);

    cout << "Enter number of rotate" << endl;
    int k;
    cin >> k;

    cout << "Before rotate" << endl;
    print(head1);
    cout << endl;

    head1 = rotateRight(head1, k);
    cout << "after delete" << endl;
    print(head1);
    cout << endl;

    return 0;
}