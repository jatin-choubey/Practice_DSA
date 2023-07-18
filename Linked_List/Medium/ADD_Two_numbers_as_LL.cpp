// Write a program to add two numbers as Linked lists from left to right
/*
    L1 :  1 - 5 - 4
    L2 :  4 - 8 - 7 - 9

  ANS  : 5 - 3 - 2 - 0 - 1

*/

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = nullptr; // Head pointer of the resulting linked list
    int carry = 0;            // Carry value for addition

    // Continue the loop until there are nodes in either list or there is a carry value
    while (l1 != nullptr || l2 != nullptr || carry != 0)
    {
        int sum = 0; // Variable to store the sum of current digits

        // Add the values of the corresponding nodes in list l1 and l2 (if they exist)
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

        sum += carry;       // Add the carry value to the sum
        carry = sum / 10;   // Update the carry value for the next addition
        int add = sum % 10; // Compute the value to be added to the new linked list

        ListNode *neww = new ListNode(add); // Create a new node for the sum digit

        if (head == nullptr)
        {
            head = neww; // If head is NULL, assign the new node as the head
        }
        else
        {
            ListNode *temp = head;

            // Find the last node in the linked list
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = neww; // Append the new node to the last node
        }

        neww->next = nullptr; // Set the next pointer of the new node to NULL
    }

    return head; // Return the head pointer of the resulting linked list
}