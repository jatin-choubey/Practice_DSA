/*
Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.

List = 1 -> 4 -> 3 -> 2 -> 5 -> 2     x = 3

ans = 1 -> 2 -> 2 -> 4 -> 3 -> 5


All the list values lesser than 'x' go on left and all the values greater than or equal to 'x' go on right.

*/

class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *lesser = new ListNode(-1);
        ListNode *greater = new ListNode(-1);

        ListNode *lsr = lesser;  // Pointer to get all the smaller elements.
        ListNode *grt = greater; // Pointer to get all the greater elements.

        ListNode *temp = head;

        while (temp != NULL)
        {
            if (temp->val < x)
            {
                lsr->next = temp;
                lsr = lsr->next;
            }
            else
            {
                grt->next = temp;
                grt = grt->next;
            }
            temp = temp->next;
        }
        lsr->next = greater->next;
        grt->next = NULL;

        return lesser->next;
    }
};