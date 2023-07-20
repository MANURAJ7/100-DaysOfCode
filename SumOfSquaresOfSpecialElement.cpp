int sumOfSquares(vector<int> &nums)
{
    int sum = 0;
    int n = nums.size();
    for (int i = 0; i < n / 2; i++)
    {
        if (n % (i + 1) == 0)
        {
            sum += nums[i] * nums[i];
        }
    }
    sum += nums[n - 1] * nums[n - 1];
    return sum;
}