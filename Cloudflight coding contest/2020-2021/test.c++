#include <iostream>
using namespace std;

int main()
{
    int n, a[200], x, y, indi, indj;
    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    cin>>x>>indi>>y>>indj;

    if (x+y==1) indj--;
    else indi++;

    for (int i=0; i<indi; i++) cout<<a[i]<<" ";
    cout<<'\n';
    for (int i=indj; i>=indi; i--) cout<<-a[i]<<" ";
    cout<<'\n';
    for (int i=indj+1; i<n;i++) cout<<a[i]<<" ";
}