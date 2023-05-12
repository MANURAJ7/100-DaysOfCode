vector<vector<int>> generateMatrix(int n)
{
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    int count = 1;
    vector<vector<int>> ans(n, vector<int>(n, 0));
    while (top <= bottom && left <= right)
    {

        // right
        for (int i = left; i <= right; i++)
        {
            ans[top][i] = count;
            count++;
        }
        top++;
        // top
        for (int i = top; i <= bottom; i++)
        {
            ans[i][right] = count;
            count++;
        }
        right--;
        // left
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans[bottom][i] = count;
                count++;
            };
            bottom--;
        }
        // bottom
        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans[i][left] = count;
                count++;
            }
            left++;
        }
    }
    return ans;
}