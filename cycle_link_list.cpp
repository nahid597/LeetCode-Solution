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

node *createCycle(node *head, int data, node *pos) {
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
    new_Node->next = pos;
    
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

 bool hasCycle(node *head) {

        if(head == NULL || head->next == NULL) {
            return false;
        }

        bool result = false;
        node *current = head;
        node *next = head->next;
        // 1 2 3 4


        while (current && current->next != NULL && next && next->next && next->next->next != NULL)
        {
            if (current == next)
            {
                result = true;
                break;
            }

            current = current->next;
            next = next->next->next;  
        }

        return result;
        
    }

int main() {

    node *head = NULL;
    head = insert(1,head);
    head = insert(2,head);
    head = insert(3,head);
    head = insert(58,head);
    head = createCycle(head, 52, head->next);

    // cout << " list ements "<< endl;
    // print(head);

    // cout << endl;

    bool res = hasCycle(head);

    cout << res << endl;


    return 0;
}