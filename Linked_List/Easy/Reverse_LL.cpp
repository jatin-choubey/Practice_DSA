// Write a Program to reverse the given Linked List.
/*
Input : 1 - 2 - 3 - 4 - 5 - NULL

Output : 5 - 4 - 3 - 2 - 1 - NULL
*/

/* Approach 1 :
Store Elements of Linked List in an Array.
Reverese the array.
And make new Linked List from that array
*/

// Approach 2 : Rearrange the given linked list

ListNode *reverseLinkedList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *nxtt = head;

    while (curr != NULL)
    {
        nxtt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxtt;
    }
    return prev;
}