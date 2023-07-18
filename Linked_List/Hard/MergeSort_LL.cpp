// Write a program to sort the Linked List (Merge Sort)
/*
Input : 5 - 3 - 0 - 1 - 4 - 2 - 3

Output : 0 - 1 - 2 - 3 - 3 - 4 - 5
*/

Node *merge(Node *l1, Node *l2)
{
    if (l1 == NULL)
        return l2;
    else if (l2 == NULL)
        return l1;

    Node *dummy = new Node(0);
    Node *temp = dummy;

    while (l1 && l2)
    {
        if (l1->data <= l2->data)
        {
            temp->next = l1;
            l1 = l1->next;
        }
        else
        {
            temp->next = l2;
            l2 = l2->next;
        }
        temp = temp->next;
    }

    if (l1)
        temp->next = l1;
    else
        temp->next = l2;

    return dummy->next;
}

Node *MergeSORT(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *slow = head;
    Node *fast = head;
    Node *prev = NULL; /* The 'prev' variable is used to keep track of the end of the first half of the LL.
     So that we can disconnect both linked lists before merging them.*/
    while (fast != NULL && fast->next != NULL)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = NULL; // Disconnected the First half of the LL from the second half.

    Node *left = MergeSORT(head);  // The Left pointer is at head Node. (ie starting point of first half)
    Node *right = MergeSORT(slow); // The Right pointer is at 'slow'. (ie starting point of second half)

    return merge(left, right); // Merge both the halves using merge function.
}