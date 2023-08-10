string removeOuterParentheses(string str)
{
    stack<char> s;
    string ans;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            if (!s.empty())
            {
                ans.push_back(str[i]);
            }
            s.push(str[i]);
        }
        else
        {
            s.pop();
            if (!s.empty())
            {
                ans.push_back(str[i]);
            }
        }
    }
    return ans;
}