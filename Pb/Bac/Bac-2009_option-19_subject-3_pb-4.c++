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
        if(a[i]<b[j]) {fout<<a[i]<<" "; i++;}
        else if(a[i]>b[j]) {fout<<b[j]<<" "; j++;}
        else i++;
    }
    while(i<n) {fout<<a[i]; i++;}
    while(j<m) {fout<<b[j]; j++;}
    return 0;
}