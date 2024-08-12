#include <iostream>
using namespace std;

bool isPrime(long long x)
{
    if (x < 2 || x > 2 && x % 2 == 0)
        return 0;
    for (long long d = 3; d * d <= x; d+=2)
        if (x % d == 0)
            return 0;
    return 1;
}

int main()
{
    //cout << "Let's goooo!";
    long long a;
    cin >> a;
    cout << isPrime(a);
    return 0;
}