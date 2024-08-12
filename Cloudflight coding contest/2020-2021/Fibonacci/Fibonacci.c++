#include <iostream>
using namespace std;

int main()
{
    unsigned long long f=0,f1=0,f2=1,p;
    cin>>p;
    for(int i=2;i<=p;i++)
    {
        f=f1+f2;
        f1=f2;
        f2=f;
    }
    cout<<f;
    return 0;
}