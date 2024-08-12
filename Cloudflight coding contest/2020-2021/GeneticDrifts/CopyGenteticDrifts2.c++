#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*ifstream cin("");
ofstream cout("");*/

long long n, p[200], nr, x, indi, y, indj, a[200];

void read()
{
    cin>>n;
    for (int i=0;i<n;i++) {cin >> p[i]; a[i]=p[i];}
    cin >> x >> indi >> y >> indj;
}

int mod(int a)
{
    if (a<0) return -a;
    return a;
}

void show()
{
    for (int i=0; i<n; i++) cout<<p[i]<<" ";
}

int main()
{
    cout<<"Start!\n";
    read();
    
    if (x+y==1) indj--;
    else indi++;

    for(int i=indi; i<=indj; i++) p[i]=-a[indj-(i-indi)];

    cout<<'\n';
    show();
    return 0;
}