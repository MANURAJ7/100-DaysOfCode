int maxSum(vector<vector<int>> &a)
{
    int ans = 0, sum;
    int i = 0, k;

    for (int i = 0; i < a.size() - 2; i++)
    {

        sum = 0;
        for (k = 0; k < 3; k++)
            sum += a[i][k] + a[i + 2][k];
        sum += a[i + 1][k - 2];
        ans = max(ans, sum);

        for (k = 3; k < a[0].size(); k++)
        {

            sum -= (a[i][k - 3] + a[i + 2][k - 3]);
            sum += (a[i][k] + a[i + 2][k]);
            sum -= a[i + 1][k - 2];
            sum += a[i + 1][k - 1];
            ans = max(ans, sum);
        }
    }

    return ans;
}