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

  node *detectCycle(node *head) {

        if(head == NULL) {
            return NULL;
        }

        if (head->next == head)
        {
            return head;
        }
        

        node *result = NULL;
        node *current = head;
        node *next = head;
        node *entry = head;
        // 1 2 3 4 6 7 8 9 

        while (current && current->next != NULL && next && next->next && next->next->next != NULL)
        {

            if (current == next)
            {
                while (entry != current)
                {
                    current = current->next;
                    entry = entry->next;
                }

                result = current;
                return result;
            } 

            current = current->next;
            next = next->next->next; 

        }

        return result;
        
    }

int main() {

    node *head = NULL;
    head = insert(1,head);
    //head = insert(2,head);
    // head = insert(3,head);
    // head = insert(8,head);
     head = createCycle(head, 4, head);

    // cout << endl;

     head = detectCycle(head);
     if (head)
     {
        cout << head->data << endl;
     } else {
        cout << "no cycle" << endl;
     }
     
     


    return 0;
}