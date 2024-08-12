#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream cin("level5_1.in");
ofstream cout("lv1.out");

struct data_type
{
    int p[50], s[50];
};

struct win
{
    int p;
    long long k;
};

bool cmp(win a, win b)
{
    if (a.k==b.k) return a.p<b.p;
    return a.k>b.k;
}

int g, pl, maxim, maxim_id, team, r1=0, r2=0;

long double ea,eb;
data_type v[10000];
win b[10000];
long long a[10000];

void read()
{
    cin >> g >> pl >> team;
    for(int i=0;i<g;++i)
    {
        for (int j=0;j<team*2;++j)
        {
            cin >> v[i].p[j] >> v[i].s[j];
            a[v[i].p[j]]=1000;
        }
    }
}

void output ()
{
    for(int i=0;i<pl;i++)
    {
        cout<<b[i].p<<" "<<b[i].k<<"\n";
    }
}

int main()
{
    read();
    for (int i=0;i<g;++i)
    {
        long long s1=0, s2=0; r1=0; r2=0;
        for (int j=0; j<team; ++j) {s1+=v[i].s[j]; r1+=a[v[i].p[j]];}
        for (int j=team; j<2*team; ++j) {s2+=v[i].s[j]; r2+=a[v[i].p[j]];}

       if (s1>s2)
       {
           for (int j=0; j<team; ++j)
           {
                int inamic=r2-r1+a[v[i].s[j]];
                ea=1/(1+pow(10, (inamic-a[v[i].p[j]])/400.0));
                a[v[i].p[j]]+=32*(1-ea);
           }
            for (int j=team; j<2*team; ++j)
            {
                a[v[i].p[j]]=s1-s2+v[i].s[j];
                int inamic=r1-r2+a[v[i].s[j]];
                eb=1/(1+pow(10, (inamic-a[v[i].p[j]])/400.0));
                a[v[i].p[j]]+=32*(-eb);
            }
       }
       else if(s2>s1)
       {
           for (int j=team; j<2*team; ++j)
            {
                a[v[i].p[j]]=s1-s2+v[i].s[j];
                int inamic=r1-r2+a[v[i].s[j]];
                eb=1/(1+pow(10, (inamic-a[v[i].p[j]])/400.0));
                a[v[i].p[j]]+=32*(1-eb);
            }
            for (int j=0; j<team; ++j)
           {
                int inamic=r2-r1+a[v[i].s[j]];
                ea=1/(1+pow(10, (inamic-a[v[i].p[j]])/400.0));
                a[v[i].p[j]]+=32*(-ea);
           }
       }
    }
    for (int i=0;i<pl;++i)
    {
        b[i].p=i;
        b[i].k=a[i];
    }
    sort (b,b+pl,cmp);
    output();
    return 0;
}