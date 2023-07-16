void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    vector<int> sorted;
    int i1 = 0;
    int i2 = 0;
    int i = 0;
    while (i1 < m && i2 < n)
    {
        if (nums1[i1] <= nums2[i2])
        {
            sorted.push_back(nums1[i1++]);
        }
        else
        {
            sorted.push_back(nums2[i2++]);
        }
    }
    while (i2 < n)
    {
        sorted.push_back(nums2[i2++]);
    }
    while (i1 < m)
    {
        sorted.push_back(nums1[i1++]);
    }
    nums1 = sorted;
    // end
}