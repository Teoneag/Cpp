#include <algorithm>
#include <iostream>
using namespace std;
/*ifstream cin("");
ofstream cout("");*/

int n, p[200], nr;

struct d
{
    int x, y;
};

d v[4000];

bool cmp(d a, d b)
{
    return a.x<b.x;
}

void read()
{
    cin>>n;
    for (int i=1;i<=n;i++) cin>>p[i];
}

int mod(int a)
{
    if (a<0) return -a;
    return a;
}

void show()
{
    cout<<nr<<" ";
    for (int i=0;i<nr;i++) 
    {
        if (v[i].x!=0||v[i].y!=0)
            cout<<v[i].x<<" "<<v[i].y<<" ";
    }
}

int main()
{
    cout<<"Start!\n";
    read();
    for (int i=1; i<=n; i++)
    {
        for (int j=i+1; j<=n; j++)
        {
            if (p[i]*p[j]<0&&p[i]!=p[j]||(p[i]==0&&p[j]==-1)||(p[i]==-1&&p[j]==0))
            {
                if (mod(p[i]+p[j])==1)
                {
                    v[nr].x=p[i], v[nr].y=p[j];
                    nr++;
                }
            }
        }
    }
    sort(v,v+nr,cmp);
    show();
    return 0;
}