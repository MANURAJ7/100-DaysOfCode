int maxSumMinProduct(vector<int> &n)
{
    long res = 0;
    vector<long> prefix(n.size() + 1), st;
    for (int i = 0; i < n.size(); ++i)
        prefix[i + 1] = prefix[i] + n[i];
    for (int i = 0; i <= n.size(); ++i)
    {
        while (!st.empty() && (i == n.size() || n[st.back()] > n[i]))
        {
            int j = st.back();
            st.pop_back();
            res = max(res, n[j] * (prefix[i] - prefix[st.empty() ? 0 : st.back() + 1]));
        }
        st.push_back(i);
    }
    return res % 1000000007;
}