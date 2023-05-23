pair<ListNode *, ListNode *> reverse(ListNode *head, int count)
{
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *temp = curr->next;
    while (count > 0)
    {
        --count;
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return {prev, temp};
}

ListNode *reverseBetween(ListNode *head, int left, int right)
{
    if (head == NULL || head->next == NULL || left == right)
        return head;
    ListNode *leftnode = head;
    ListNode *beforeleftnode = NULL;
    for (int i = 1; i < left; ++i)
    {
        beforeleftnode = leftnode;
        leftnode = leftnode->next;
    }
    auto [rightnode, afterrightnode] = reverse(leftnode, right - left + 1);
    if (beforeleftnode != NULL)
    {
        beforeleftnode->next = rightnode;
    }
    else
    {
        head = rightnode;
    }
    leftnode->next = afterrightnode;
    return head;
}