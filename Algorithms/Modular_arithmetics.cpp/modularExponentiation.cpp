#include <iostream>
using namespace std;

int exp_modulo(int a, int p, int n)
{
    long long rez = 1;
    while (p > 0)
    {
        if (p & 1)
            rez = (rez * a) % n;
        a = (a * a) % n;
        p = p >> 1;
    }
    return rez ;
}

int main()
{
    cout << exp_modulo(2, 10, 10);
    return 0;
}
