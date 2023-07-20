// Write a program to add two numbers as Linked lists from left to right
/*
    L1 :  1 - 5 - 4
    L2 :  4 - 8 - 7 - 9

  ANS  : 5 - 3 - 2 - 0 - 1

*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // Create a dummy node to start building the result linked list.
    ListNode *dummy = new ListNode(-1);
    // Create a pointer 'temp' to traverse the new linked list.
    ListNode *temp = dummy;
    // Initialize 'carry' to handle any carryover from addition.
    int carry = 0;

    // Continue the loop until both input linked lists 'l1' and 'l2' are empty,
    // and there's no carry left to handle.
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        // Initialize 'sum' to hold the sum of digits at the current position.
        int sum = 0;

        // Add the values of 'l1' and 'l2' if they are not nullptr.
        if (l1 != nullptr)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != nullptr)
        {
            sum += l2->val;
            l2 = l2->next;
        }

        // Add any carry value from the previous iteration to 'sum'.
        sum += carry;

        // Calculate the new carry value for the next iteration.
        carry = sum / 10;

        // Create a new node to hold the current digit and attach it to the result linked list.
        ListNode *newNode = new ListNode(sum % 10);
        temp->next = newNode;

        // Move 'temp' to the next position in the result linked list.
        temp = temp->next;
    }

    // Return the head of the result linked list, skipping the dummy node.
    return dummy->next;
}
