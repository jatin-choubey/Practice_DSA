// Write a program to check if the given Linked List is Palindrome or Not.
/*
Input : 1 - 2 - 2 - 3 - 2 - 2 - 1
Output : True

Input : 1 - 2 - 3 - 3 - 2 - 2
Output : False
*/

LinkedListNode<int> *reverseLL(LinkedListNode<int> *head)
{
    LinkedListNode<int> *prev = NULL, *next = NULL;
    while (head != NULL)
    {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool isPalindrome(LinkedListNode<int> *head)
{
    if (head == NULL || head->next == NULL)
        return true;
    LinkedListNode<int> *fast = head, *slow = head;

    // Keep moving both fast and slow pointers till the FAST pointer reaches the last Node or Second Last node.
    /*
    We stop at last and second last node (*instead of Null or last Node*) because we want our slow pointer
    to end at either exact middle element (in odd sized LL) or on the lower side (in even sized LL).
    ie in LL : 1 2 3 4 5 6, i want the slow pointer to end at node 3 instead of node 4.
    */
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseLL(slow->next); // reverse the seocnd half of the LL.
    LinkedListNode<int> *p2 = slow->next;
    LinkedListNode<int> *p1 = head;
    // Compare all elements of two halves one by one
    while (p2 != NULL)
    {
        if (p2->data != p1->data) // return false if they are not equal.
            return false;
        p1 = p1->next;
        p2 = p2->next;
    }
    return true;
}

// Approach : 2 : Using external Stack Space.
bool isPalindrome(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return true;

    ListNode *slow = head;
    ListNode *fast = head;

    stack<int> stack;

    // Storing first half elements of the Linked List in the stack
    while (fast != nullptr && fast->next != nullptr)
    {
        stack.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    // Handle odd-length linked list
    // Move the slow pointer one ahead of its current position to skip the middle Node
    // ie, if the LL is 1 2 2 3 2 2 1. We want to skip 3 and want to check from next node.
    if (fast != nullptr)
        slow = slow->next;

    while (slow != nullptr)
    {
        int topElement = stack.top();
        stack.pop();

        if (slow->val != topElement)
            return false;

        slow = slow->next;
    }

    return true;
}