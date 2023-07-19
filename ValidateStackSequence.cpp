bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
{
    stack<int> s;
    int push = 0, pop = 0;
    while (push < pushed.size() && pop < popped.size())
    {
        if (s.empty())
        {
            s.push(pushed[push]);
            push++;
        }
        else if (s.top() == popped[pop])
        {
            s.pop();
            pop++;
        }
        else if (pushed[push] == popped[pop])
        {
            push++;
            pop++;
        }
        else
        {
            s.push(pushed[push]);
            push++;
        }
    }
    while (!s.empty() && pop < popped.size())
    {
        if (s.top() != popped[pop])
        {
            return false;
        }
        s.pop();
        pop++;
    }
    if (popped.size() > pop)
        return false;
    else
        return true;
}