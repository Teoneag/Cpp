#include <iostream>
using namespace std;

int base_b_t0_10(int n, int b)
{
    int p = 1, m = 0;
    while (n)
    {
        m += (n % 10) * p;
        p *= b;
        n/=10;
    }
    return m;
}

int main()
{
    cout << base_b_t0_10(1546, 7);
    return 0;
}