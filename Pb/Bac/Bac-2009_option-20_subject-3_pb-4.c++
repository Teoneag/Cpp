#include <fstream>
using namespace std;

ifstream cin("test.in");
ofstream cout("test.out");

int main()
{
    int n, m, a[9999/*9999*/], b[9999/*9999*/];
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int j=0;j<m;j++) cin>>b[j];
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else {cout<<a[i]<<" "; i++,j++;}
    }
    return 0;
}