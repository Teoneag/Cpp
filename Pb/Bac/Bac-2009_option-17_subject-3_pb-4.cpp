#include <fstream>
using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

int main()
{
    int n, poz=0,a,a1;
    fin>>n;
    if(n!=0) fin>>a1;
    for(int i=1;i<n;i++)
    {
        fin>>a;
        if(a<a1) poz++;
    }
    fout<<poz+1;
    return 0;
}