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

node *deleteNode(node *head, int data)
{
    cout << "data " << data << endl;
    if (head->data == data)
    {
        node *temp = head;
        head = head->next;
        free(temp);

        return head;
    }

    node *temp = head;

    while (temp->next->data != data)
    {
        temp = temp->next;
    }

    node *stor = temp->next;

    if (stor->next == NULL)
    {
        temp->next = NULL;
        free(stor);
        return head;
    }

    temp->next = temp->next->next;
    free(stor);

    return head;
}

node *deleteDuplicates(node *head)
{
    node *temp = head;
    node *next = NULL;
    node *pre = NULL;
    node *stdummy = NULL;
    node *str = NULL;

   node *temp1 = newNode(0);
   node *dummy = temp1;

    if (head == NULL)
    {
        return head;
    }

    if (head->next == NULL)
    {
        return head;
    }
    

    while (temp->next != NULL)
    {
        // 1 1 1 2 2 4 6 6
        // 1 2
        next = temp->next;

        if (pre == NULL)
        {
            if (temp->data != next->data)
            {
                str = newNode(temp->data);
                dummy->next = str;
                dummy = dummy->next;
            }
        }
        else
        {
            if (temp->data != pre->data && temp->data != next->data)
            {
                str = newNode(temp->data);
                dummy->next = str;
                dummy = dummy->next;
            }
            
        }

        pre = temp;
        temp = temp->next;
    }

    if (pre != NULL && temp->data != pre->data)
    {
         dummy->next = temp;
         dummy = dummy->next;
    }
    
    

    return temp1->next;
}

int main()
{

    node *head1 = NULL;
    head1 = insert(1, head1);
    head1 = insert(1, head1);
    head1 = insert(1, head1);
    head1 = insert(2, head1);
    head1 = insert(2, head1);
    head1 = insert(4, head1);
    head1 = insert(5, head1);
    head1 = insert(6, head1);
    head1 = insert(6, head1);
    // head1 = insert(6, head1);
     head1 = insert(7, head1);
    // head1 = insert(7, head1);
    // head1 = insert(8, head1);
    // head1 = insert(8, head1);
    // head1 = insert(3, head1);
    // head1 = insert(3, head1);
    // head1 = insertAtAnyPosition(10,head1,head1->next);

    cout << "Before merge list 1" << endl;
    print(head1);
    cout << endl;

    head1 = deleteDuplicates(head1);
    cout << "after delete" << endl;
    print(head1);
    cout << endl;

    return 0;
}