#include <math.h>
double myPow(double x, int n)
{
    if (x < 0)
    {
        if (n % 2 == 0)
        {
            return exp(n * log(-x));
        }
        else
        {
            return -exp(n * log(-x));
        }
    }
    return exp(n * log(x));
}