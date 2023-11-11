#include <iostream>
using namespace std;

long long base10to8(long long x)
{
    long long y=0, p=1;
    while(x)
    {
        y+=x%8*p;
        x/=8;
        p*=10;
    }
    return y;
}

int main()
{
    cout<<base10to8(18792364);
    return 0;
}