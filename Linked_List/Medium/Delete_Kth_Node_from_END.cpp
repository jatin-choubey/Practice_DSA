// Write a program to Delete the Kth node from the back of the linked list.
/*
Input : 1 - 2 - 3 - 4 - 5 - 6
K : 3

Output : 1 - 2 - 3 ---- 5 - 6

Explaination : We removed the Node '4' form the LL, as it was 3rd node from back.
*/

// Approach 1 : (BRUTE FORCE)
/*
Calculate the 'size' of the LL and delete the (size - K + 1)th node from start.
*/
ListNode *removeNthFromEnd(ListNode *head, int k)
{
    ListNode *t = head;
    int size = 0;
    while (t != NULL)
    {
        t = t->next;
        size++;
    }
    if (k == size) // If the size of the LL is equal to 'K', means the Head node is to be deleted.
        return head->next;

    ListNode *prev = head;

    // Move the previous pointer till one position before the 'Kth' node
    for (int i = 1; i < size - k; i++)
    {
        prev = prev->next;
    }

    // Point prev's next to its next's next, leaving behind prev's actual next, which was the Kth node.
    prev->next = prev->next->next;

    return head;
}

// Approach : 2 (Optimal Approach)
// Using Front and Back pointers

ListNode *removeNthFromEnd(ListNode *head, int K)
{
    // Make a dummy node and attach it to head
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;

    ListNode *front = dummy; // Place front pointer at dummy node.
    ListNode *back = dummy;  // Place back pointer at dummy node.

    // Move the front pointer K times.
    for (int i = 0; i < K; i++)
    {
        front = front->next;
    }

    // By the end of previous loop, there would a 'K' size difference between Front and Back pointer

    while (front->next != NULL) // Move both the pointers till front pointer reaches the last node.
    {
        front = front->next;
        back = back->next;
    }

    // Point back's next to its next's next. leaving behind back's actual next, which was the Kth node.
    back->next = back->next->next;

    return dummy->next;
}