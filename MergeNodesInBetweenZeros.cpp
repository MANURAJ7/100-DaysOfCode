ListNode *mergeNodes(ListNode *head)
{
    ListNode *newHead = new ListNode();
    newHead->val = -1;
    ListNode *temp2 = newHead;
    ListNode *temp = head;
    int sum = 0;
    while (temp)
    {
        if (temp->val == 0)
        {
            if (sum)
            {
                if (temp2 == newHead && newHead->val == -1)
                {
                    temp2->val = sum;
                    sum = 0;
                }
                else
                {
                    ListNode *newNode = new ListNode();
                    newNode->val = sum;
                    temp2->next = newNode;
                    temp2 = newNode;
                    sum = 0;
                }
            }
        }
        else
        {
            sum += temp->val;
        }
        temp = temp->next;
    }
    return newHead;
}