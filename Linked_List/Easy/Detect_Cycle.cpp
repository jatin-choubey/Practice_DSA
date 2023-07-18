// Write a program to detect if there exists a cycle in the LL
/*
Input : 1 - 2 - 3 - 4 - 5 - 6 - 7 - 8
                    |_______________|
Output : true

Input : 1 - 2 - 3 - 4 - 5
output : false
*/

// Approach 1 : Using External data structure
bool hasCycle(ListNode *head)
{
    unordered_set<ListNode *> st; // Using an external Data Structure to store every visited Node.
    ListNode *t = head;
    while (t and t->next)
    {
        if (st.find(t) != st.end()) // If the node was already present in the set data structure, means we are coming back to this node for the second time.
        {
            return true; // Hence it is the entry point of the linked list.
        }
        else
        {
            st.insert(t); // If the node was not found in the set. Means it is not the insertion point.
            t = t->next;
        }
    }
    return false;
}

// Approach 2 : Using Slow, Fast pointers (Optimal)
bool hasCycle(ListNode *head)
{
    ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) // If at any point the pointers collide, return true
            return true;
    }
    return false;
}