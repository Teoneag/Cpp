#include <fstream>
using namespace std;

ifstream cin("test.in");
ofstream cout("test.out");

int main()
{
    int n, poz=0,a,a1;
    cin>>n;
    if(n!=0) cin>>a1;
    for(int i=1;i<n;i++)
    {
        cin>>a;
        if(a<a1) poz++;
    }
    cout<<poz+1;
    return 0;
}