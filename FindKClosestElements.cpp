vector<int> findClosestElements(vector<int> &arr, int k, int x)
{
    int s = 0, e = k - 1;
    for (int i = k; i < arr.size(); i++)
    {
        if ((abs(x - arr[i]) < abs(x - arr[s])) || (arr[i] == arr[s]))
        {
            s++;
            e++;
        }
        else if (abs(x - arr[i]) > abs(x - arr[s]))
        {
            break;
        }
    }
    vector<int> ans;
    while (e >= s)
    {
        ans.push_back(arr[s]);
        s++;
    }
    return ans;
}