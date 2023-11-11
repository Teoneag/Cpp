#include <iostream>
using namespace std;

int base_10_to_b(int n, int b)
{
    int m = 0, p=1;
    while (n)
    {
        m += (n % b)*p;
        n /= b;
        p*=10;
    }
    return m;
}

int main()
{
    cout << base_10_to_b(24, 8);
    return 0;
}