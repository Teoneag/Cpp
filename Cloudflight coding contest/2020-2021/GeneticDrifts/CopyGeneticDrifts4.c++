#include <iostream>
using namespace std;

int n, a[200], x, y, indi, indj, d[200], nr, nrm, mx, my, mindi, mindj, nrinv;

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

void changed()
{
    int di=0;
    for (int i=0; i<indi; i++) d[di++]=a[i];
    for (int i=indj; i>=indi; i--) d[di++]=-a[i]; 
    for (int i=indj+1; i<n;i++) d[di++]=a[i];
}

int calcnr()
{
    nr=0;
    for (int i=0; i<n; i++)
    {
        for (int j=i+1; j<n; j++)
        {
            if (d[i]*d[j]<=0&&d[i]!=d[j]||(d[i]==0&&d[j]==-1)||(d[i]==-1&&d[j]==0))
            {
                if (mod(d[i]+d[j])==1)
                {
                    nr++;
                }
            }
        }
    }
    return nr;
}

int main()
{
    cout<<"Start\n";
    read();

    for (nrinv=1; ; nrinv++)
    {
        for (int i=0;i<n;i++) d[i]=a[i];
        if(calcnr()==0) break;
        nrm=0;
        for (int pi=0; pi<n; pi++)
        {
           for (int pj=pi+1; pj<n; pj++)
            {
                if (a[pi]*a[pj]<=0 && a[pi]!=a[pj] || (a[pi]==0 && a[pj]==-1) || (a[pi]==-1&&a[pj]==0))
                {
                    if (mod(a[pi]+a[pj])==1)
                    {
                        indi=pi, indj=pj;
                        if (x+y==1) indj--;
                        else indi++;

                        changed();
                        if(calcnr()>nrm)
                        {
                            nrm=nr;
                            mx=a[pi];
                            my=a[pj];
                            mindi=pi;
                            mindj=pj;
                        }

                    }
                }
            }
        }
        if(nrm==0) break;

        cout<<nrinv<<", Nrm= "<<nrm<<", mx= "<<mx<<", my= "<<my<<", mindi= "<<mindi<<", mindj= "<<mindj<<",   ";

        indi=mindi;
        indj=mindj;
        y=my;
        x=mx;
        if (x+y==1) indj--;
        else indi++;
        changed();
        for (int i=0; i<n; i++) a[i]=d[i];
        for (int i=0; i<n; i++) cout<<a[i]<<" "; cout<<'\n';
    }
    
    cout<<"\n\n";
    for (int i=0; i<n; i++) cout<<a[i]<<" ";
    cout<<"\n\n Nrinv= "<<--nrinv;
    return 0;
}