#include <fstream>
#include <algorithm>
#include <cmath>
#include <cfenv>
using namespace std;
ifstream cin("level4_5.in");
ofstream cout("lv1.out");

struct data_type
{
    int p1, s1, p2, s2;
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

int g, pl, maxim, maxim_id;
long double ea,eb;
data_type v[3000];
win b[3000];
long long a[3000];

void read()
{
    cin >> g >> pl;
    for(int i=0;i<g;++i)
    {
        cin >> v[i].p1 >> v[i].s1 >> v[i].p2 >> v[i].s2;
        a[v[i].p1]=1000;a[v[i].p2]=1000;
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
    int c;
    for (int i=0;i<g;++i)
    {
        ea=1/(1+pow(10, (a[v[i].p2]-a[v[i].p1])/400.0));
        eb=1/(1+pow(10, (a[v[i].p1]-a[v[i].p2])/400.0));
        
       if (v[i].s1>v[i].s2) 
       {
           a[v[i].p1]+=32*(1-ea);
           a[v[i].p2]+=32*(-eb);
       }
       else if(v[i].s1<v[i].s2)
       {
           a[v[i].p2]+=32*(1-eb);
           a[v[i].p1]+=32*(-ea);
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