int countCollisions(string directions)
{
    int count = 0;
    stack<char> s;
    for (int i = 0; i < directions.length(); i++)
    {
        if (s.empty() || directions[i] == 'R')
        {
            s.push(directions[i]);
        }
        else if (directions[i] == 'S')
        {
            if (s.top() == 'R')
            {
                while (!s.empty() && s.top() == 'R')
                {
                    count++;
                    s.pop();
                }
            }
            s.push(directions[i]);
        }
        else
        {
            //(directions[i]=='L')
            if (s.top() == 'R')
            {
                count += 2;
                s.pop();
                while (!s.empty() && s.top() == 'R')
                {
                    count++;
                    s.pop();
                }
                s.push('S');
            }
            else if (s.top() == 'L')
            {
                s.push(directions[i]);
            }
            else
            {
                count++;
            }
        }
    }
    return count;
}