ListNode *swapNodes(ListNode *head, int k)
{
    ListNode *left = head, *right = head;
    for (int i = 0; i < k - 1; i++)
    {
        right = right->next;
    }

    ListNode *end = right;
    while (right->next)
    {
        left = left->next;
        right = right->next;
    }

    swap(end->val, left->val);

    return head;
}