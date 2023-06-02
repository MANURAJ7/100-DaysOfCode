int findCelebrity(int n)
{
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        s.push(i);
    }
    while (s.size() > 1)
    {
        int a = s.top();
        s.pop();
        int b = s.top();
        s.pop();

        if (knows(a, b))
        {
            s.push(b);
        }
        if (knows(b, a))
        {
            s.push(a);
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (knows(s.top(), i))
        {
            return -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (i == s.top())
        {
            continue;
        }
        if (!knows(i, s.top()))
        {
            return -1;
        }
    }
    return s.top();
}