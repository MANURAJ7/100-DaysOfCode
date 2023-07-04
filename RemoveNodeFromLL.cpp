void solve(ListNode *prev, ListNode *curr, stack<int> &s)
{
    if (curr->next == NULL)
    {
        s.push(curr->val);
        return;
    }
    solve(curr, curr->next, s);
    if (s.empty() || s.top() < curr->val)
    {
        s.pop();
        s.push(curr->val);
    }
    else if (s.top() > curr->val)
    {
        prev->next = curr->next;
        curr->next = NULL;
    }
}
ListNode *removeNodes(ListNode *head)
{
    stack<int> s;
    s.push(head->val);
    ListNode *temp = head;
    solve(temp, temp->next, s);
    if (head->next != NULL && head->next->val > head->val)
    {
        head = head->next;
    }
    return head;
}