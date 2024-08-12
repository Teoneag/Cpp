#include <fstream>
using namespace std;
ifstream cin("level1_5.in");
ofstream cout("lv1.out");

struct data_type
{
    int p1, s1, p2, s2;
};



int g, pl, maxim, maxim_id;
data_type v[2000];

void read()
{
    cin>>g>>pl;
    for(int i=0;i<g;++i)
    {
        cin >> v[i].p1 >> v[i].s1 >> v[i].p2 >> v[i].s2;
    }
}

void output (){
    cout<<maxim_id<<" "<<maxim;
}


int main()
{
    read();
    for (int i=0;i<g;++i)
    {
        if (v[i].s1>maxim)
        {
            maxim=v[i].s1;
            maxim_id=v[i].p1;
        }
        else if (v[i].s1==maxim)
        {
            maxim_id=min(maxim_id,v[i].p1);
        }
        if (v[i].s2>maxim)
        {
            maxim=v[i].s2;
            maxim_id=v[i].p2;
        }
        else if (v[i].s2==maxim)
        {
            maxim_id=min(maxim_id,v[i].p2);
        }
    }
    output();
    return 0;
}