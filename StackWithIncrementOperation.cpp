vector<int> v;
int max;
CustomStack(int maxSize)
{
    max = maxSize;
}

void push(int x)
{
    if (v.size() == max)
    {
        return;
    }
    else
    {
        v.push_back(x);
    }
}

int pop()
{
    if (v.empty())
    {
        return -1;
    }
    else
    {
        int i = v.back();
        v.pop_back();
        return i;
    }
}

void increment(int k, int val)
{
    int i = 0;
    int n = k;
    while (n && i < v.size())
    {
        v[i++] += val;
        n--;
    }
}