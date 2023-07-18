// Write a program to Merge multiple sorted linked lists.

/* l1 = 1 -> 3 -> 5
   l2 = 2 -> 5
   l3 = 1 -> 4 -> 6

   ans : 1 -> 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6

   The idea is to first merge the linked lists l1 and l2 to form a new linked list (say 'merged'), and then
   merge the 'merged' linked list and l3.
*/

ListNode *merge(ListNode *l1, ListNode *l2) // Merge the Two Linked Lists.
{
    ListNode *dummy = new ListNode();
    ListNode *temp = dummy;
    while (l1 && l2)
    {
        if (l1->val <= l2->val)
        {
            temp->next = l1;
            l1 = l1->next;
            temp = temp->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
            temp = temp->next;
        }
    }

    if (l1)
        temp->next = l1;
    else
        temp->next = l2;

    return dummy->next;
}

ListNode *mergeKLists(vector<ListNode *> &lists)
{

    if (lists.size() == 0)
        return NULL;

    ListNode *l1 = NULL;         // To store one of the two linked lists.
    ListNode *l2 = NULL;         // To store one of the two linked lists.
    ListNode *merged = lists[0]; // Initially consider the first list as a merged list.

    for (int i = 1; i < lists.size(); i++)
    {
        l1 = merged;
        l2 = lists[i];
        merged = merge(l1, l2);
    }
    return merged;
}