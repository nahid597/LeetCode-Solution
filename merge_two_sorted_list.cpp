#include<iostream>

using namespace std;

struct node {
    int data;
    node *next;
};

node *newNode(int data) {
    node *temp = (node*) malloc(sizeof(node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}

node *insert(int data, node *head) {

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

node *insertAtAnyPosition(int data, node *head, node *pos) {
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

void print(node *head) {
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp =  temp->next;
    }
}

node *mergeTowLists(node *list1, node *list2) {
    node *temp = newNode(0);
    node *tail = temp;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data < list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    while (list1 != NULL)
    {
        tail->next = list1;
        list1 = list1->next; 
        tail = tail->next;
    }

     while (list2 != NULL)
    {
        tail->next = list2;
        list2 = list2->next;
        tail = tail->next;
    }

    return temp->next;
    
}

int main() {

    node *head1 = NULL;
    head1 = insert(5,head1);
    head1 = insert(52,head1);
    head1 = insert(58,head1);
    head1 = insertAtAnyPosition(10,head1,head1->next);

    cout << "Before merge list 1" << endl;
    print(head1);
    cout << endl;

    node *head2 = NULL;
    head2 = insert(15,head2);
    head2 = insert(48,head2);
    head2 = insert(52,head2);
    head2 = insertAtAnyPosition(20,head2,head2->next);

    cout << "Before merge list 2" << endl;
    print(head2);
    cout << endl;

    node *head = mergeTowLists(head1, head2);
    cout << "after merge" << endl;
    print(head);
    cout << endl;


    return 0;
}