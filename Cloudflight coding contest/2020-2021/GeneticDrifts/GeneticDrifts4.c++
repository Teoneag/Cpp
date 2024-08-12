#include <iostream>
using namespace std;

int n, a[200], x, y, indi, indj, d[200], nr, nrm, i, j;

int mod(int a)
{
    if (a<0) return -a;
    return a;
}

void read()
{
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
}

void changedverif()
{
    int di=0;
    for (int i2=0; i2<i; i2++) d[di++]=a[i2];
    for (int i2=j; i2>=i; i2--) d[di++]=-a[i2];
    for (int i2=j+1; i2<n;i2++) d[di++]=a[i2];
}

void changed()
{
    if (x+y==1) indj--;
    else indi++;

    int di=0;
    for (int i=0; i<indi; i++) d[di++]=a[i];
    for (int i=indj; i>=indi; i--) d[di++]=-a[i];
    for (int i=indj+1; i<n;i++) d[di++]=a[i];

    for(int i=0;i<n;i++) a[i]=d[i];
}

void verif()
{
    for (int i2=0; i2<n; i2++)
    {
        for (int j2=i2+1; j2<n; j2++)
        {
            if (d[i2]*d[j2]<0&&d[i2]!=d[j]||(d[i2]==0&&d[j2]==-1)||(d[i2]==-1&&d[j2]==0))
            {
                if (mod(d[i2]+d[j2])==1)
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

    for(i=0;i<n;i++) a[i]=d[i];
    verif();
    while(nr)
    {
        for (i=0; i<n; i++)
        {
            for (j=i+1; j<n; j++)
            {
                if (a[i]*a[j]<0&&d[i]!=a[j]||(a[i]==0&&a[j]==-1)||(a[i]==-1&&a[j]==0))
                {
                    if (mod(d[i]+d[j])==1)
                    {
                        changedverif();
                        nr=0;
                        verif();
                        if(nr>nrm)
                        {
                            nrm=nr;
                            x=a[i];
                            y=a[j];
                            indi=i;
                            indj=j;
                        }
                    }
                }
            }
        }
        changed();
    }
    
    for(i=0; i<n;i++) cout<<d[i]<<" "; cout<<'\n';
    cout<<nr;
    
}
return 0;