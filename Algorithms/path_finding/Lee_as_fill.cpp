/*
4 5
3
1 2
4 3
3 2
*/

#include <iostream>
#include <iomanip>
using namespace std;

int Lee(int x, int y, int fx, int fy, int &nr, int a[][102])
{
    if(a[x][y]==0)
    {
        if(x==fx&&y==fy) return nr;
        Lee(x+1, y, fx, fy, ++nr, a);
        Lee(x-1, y, fx, fy, ++nr, a);
        Lee(x, y+1, fx, fy, ++nr, a);
        Lee(x, y-1, fx, fy, ++nr, a);
    }
}

int main()
{
    int a[102][102]={0}, n, m, k, x, y, nr=0;
    cin>>n>>m>>k;
    for(int i=0; i<k; i++)
    {
        cin>>x>>y;
        a[x][y]=-1;
    }
    for(int i=0; i<=n+1; i++)
    {
        a[i][0]=-1;
        a[i][m+1]=-1;
    }
    for(int i=0; i<=m+1; i++)
    {
        a[0][i]=-1;
        a[n+1][i]=-1;
    }

    cout<<Lee(1, 1, n, m, nr, a)<<"\n";

    for(int i=0; i<=n+1; i++)
    {
        for(int j=0; j<=m+1; j++)
        {
            cout<<setw(3)<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}