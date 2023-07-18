// Write a program to find the entry point of the linked list cycle.
/*
Input:
1 - 2 - 3 - 4 - 5 - 6 - 7 - 8
            |_______________|

Output : 4

Explaination:
We can see that Linked List Cycle begins from Node 4.
*/

// Approach 1 :: Using External Space
ListNode *detectCycle(ListNode *head)
{
    unordered_set<ListNode *> st; // Using an external Data Structure to store every visited Node.
    ListNode *t = head;
    while (t and t->next)
    {
        if (st.find(t) != st.end()) // If the node was already present in the set data structure, means we are coming back to this node for the second time.
        {
            return t; // Hence it is the entry point of the linked list.
        }
        else
        {
            st.insert(t); // If the node was not found in the set. Means it is not the insertion point.
            t = t->next;
        }
    }
    return NULL;
}

// Approach :: 2 OPTIMAL
Node *firstNode(Node *head)
{
    Node *slow = head, *fast = head;

    // Keep moving SLOW and FAST pointers
    while (true)
    {
        if (fast == NULL || fast->next == NULL) // Return NULL if fast gets on NULL or last Node, means there is no Cycle.
            return NULL;
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // At this point, both SLOW pointer and HEAD will be at same distance from the Intersection point of the linked list.
    Node *start = head;
    while (slow != start) // So, Keep incrementing both Head and Slow pointers till they meet (at Entry or Intersection Point)
    {
        slow = slow->next;
        start = start->next;
    }
    return slow;
}
