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

node *deleteNode(node *head, int data) {
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

node *reverse(node *head,int l, int r) {
    node *prev = NULL;
    node *next;
    node *temp = head;
    node *newList = newNode(0);
    node *st = newList;

    int cnt = 1;

    while (temp != NULL && cnt != l)
    {
        cnt++;
        st->next = temp;
        st = st->next;
        temp = temp->next;
    }
    

    while (temp != NULL && cnt<= r)
    {
       cnt++;
       next = temp->next;
       temp->next = prev;
       prev = temp;
       temp = next;
    }

    while (prev != NULL)
    {
        st->next = prev;
        st = st->next;
        prev =  prev->next;
    }

    while (temp != NULL)
    {
        st->next = temp;
        st = st->next;
        temp =  temp->next;
    }
    

    return newList->next;
}

void print(node *head) {
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp =  temp->next;
    }
}

int main() {

    node *head = NULL;
    head = insert(1,head);
    head = insert(2,head);
    head = insert(3,head);
    head = insert(4,head);
    head = insert(5,head);
    //head = insertAtAnyPosition(10,head,head->next->next);

    cout << "Before delete " << endl;
    print(head);
    cout << endl;

    int l = 2, r = 4;

    head = reverse(head, l, r);
     cout << "after Reverse " << endl;
     print(head);
     cout << endl;

    // head = deleteNode(head, 5);
    // head = deleteNode(head, 5);
    // head = deleteNode(head, 5);

    // cout << "after delete " << endl;
    // print(head);
    // cout << endl;

    return 0;
}