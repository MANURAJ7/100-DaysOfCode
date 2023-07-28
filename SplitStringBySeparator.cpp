vector<string> splitWordsBySeparator(vector<string> &words, char separator)
{
    string temp;
    vector<string> v;
    for (int i = 0; i < words.size(); i++)
    {
        if (!temp.empty())
        {
            v.push_back(temp);
            temp.clear();
        }
        for (int j = 0; j < words[i].length(); j++)
        {
            if (words[i][j] != separator)
            {
                temp.push_back(words[i][j]);
            }
            else
            {
                if (!temp.empty())
                {
                    v.push_back(temp);
                    temp.clear();
                }
            }
        }
    }
    if (!temp.empty())
    {
        v.push_back(temp);
        temp.clear();
    }
    return v;
}