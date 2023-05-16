#include <iostream>
using namespace std;

int gcd_Euclid_nonrecursive(int a, int b)
{
    int aux;
    while (b)
    {
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

int gcd_binaryEuclid_recursive(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if ((a & 1) == 0 && (b & 1) == 0)
        return 2 * gcd_binaryEuclid_recursive(a >> 1, b >> 1);
    if ((a & 1) == 0)
        return gcd_binaryEuclid_recursive(a >> 1, b);
    if ((b & 1) == 0)
        return gcd_binaryEuclid_recursive(a, b >> 1);
    if (a > b)
        return gcd_binaryEuclid_recursive(a - b, b);
    return gcd_binaryEuclid_recursive(a, b - a);
}

int gcd_Euclid_recursive(int a, int b)
{
    if (b == 0)
        return a;
    return gcd_Euclid_recursive(b, a % b);
}

pair<long long, long long> extended_gcd(int a, int b)
{
    if (b == 0)
        return {1, 0};
    auto p = extended_gcd(b, a % b);
    return {p.second, p.first - (a / b) * p.second};
}

int main()
{
    // cout << gcd_Euclid_recursive(69, 46) << '\n';
    // cout << gcd_Euclid_nonrecursive(69, 46) << '\n';
    cout << gcd_binaryEuclid_recursive(12, 64) << '\n';
    cout << extended_gcd(12, 64).first << ' ' << extended_gcd(12, 64).second;
    return 0;
}