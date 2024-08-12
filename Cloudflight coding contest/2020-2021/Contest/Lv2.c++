#include <fstream>
#include <algorithm>
using namespace std;
ifstream cin("level2_5.in");
ofstream cout("lv1.out");

struct data_type
{
    int p1, s1, p2, s2;
};

struct win
{
    int p;
    int win;
};

bool cmp(win a, win b)
{
    if (a.win==b.win) return a.p<b.p;
    return a.win>b.win;
}

int g, pl, maxim, maxim_id, a[2000];
data_type v[2000];
win b[2000];

void read()
{
    cin>>g>>pl;
    for(int i=0;i<g;++i)
    {
        cin >> v[i].p1 >> v[i].s1 >> v[i].p2 >> v[i].s2;
    }
}

void output (){
    for (int i=0;i<pl;i++){
        cout<<b[i].p<<" "<<b[i].win<<"\n";
    }
}


int main()
{
    read();
    
    for (int i=0;i<g;++i)
    {
       if (v[i].s1>v[i].s2) a[v[i].p1]++;
       else a[v[i].p2]++;
    }
    
    for (int i=0;i<pl;++i) 
    {
        b[i].p=i;
        b[i].win=a[i];
    }
    sort (b,b+pl,cmp);
    output();
    return 0;
}