/*
Remove Duplicates from SORTED LIST II
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct
numbers from the original list. Return the linked list sorted as well.

EXAMPLE

Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
*/

// APPROACH 1 ---- MY THNKING
class Solution
{
public:
    // Function to delete duplicates from sorted linked list
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Check if the list is empty or has only one node
        if (head == NULL || head->next == NULL)
            return head;

        // Create a dummy node and point it to the head of the list
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // Initialize pointers for traversal and tracking
        ListNode *temp = dummy; // temp points to the last non-duplicate node
        ListNode *st = head;    // st points to the start of potential duplicates
        ListNode *en = head;    // en is used to explore potential duplicates
        int count = 0;          // count keeps track of duplicate nodes

        // Traverse through the linked list
        while (en != NULL)
        {
            // Check if the current node has the same value as the start node
            if (en != NULL && st->val == en->val)
            {
                count++;       // Increment the duplicate count
                en = en->next; // Move en to the next node
                continue;      // Continue to the next iteration
            }

            // If only one instance of the value is found, link it to the temp node
            if (count == 1)
            {
                temp->next = st;   // Link the last non-duplicate node to the current node
                temp = temp->next; // Move temp to the current node
                st = en;           // Update st to the next potential start
                count = 0;         // Reset the duplicate count
            }

            // If the values are different or duplicates are handled, update pointers
            if (en != NULL && st->val != en->val)
            {
                count = 0; // Reset the duplicate count
                st = en;   // Update st to the new potential start
            }
        }

        // Handle cases where the last node is non-duplicate or duplicate
        if (count == 1)
            temp->next = st; // Link last non-duplicate node
        else
        {
            st = en;         // Update st to en (for last duplicate node)
            temp->next = st; // Link last duplicate node or NULL
        }

        // Return the sorted linked list starting from dummy's next node
        return dummy->next;
    }
};

// APPROACH 2 ----

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        // Create a dummy node and point it to the head of the list
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        // Pointer for traversal and connection
        ListNode *temp = dummy;

        // Traverse the list
        while (temp->next && temp->next->next)
        {
            // Check if the current node has a duplicate
            if (temp->next->val == temp->next->next->val)
            {
                int duplicateVal = temp->next->val;

                // Remove all consecutive duplicates
                while (temp->next && temp->next->val == duplicateVal)
                {
                    temp->next = temp->next->next;
                }
            }
            else
            {
                // Move to the next node
                temp = temp->next;
            }
        }

        // Return the sorted linked list starting from dummy's next node
        return dummy->next;
    }
};
