vector<int> dailyTemperatures(vector<int> &temp)
{
    stack<int> s;
    s.push(-1);
    vector<int> rightMax(temp.size());
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        while (s.top() != -1 && temp[i] >= temp[s.top()])
        {
            s.pop();
        }
        if (s.top() == -1)
        {
            rightMax[i] = 0;
        }
        else
        {
            rightMax[i] = s.top() - i;
        }
        s.push(i);
    }

    return rightMax;
}