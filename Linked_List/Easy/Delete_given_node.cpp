// Write a program to Delete a Given node in the linked list when THE HEAD IS NOT GIVEN.
/*
Input : 1 - 2 - 3 - 4 - 5
node : 3

Output : 1 - 2 - 4 - 5
*/
void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}