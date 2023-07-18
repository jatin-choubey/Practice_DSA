// Write a program to find the middle of a Linked List.
/*
Input : 1 - 2 - 3 - 4 - 5
output = 3
*/

// Using SLOW, FAST pointers

Node *middleNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}