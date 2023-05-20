ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
{
    int sizeA = 0;
    int sizeB = 0;
    ListNode *tempA = headA;
    ListNode *tempB = headB;
    while (tempA != NULL || tempB != NULL)
    {
        if (tempA != NULL)
        {
            sizeA++;
            tempA = tempA->next;
        }
        if (tempB != NULL)
        {
            sizeB++;
            tempB = tempB->next;
        }
    }
    if (sizeA > sizeB)
    {
        int d = sizeA - sizeB;
        while (d != 0 && headA != NULL)
        {
            headA = headA->next;
            d--;
        }
    }
    else
    {
        int d = sizeB - sizeA;
        while (d != 0 && headB != NULL)
        {
            headB = headB->next;
            d--;
        }
    }
    while (headA != NULL && headB != NULL)
    {
        if (headA == headB)
        {
            return headB;
        }
        headA = headA->next;
        headB = headB->next;
    }
    return 0;
}