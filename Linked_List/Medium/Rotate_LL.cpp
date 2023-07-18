// Write a program to rotate the list to the right by 'K' places.
/*
L : 0 - 1 - 2
K = 4

output : 2 - 0 - 1

Explaination:
After 1st rotation: 2 - 0 - 1
After 2nd rotation: 1 - 2 - 0
After 3rd rotation: 0 - 1 - 2
After 4th rotation: 2 - 0 - 1
*/

// If the Value of k_new is equivalent to the size of the List, we will
// give us the actual list.

// See in the above given example, the linked list gets repeated at 3rd iteration as the size was 3.

ListNode *rotateRight(ListNode *head, int k)
{
    // Check for base cases
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Calculate the size of the list
    ListNode *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        size++;
    }

    // Reduce k to its equivalent value within the size of the list
    // Suppose size = 5, and k = 18. Then LL will repeat itself at k = 5, k = 10 and k = 15. So k_new is (18 % 5) ie '3'
    int k_new = k % size;

    // If k_new becomes 0, the list remains unchanged
    if (k_new == 0)
        return head;

    // Create a dummy node and make it point to the head
    ListNode *dummy = new ListNode();
    dummy->next = head;

    temp = dummy;

    // Move temp k_new steps forward
    for (int i = 0; i < k_new; i++)
        temp = temp->next;

    ListNode *back = dummy;

    // Move both back and temp until temp reaches the end of the list
    while (temp->next != NULL)
    {
        back = back->next;
        temp = temp->next;
    }

    // Set the new head to the node next to back
    ListNode *newHead = back->next;
    back->next = NULL;

    // Connect the end of the original list to the original head
    temp->next = head;

    // Return the new head of the rotated list
    return newHead;
}
