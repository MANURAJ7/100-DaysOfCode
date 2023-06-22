vector<int> nextLargerNodes(ListNode *head)
{
    vector<pair<int, int>> s;
    vector<int> ans;
    ListNode *temp = head;
    int idx = 0;

    while (temp != NULL)
    {
        ans.push_back(0);
        while (s.size() && temp->val > s.back().second)
        {

            auto [id, val] = s.back();
            s.pop_back();
            ans[id] = temp->val;
        }
        s.push_back({idx++, temp->val});
        temp = temp->next;
    }
    return ans;
}