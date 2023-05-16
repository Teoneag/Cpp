#include <iostream>
using namespace std;

void merge(int v1[], int l, int m, int r)
{
    int v2[100000], i1 = l, i2 = m + 1, k = l;
    for (int i = l; i <= r; i++)
        v2[i] = v1[i];
    while (i1 <= m && i2 <= r)
        if (v2[i1] < v2[i2])
            v1[k++] = v2[i1++];
        else
            v1[k++] = v2[i2++];
    while (i1 <= m)
        v1[k++] = v2[i1++];
    while (i2 <= r)
        v1[k++] = v2[i2++];
}

int main()
{
    int n, a[1000];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    merge(a, 0, 5, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}