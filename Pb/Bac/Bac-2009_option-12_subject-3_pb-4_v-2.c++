#include <iostream>
using namespace std;

int main()
{
    int n, a[20], b[20], m=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(a[i]%10 == a[i]/10%10 && a[i]%10 == a[i]/100%10 && a[i]%10 == a[i]/1000%10 && a[i]%10 == a[i]/10000)
        /*if(a[i]==11111||a[i]==22222||a[i]=33333||a[i]=44444||a[i]=55555||a[i]=66666||a[i]=77777||a[i]=88888||a[i]=99999)*/
        {
            if(m==0) b[m++]=a[i];
            else
            {
                int j=0;
                while(a[i]>=b[j]) j++;
                m++;
                for(int k=m-1;k>j;k--) b[k]=b[k-1];
                b[j]=a[i];
            }
            /*cout<<"m= "<<m<<": "; for(int x=0;x<m;x++) cout<<b[x]<<" "; cout<<'\n';*/
            
        }
    }
    for(int j=0;j<m;j++) cout<<b[j]<<" ";
    return 0;
}

/*
5
11111
33333
12345
54321
11111


7
18756
22222
33333
77777
12234
55555
11111
*/