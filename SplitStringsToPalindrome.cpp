bool isPa(string &s, int i, int j)
{
    for (; i < j; ++i, --j)
        if (s[i] != s[j])
            return false;
    return true;
}

bool check(string &a, string &b)
{
    for (int i = 0, j = a.size() - 1; i < j; ++i, --j)
        if (a[i] != b[j])
            return isPa(a, i, j) || isPa(b, i, j);
    return true;
}

bool checkPalindromeFormation(string a, string b)
{
    return check(a, b) || check(b, a);
}