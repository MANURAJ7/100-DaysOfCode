int sumSubarrayMins(vector<int> &arr)
{
    auto negativeInf = std::numeric_limits<int>::min();
    arr.insert(arr.begin(), negativeInf);
    arr.insert(arr.end(), negativeInf);
    int res = 0;
    vector<int> stack;
    for (int i = 0; i < arr.size(); ++i)
    {
        int n = arr[i];
        while (stack.size() > 0 && n < arr[stack.back()])
        {
            int index = stack.back();
            stack.pop_back();
            int left = index - stack.back();
            int right = i - index;
            int mod = (7 + std::pow(10, 9));
            long long multi = (left * right) % mod;
            long long total = (multi * (arr[index] % mod)) % mod;
            res = (res + total) % mod;
        }

        stack.push_back(i);
    }
    return res;
}