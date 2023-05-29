bool isValid(string s)
{
    if (s.length() == 0 || s.length() == 1)
    {
        return false;
    }
    stack<char> stack;
    char c;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '(' || s[i] == '[')
        {
            c = s[i];
            stack.push(c);
        }
        else
        {
            if (stack.empty())
                return false;
            if (s[i] == '}' && stack.top() == '{' || s[i] == ')' && stack.top() == '(' || s[i] == ']' && stack.top() == '[')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (stack.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}