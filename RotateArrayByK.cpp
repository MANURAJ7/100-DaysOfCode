void rotate(vector<int> &nums, int k)
{
    vector<int> v = nums;
    int index;
    for (int i = 0; i < nums.size(); i++)
    {
        index = (i + k) % nums.size();
        nums[index] = v[i];
    }
}