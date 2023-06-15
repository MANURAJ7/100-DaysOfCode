bool find132pattern(vector<int> &nums)
{
    int min = 0;
    vector<int> small;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[min] >= nums[i])
        {
            min = i;
            small.push_back(-1);
        }
        else
        {
            small.push_back(min);
        }
    }
    stack<int> s;
    for (int i = nums.size() - 1; i > 0; i--)
    {
        while (!s.empty() && small[i] != -1 && s.top() <= nums[small[i]])
        {
            s.pop();
        }
        if (!s.empty() && small[i] != -1 && s.top() < nums[i])
        {
            return true;
        }
        s.push(nums[i]);
    }
    return false;
}