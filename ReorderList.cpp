void reorderList(ListNode *head)
{
    if (!head or !head->next)
        return;

    stack<ListNode *> stk;

    auto it = head, first = head, second = first->next;
    while (it)
    {
        stk.push(it);
        it = it->next;
    }

    int maxPops = stk.size() / 2;

    while (maxPops--)
    {
        auto top = stk.top();
        stk.pop();
        first->next = top;
        top->next = second;

        first = second;
        second = second->next;
    }

    first->next = NULL;
}