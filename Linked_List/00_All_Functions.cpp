#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};

void insertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    else
    {
        node *temp = head;
        head = n;
        n->next = temp;
    }
}

void insertAtPosition(node *&head, int val, int pos)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *i = head;
    node *j = i->next;
    // pos = 4
    // 4 - 1 = 3
    // 1, 2
    for (int num = 1; num < pos - 1; num++)
    {
        i = i->next;
        j = j->next;
    }
    i->next = n;
    n->next = j;
}

void deleteAtPosition(node *&head, int pos)
{
    // 1 2 3 4 5 6 7
    // Delete position 5
    // 1 2 3 4 6 7
    if (head == NULL)
    {
        cout << "Nothing to be deleted\n";
        return;
    }
    else if (head->next == NULL or pos == 1)
    {
        head = head->next;
        return;
    }

    node *p = head;
    node *n = p->next;
    for (int i = 1; i < pos - 1; i++)
    {
        p = p->next;
        n = n->next;
    }
    p->next = n->next;
    delete n;
}

void display(node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    node *head = NULL;
    cout << "Enter the number to be inserted in the Linked List\n";
    string input;
    while (true)
    {
        cin >> input;
        if (input != "x")
        {
            int n = stoi(input);
            insertAtTail(head, n);
        }
        else
        {
            break;
        }
    }

    // insertAtHead(head, 100);

    // insertAtPosition(head, 0, 5);

    // deleteAtPosition(head, 1);

    display(head);

    return 0;
}