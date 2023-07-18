// Write a program to reverse a linked list in 'K' groups
/*
Input:
LL : 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> NULL
K : 3

Output :
LL : 3 -> 2 -> 1 -> 6 -> 5 -> 4 -> 7 -> 8 -> NULL

Explaination :
'K' is given as 3. So, we reverse every 3 nodes of the linekd list.
*/

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *t = head;
    int size = 0;
    while (t != NULL) // Find SIZE of the linked list.
    {
        size++;
        t = t->next;
    }

    ListNode *dummy = new ListNode(); // Making a Dummy Node
    dummy->next = head;               // and placing it before head.

    ListNode *pre = dummy; // Using three pointers to reverse each link.
    ListNode *cur = dummy;
    ListNode *nxt = dummy;

    while (size >= k) // We only go for reversing if the elements left out to be reversed is greater than or equal to 'K'
    {
        cur = pre->next; // Placing Current node to Previous node's next before every iteration.
        nxt = cur->next; // Placing Next node to Current node's next before every iteration.

        for (int i = 0; i < k - 1; i++) // We run a loop for 'k - 1' times because when we want to reverse 'K' nodes, we will have to reverse 'k - 1' links one by one;
        {
            cur->next = nxt->next; // These 4 steps are VERY VERY IMPORTANT.
            nxt->next = pre->next;
            pre->next = nxt;
            nxt = cur->next;
        }
        size -= k; // Reduce the size of the linked list by 'K', as we have reversed K elements already.
        pre = cur; // Placing the Previous pointer for next iteration to Current.
    }
    return dummy->next; // Return Dummy's next.
}