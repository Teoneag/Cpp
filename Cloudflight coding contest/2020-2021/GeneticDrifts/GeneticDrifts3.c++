#include <iostream>
using namespace std;

int n, a[200], x, y, indi, indj, d[200], nr;

int mod(int a)
{
    if (a<0) return -a;
    return a;
}

void read()
{
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    cin>>x>>indi>>y>>indj;

    if (x+y==1) indj--;
    else indi++;
}

void changed()
{
    int di=0;
    for (int i=0; i<indi; i++) d[di++]=a[i];
    for (int i=indj; i>=indi; i--) d[di++]=-a[i];
    for (int i=indj+1; i<n;i++) d[di++]=a[i];
}

void verif()
{
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (d[i]*d[j]<0&&d[i]!=d[j]||(d[i]==0&&d[j]==-1)||(d[i]==-1&&d[j]==0))
            {
                if (mod(d[i]+d[j])==1)
                {
                    nr++;
                }
            }
        }
    }
}

int main()
{
    cout<<"Start\n";
    read();
    changed();
    verif();

    for(int i=0; i<n;i++) cout<<d[i]<<" "; cout<<'\n';
    cout<<nr;
    
}