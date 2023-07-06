vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    if (k == nums.size() && k == 1)
    {
        return nums;
    }
    vector<int> ans;
    deque<int> q;
    for (int i = 0; i < nums.size(); i++)
    {
        if (q.empty())
        {
            q.push_back(i);
            if (k == 1)
                ans.push_back(nums[i]);
            continue;
        }

        // removing elements outside the window
        if (i - q.front() == k)
        {
            q.pop_front();
        }

        // popping all smaller values
        while (!q.empty() && nums[q.back()] < nums[i])
        {
            q.pop_back();
        }
        // pushing current value
        q.push_back(i);

        // push largest of the window in ans
        if (i >= k - 1)
        {
            ans.push_back(nums[q.front()]);
        }
    }
    return ans;
}