string removeStars(string strng)
{
    string ans = "";
    for (int i = 0; i < strng.length(); i++)
    {
        if (strng[i] == '*')
        {
            ans.pop_back();
        }

        else
        {
            ans.push_back(strng[i]);
        }
    }
    return ans;
}