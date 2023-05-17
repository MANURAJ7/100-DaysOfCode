ListNode *detectCycle(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *entry = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }
    return 0;
}