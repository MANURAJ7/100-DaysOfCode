int maxFrequency(vector<int> &nums, int k)
{
    sort(nums.begin(), nums.end());
    long long currSum = 0;
    int ans = 0, start = 0, end = 0;
    while (end <= nums.size() - 1)
    {
        currSum += nums[end];

        // IMPORTANT: nums[end]*(end-start+1) > currSum+k
        while (nums[end] > (currSum + k) / (end - start + 1))
        {
            currSum -= nums[start];
            start++;
        }

        ans = max(ans, end - start + 1);
        end++;
    }
    return (int)ans;
}