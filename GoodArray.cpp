bool isGood(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    int max = nums[nums.size() - 1];
    if (nums.size() < max + 1)
        return false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (i == nums.size() - 1)
        {
            if (nums[i] == i)
            {
                return true;
            }
        }
        if (nums[i] != i + 1)
            return false;
    }
    return true;
}