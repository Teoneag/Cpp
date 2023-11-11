#include <iostream>
using namespace std;

int EulerIndicator(int a)
{
    int n = a, d = 2;
    while (a > 1)
    {
        if (a % d == 0)
        {
            n = n / d * (d - 1);
            while (a % d == 0)
                a /= d;
        }
        d++;
        if (d * d > a)
            d = a;
    }
    return n;
}

int main()
{
    cout << EulerIndicator(12);
    return 0;
}