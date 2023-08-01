int maxWidthRamp(vector<int> &nums)
{
    stack<int> s;
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (s.empty() || nums[s.top()] > nums[i])
        {
            s.push(i);
        }
    }
    for (int i = nums.size() - 1; i >= ans; i--)
    {
        while (!s.empty() && nums[s.top()] <= nums[i])
        {
            ans = max(ans, i - s.top());
            s.pop();
        }
    }
    return ans;
}