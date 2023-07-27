string sortVowels(string s)
{
    string v;
    vector<int> index;
    for (int i = 0; i < s.length(); i++)
    {
        if (tolower(s[i]) == 'a' || tolower(s[i]) == 'e' || tolower(s[i]) == 'i' || tolower(s[i]) == 'o' || tolower(s[i]) == 'u')
        {
            v.push_back(s[i]);
            index.push_back(i);
        }
    }
    if (v.size() < 2)
        return s;
    sort(v.begin(), v.end());
    int k = 0;
    for (int i = 0; i < v.size(); i++)
    {
        s[index[k]] = v[i];
        k++;
    }
    return s;
}