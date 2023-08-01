vector<int> mostCompetitive(vector<int> &nums, int k)
{
    stack<int> s;
    vector<int> ans(k, 0);
    for (int i = 0; i < nums.size(); i++)
    {
        while (!s.empty() && s.size() + nums.size() - i - 1 >= k && nums[s.top()] > nums[i])
        {
            cout << "popping: " << nums[s.top()];
            s.pop();
        }
        // if(s.size()==k) break;
        if (s.empty() || nums[s.top()] <= nums[i])
            cout << "pushing: " << nums[i];
        s.push(i);
    }
    int j = k - 1;
    while (s.size() > k)
    {
        s.pop();
    }
    while (!s.empty() && j >= 0)
    {
        ans[j] = nums[s.top()];
        s.pop();
        j--;
    }
    return ans;
}