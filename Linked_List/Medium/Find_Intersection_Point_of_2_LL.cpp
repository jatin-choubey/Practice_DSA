// Write a program to find the intersection point of 2 linked lists (If present)
/*
Input:
1----2----3----4
                \
                5----6-NULL
         1----2/

Output: 5

Explaination:
Intersection point of two linked lists is 5.
*/

/* Approach 1 ::
 Check each and every Node of Linked List 1
 with every Node of Linked List 2.
 TC = O(M*N), SC = O(1) */

/* Approach 2 ::
Store the nodes of linked list 1 in an
unordered_set and then start finding the nodes of linked list 2
in that unordered_set. If found, return the Node.
TC = O(N + M), SC = O(N) */

// (Optimal)APPROACH 3 :: Find the size of both linked lists.
// TC = O(2N), SC = O(1)

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    long long int size1 = 0, size2 = 0;
    ListNode *track1 = headA;
    ListNode *track2 = headB;
    while (track1 != NULL || track2 != NULL) // Find the size of Both the linked lists
    {
        if (track1 != NULL)
        {
            size1++;
            track1 = track1->next;
        }
        if (track2 != NULL)
        {
            size2++;
            track2 = track2->next;
        }
    }

    // If size of linked list 1 is greater than size of linked list 2, swap the head pointers of both linked list.
    // Basically, this step is to make sure that the HeadA is always the head of the smaller linked list.
    if (size1 > size2)
        swap(headA, headB);

    int diff = abs(size1 - size2); // Find the difference between the sizes.

    // Move the HeadB no its next for 'diff' times.
    // Basically, this step will make sure that both the HeadA and HeadB are at same distance from the Intersection point of the linked list.
    for (int i = 0; i < diff; i++)
        headB = headB->next;

    // Now keep moving both the HeadA and HeadB till they are found equal on any point. This is the intersection point.
    // Or they reach NULL, in which case, No intersection Node was found.
    while (headA && headB && headA != headB)
    {
        headA = headA->next;
        headB = headB->next;
    }

    return headA; // You can return either of HeadA and HeadB.
}

// (Optimal) APPROACH 4 :: Two Pointer
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    while (p1 != p2) // P1 and P2 will eventually meet
    {
        if (p1 != NULL) // Keep moving Pointer 1 till its not equal to NULL.
            p1 = p1->next;
        else
            p1 = headB; // Once it is at NULL, put it on Head of another linked list (ie HeadB)

        if (p2 != NULL) // Keep moving Pointer 2 till its not equal to NULL.
            p2 = p2->next;
        else
            p2 = headA; // Once it is at NULL, put it on Head of another linked list (ie HeadA)
    }
    return p1;
}
