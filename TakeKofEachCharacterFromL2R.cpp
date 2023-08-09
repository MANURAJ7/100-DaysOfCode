bool invalid(vector<int> &v1, vector<int> &v2)
{
    if (v2[0] > v1[0] || v2[1] > v1[1] || v2[2] > v1[2])
        return true;
    else
        return false;
}
int takeCharacters(string str, int k)
{
    if (!k)
        return 0;
    int s = 0, ans = INT_MIN;
    vector<int> v1(3, 0), v2(3, 0);
    for (int i = 0; i < str.length(); i++)
    {
        v1[str[i] - 'a']++;
    }
    for (int i = 0; i < v1.size(); i++)
    {
        v1[i] -= k;
        if (v1[i] < 0)
        {
            return -1;
        }
    }
    int i = 0;
    for (i; i < str.length(); i++)
    {
        v2[str[i] - 'a']++;
        if (invalid(v1, v2))
        {
            ans = max(ans, i - s);
            while (s <= i && invalid(v1, v2))
            {
                v2[str[s] - 'a']--;
                s++;
            }
        }
    }

    ans = max(ans, i - s);
    return str.length() - ans;
}