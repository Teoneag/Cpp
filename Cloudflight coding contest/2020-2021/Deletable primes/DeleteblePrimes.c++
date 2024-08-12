#include <iostream>
using namespace std;

int nr;

int prim(unsigned long long x)
{
    if(x<2||x>2&&x%2==0) return 0;
    for(unsigned long long d=3;d*d<=x;d+=2) if(x%d==0) return 0;
    return 1;
}

void det(unsigned long long a)
{
    unsigned long long p=1;
    while(a/p)
    {
        if(a<10&&prim(a)) {nr++; break;}
        if(prim(a)) det(a%p+a/(p*10)*p);
        p*=10;
    }
}

int main()
{
    unsigned long long t;
    cout<<"Start\nBaga: ";
    cin>>t;
    det(t);
    cout<<"\nNr= "<<nr;
    return 0;
}