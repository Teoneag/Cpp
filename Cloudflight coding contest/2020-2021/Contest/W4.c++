#include <fstream>
#include <algorithm>
#include <cmath>
using namespace std;
ifstream cin("level4_1.in");
ofstream cout("lv.out");

struct matchInfo
{
    int player1, score1, player2, score2;
} info[2000];

int nrgames, nrplayers;

win b[2000];
long long a[2000];

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
    for (int i=0;i<g;++i)
    {
        ea=1/(1+powl(10, (a[v[i].p2]-a[v[i].p1])/400));
        eb=1/(1+powl(10, (a[v[i].p1]-a[v[i].p2])/400));
        
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
    cout << 1/(1+powl(10, (1400-1400)/400)); <<"\n"
    for (int i=0;i<pl;++i) 
    {
        b[i].p=i;
        b[i].k=a[i];
    }
    sort (b,b+pl,cmp);
    output();
    return 0;
}