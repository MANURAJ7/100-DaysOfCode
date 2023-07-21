string removeDuplicates(string s, int k)
{
    stack<char> st;
    char prev = s[0];
    int count = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        st.push(s[i]);
        if (st.top() == prev)
            count++;
        else
        {
            prev = st.top();
            count = 1;
        }
        if (count == k)
            while (count--)
                st.pop();
        if (count <= 0 && st.size() > 0)
        {
            prev = st.top();
            vector<char> v;
            count = 0;
            while (st.size() > 0 && st.top() == prev)
            {
                count++;
                v.push_back(st.top());
                st.pop();
            }
            for (auto x : v)
                st.push(x);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}