ListNode *reverse(ListNode *ptr)
{
    ListNode *pre = NULL;
    ListNode *nex = NULL;
    while (ptr != NULL)
    {
        nex = ptr->next;
        ptr->next = pre;
        pre = ptr;
        ptr = nex;
    }
    return pre;
}

bool isPalindrome(ListNode *head)
{
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    slow->next = reverse(slow->next);
    ListNode *temp = head;
    slow = slow->next;

    while (slow != NULL)
    {
        if (slow->val != temp->val)
        {
            return false;
        }
        slow = slow->next;
        temp = temp->next;
    }
    return true;
}