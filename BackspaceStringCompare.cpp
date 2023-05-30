void remove(stack<char> &s)
{
    if (s.empty())
        return;
    char top = s.top();
    s.pop();

    remove(s);

    if (top == '#' && s.empty())
    {
        return;
    }
    else if (top == '#' && !s.empty())
    {
        s.pop();
    }
    else
    {
        s.push(top);
    }
}
bool backspaceCompare(string s, string t)
{
    stack<char> s1;
    stack<char> s2;
    int si = 0;
    int ti = 0;
    while (si < s.length() && ti < t.length())
    {
        s1.push(s[si++]);
        s2.push(t[ti++]);
    }
    while (si < s.length())
    {
        s1.push(s[si++]);
    }
    while (ti < t.length())
    {
        s2.push(t[ti++]);
    }
    remove(s1);
    remove(s2);
    if (s1 == s2)
    {
        return true;
    }
    return false;
}