#include <fstream>
#include <iomanip>
using namespace std;
ifstream cin("level1-1.in");
ofstream cout("level1-1.out");

int nrtests, rows, columns, nrpoints, a[12][12];

void space(int nr)
{
    if(nr==-1||nr>9) cout<<" ";
    else cout<<"  ";
}

void read()
{
    for(int i=0;i<=10;i++) for(int j=0;j<=10;j++) a[i][j]=0;
    cin>>rows>>columns>>nrpoints;
    for(int i=0;i<nrpoints;i++)
    {
    int poz, color;
    cin>>poz>>color;
    if(poz%columns==0) a[(poz-1)/columns+1][columns]=color;
    else a[(poz-1)/columns+1][poz%columns]=color;
    }
    cin>>nrpoints;
} 

void show()
{
    cout<<"Rows: "<<rows<<", colons: "<<columns<<'\n';
    for(int i=-1;i<=rows+1;i++) {cout<<i; space(i);} cout<<'\n';
    for(int i=0; i<=rows+1; i++)
    {
        cout<<i; space(i);
        for (int j=0; j<=columns+1; j++)
        {cout<<a[i][j]; space(a[i][j]);}
        cout<<'\n';
    }
}

void alg()
{

}

int main()
{
    cout<<"Start\n";
    
    cin>>nrtests;
    for(int inrtests=0; inrtests<nrtests; inrtests++)
    {
        read();
        show();
        cout<<"\n\n";
    }
    return 0;
}