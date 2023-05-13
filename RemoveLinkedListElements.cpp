ListNode *removeElements(ListNode *head, int val)
{
    while (head && head->val == val)
    {
        head = head->next;
    }
    ListNode *curr = head;
    ListNode *prev = NULL;
    while (curr)
    {
        if (curr->val == val)
        {
            if (!curr->next)
            {
                prev->next = NULL;
            }
            else
            {
                prev->next = curr->next;
            }
        }

        else
        {
            prev = curr;
        }
        curr = curr->next;
    }

    return head;
}