#include<iostream>
using namespace std;

void citire(int &n,int &m,int a[],int b[])
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    cin>>m;
    for(int j=0;j<m;j++) cin>>b[j];
}

void afisare(int n,int m,int a[],int b[])
{
    cout<<"\nAfisare:\n"<<n<<": ";
    for(int i=0;i<n;i++) cout<<a[i]<<" ";
    cout<<'\n'<<m<<": ";
    for(int j=0;j<m;j++) cout<<b[j]<<" ";
    cout<<"\n\n";
}

void sub(int n,int m,int a[],int b[])
{
    cout<<'\n';
    int i=0,j=0,ok=0;
    if(a[0]<b[0]) {cout<<a[0]<<" "; i=1,ok=1;}
    else {cout<<b[0]<<" "; j=1;}
 
    while (i<n&&j<m)
    {
        if(a[i]<b[j])
        {
            if(ok==0) {cout<<a[i]<<" "; i++; ok=1;}
            else i++;
        }
        else
        {
            if(ok==1)  {cout<<b[j]<<" "; j++; ok=0;}
            else j++;
        }
    }
    if(i<n&&ok==0) cout<<a[i];
    else if(j<m&&ok==1) cout<<b[j];
}

int main()
{
    int n,m,a[100],b[100];

    citire(n,m,a,b);

    /*afisare(n,m,a,b);*/

    sub(n,m,a,b);

    return 0;
}

/*5
2 4 8 10 14
3
3 5 11*/