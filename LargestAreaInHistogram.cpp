vector<int> nextSmaller(vector<int> heights, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for (int i = n - 1; i >= 0; i--)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

vector<int> prevSmaller(vector<int> heights, int n)
{
    stack<int> s;
    vector<int> ans(n);
    s.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (s.top() != -1 && heights[s.top()] >= heights[i])
        {
            s.pop();
        }
        ans[i] = s.top();
        s.push(i);
    }
    return ans;
}

int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    int area = INT_MIN;
    vector<int> next(n);
    next = nextSmaller(heights, n);

    vector<int> prev(n);
    prev = prevSmaller(heights, n);

    for (int i = 0; i < n; i++)
    {
        int l = heights[i];
        if (next[i] == -1)
        {
            next[i] = n;
        }
        int b = next[i] - prev[i] - 1;

        int temp_area = l * b;
        area = max(area, temp_area);
    }
    return area;
}