ListNode *deleteDuplicates(ListNode *head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    ListNode *prev = head;
    ListNode *curr = head;
    ListNode *newHead = head;
    while (curr)
    {
        if (curr->next == NULL)
        {
            return newHead;
        }
        else if (curr->next->val != curr->val)
        {
            prev = curr;
            curr = curr->next;
        }
        else
        {
            // Duplicate
            if (curr == newHead)
            {
                while (curr->next != NULL && curr->next->val == curr->val)
                {
                    curr = curr->next;
                }
                if (curr->next == NULL)
                {
                    return NULL;
                }
                prev = curr->next;
                curr = prev;
                newHead = curr;
            }
            else
            {
                while (curr->next != NULL && curr->next->val == curr->val)
                {
                    curr = curr->next;
                }
                if (curr->next == NULL)
                {
                    prev->next = NULL;
                    return newHead;
                }
                prev->next = curr->next;
                curr = curr->next;
            }
        }
    }
    return newHead;
}