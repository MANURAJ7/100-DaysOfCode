int calPoints(vector<string> &array)
{
    stack<int> s;
    int count = 0;
    for (int i = 0; i < array.size(); i++)
    {
        if (array[i] == "+")
        {
            if (!s.empty())
            {
                int newTop = s.top();
                if (!s.empty())
                {
                    s.pop();
                    newTop += s.top();
                    s.push(newTop - s.top());
                }
                s.push(newTop);
            }
            count += s.top();
        }
        else if (array[i] == "D")
        {
            s.push(s.top() * 2);
            count += s.top();
        }
        else if (array[i] == "C")
        {
            if (!s.empty())
            {
                count -= s.top();
                s.pop();
            }
        }
        else
        {
            s.push(stoi(array[i]));
            count += s.top();
        }
    }
    return count;
}