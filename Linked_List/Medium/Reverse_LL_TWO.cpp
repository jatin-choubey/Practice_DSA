/*
Given the head of a singly linked list and two integers left and right where left <= right,
reverse the nodes of the list from position left to position right, and return the reversed list.

list = 1 -> 2 -> 3 -> 4 -> 5
left = 2, right = 4

anss = 1 -> 4 -> 3 -> 2 -> 1

*/

class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode *dummy = new ListNode(-1), *pre = dummy, *cur;
        dummy->next = head;

        for (int i = 0; i < left - 1; i++)
            pre = pre->next;

        cur = pre->next;

        for (int i = 0; i < right - left; i++)
        {
            ListNode *temp = pre->next;
            pre->next = cur->next;
            cur->next = cur->next->next;
            pre->next->next = temp;
        }
        return dummy->next;
    }
};