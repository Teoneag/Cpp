#include <fstream>
using namespace std;

ifstream fin("test.in");
ofstream fout("test.out");

int main()
{
    int n, m, a[9999/*9999*/], b[9999/*9999*/];
    fin>>n>>m;
    for(int i=0;i<n;i++) fin>>a[i];
    for(int j=0;j<m;j++) fin>>b[j];
    int i=0,j=0;
    while(i<n&&j<m)
    {
        if(a[i]<b[j]) i++;
        else if(a[i]>b[j]) j++;
        else {fout<<a[i]<<" "; i++,j++;}
    }
    return 0;
}