vector<int> nextGreaterElements(vector<int> &nums)
{
    stack<int> s;
    vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[s.top()] <= nums[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = nums[s.top()];
        }
        s.push(i);
    }
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[s.top()] <= nums[i])
        {
            s.pop();
        }
        if (s.empty())
        {
            ans[i] = -1;
        }
        else
        {
            ans[i] = nums[s.top()];
        }
        s.push(i);
    }
    return ans;
}