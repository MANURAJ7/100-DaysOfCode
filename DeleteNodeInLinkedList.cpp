// Its a simple code but the catch is that you are not given the head pointer.

void deleteNode(ListNode *node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}