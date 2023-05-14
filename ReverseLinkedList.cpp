ListNode *reverseList(ListNode *head)
{
    ListNode *prev = NULL;
    ListNode *crnt = head;
    ListNode *nxt;

    while (crnt != NULL)
    {
        nxt = crnt->next;
        crnt->next = prev;
        prev = crnt;
        crnt = nxt;
    }
    head = prev;
    return head;
}