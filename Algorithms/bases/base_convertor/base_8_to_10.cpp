#include <iostream>
using namespace std;

long long base8to10(long long x)
{
    long long y=0, p=1;
    while(x)
    {
        y+=x%10*p;
        p*=8;
        x/=10;
    }
    return y;
}

int main()
{
    cout<<base8to10(16);
    return 0;
}