int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();
    stack<int> st;
    int leftsmall[n], rightsmall[n];
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            st.pop();
        }
        if (st.empty())
            leftsmall[i] = 0;
        else
            leftsmall[i] = st.top() + 1;
        st.push(i);
    }
    // clear the stack to be re-used
    while (!st.empty())
        st.pop();

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
            st.pop();

        if (st.empty())
            rightsmall[i] = n - 1;
        else
            rightsmall[i] = st.top() - 1;

        st.push(i);
    }
    int maxA = 0;
    for (int i = 0; i < n; i++)
    {
        maxA = max(maxA, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
    }
    return maxA;
}

int maximalRectangle(vector<vector<char>> &matrix)
{
    int area = 0;
    vector<int> temp;
    for (int col = 0; col < matrix[0].size(); col++)
    {
        if (matrix[0][col] == '0')
        {
            temp.push_back(0);
        }
        else
        {
            temp.push_back(1);
        }
    }
    area = max(area, largestRectangleArea(temp));
    for (int row = 1; row < matrix.size(); row++)
    {
        for (int col = 0; col < matrix[0].size(); col++)
        {
            if (matrix[row][col] == '0')
            {
                temp[col] = 0;
            }
            else
            {
                temp[col]++;
            }
        }
        for (int i = 0; i < temp.size(); i++)
        {
            cout << temp[i];
        }
        cout << endl;
        area = max(area, largestRectangleArea(temp));
    }
    return area;
}