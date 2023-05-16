#include <iostream>
using namespace std;

long long sumBase8(long long x, long long y)
{
    long long s=0, p=1;
    int sc, c3=0;
    while(x&&y)
    {
        sc=x%10+y%10+c3;
        c3=sc/8;
        sc-=sc/8*8;
        s+=sc*p;
        p*=10;
        x/=10, y/=10;
    }
    while(x)
    {
        sc=x%10+c3;
        c3=sc/8;
        sc-=sc/8*8;
        s+=sc*p;
        p*=10;
        x/=10;
    }
    while(y)
    {
        sc=y%10+c3;
        c3=sc/8;
        sc-=sc/8*8;
        s+=sc*p;
        p*=10;
        y/=10;
    }
    s+=p*c3;
    return s;
}

int main()
{
    cout<<sumBase8(12345677654321,76543211234567);
    return 0;
}