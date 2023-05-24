static bool cmp(pair<int, int> &a, pair<int, int> &b)
{
    return a.second > b.second;
}

vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<pair<int, int>> freq;

    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        mp[nums[i]]++;
    }

    for (auto x : mp)
    {
        freq.push_back({x.first, x.second});
    }

    sort(freq.begin(), freq.end(), cmp);

    vector<int> res;
    for (int i = 0; i < k; i++)
        res.push_back(freq[i].first);

    return res;
}