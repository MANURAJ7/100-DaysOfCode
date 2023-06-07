vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
{
    stack<int> s;
    s.push(-1);
    unordered_map<int, int> map;
    vector<int> ans;
    for (int i = nums2.size() - 1; i >= 0; i--)
    {
        while (s.top() != -1 && nums2[i] >= nums2[s.top()])
        {
            s.pop();
        }
        map[nums2[i]] = s.top();
        s.push(i);
    }
    for (int i = 0; i < nums1.size(); i++)
    {
        if (map.find(nums1[i])->second == -1)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(nums2[map.find(nums1[i])->second]);
        }
    }
    return ans;
}