void solve(ListNode *prev, ListNode *curr)
{
    prev->next = curr->next;
    curr->next = prev;
    if (prev->next == NULL || prev->next->next == NULL)
    {
        return;
    }
    else
    {
        curr = prev->next;
        prev->next = curr->next;
        solve(curr, curr->next);
    }
}
ListNode *swapPairs(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *FinalHead = head->next;
    solve(head, head->next);
    return FinalHead;
}