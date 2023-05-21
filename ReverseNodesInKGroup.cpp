ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *dummyNode = new ListNode(0);
    dummyNode->next = head;
    ListNode *pre = dummyNode;
    ListNode *curr;
    ListNode *nex;
    int len = 0;
    ListNode *temp = head;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    while (len >= k)
    {
        curr = pre->next;
        nex = curr->next;
        for (int i = 1; i < k; i++)
        {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }
        pre = curr;
        len = len - k;
    }
    return dummyNode->next;
}