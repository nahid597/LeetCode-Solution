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

node *deleteDuplicates(node *head)
{
    node *temp = head;
    node *str = NULL;

    if (head == NULL)
    {
        return head;
    }
    

    while (temp->next != NULL)
    {
        if (temp->data == temp->next->data)
        {
            str = temp->next;

            if (str->next == NULL)
            {
                temp->next = NULL;
                free(str);
                return head;
            }

            temp->next = temp->next->next;
            free(str);
           // temp = temp->next;
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
}
int main()
{

    node *head1 = NULL;
    head1 = insert(1, head1);
    head1 = insert(1, head1);
    head1 = insert(1, head1);
    head1 = insert(2, head1);
    head1 = insert(3, head1);
    // head1 = insert(3, head1);
    // head1 = insert(3, head1);
    // head1 = insertAtAnyPosition(10,head1,head1->next);

    // cout << "Before merge list 1" << endl;
    // print(head1);
    // cout << endl;

    head1 = deleteDuplicates(head1);
    cout << "after delete" << endl;
    print(head1);
    cout << endl;

    return 0;
}