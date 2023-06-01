int minAddToMakeValid(string s)
{
    stack<char> st;
    int ans = 0;
    char c;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            c = s[i];
            st.push(c);
        }
        else
        {
            if (!st.empty())
            {
                if (st.top() == '(')
                {
                    st.pop();
                }
                else
                {
                    ans++;
                }
            }
            else
            {
                ans++;
            }
        }
    }
    ans += st.size();
    return ans;
}