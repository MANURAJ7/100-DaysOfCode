int strStr(string hay, string needle)
{
    for (int i = 0; i < hay.length(); i++)
    {
        if (hay[i] == needle[0])
        {
            int k = i + 1;
            int j = 1;
            for (j; k < hay.length() && j < needle.length(); j++, k++)
            {
                if (hay[k] != needle[j])
                {
                    break;
                }
            }
            if (j == needle.length())
                return i;
        }
    }
    return -1;
}