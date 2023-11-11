#include <iostream>
using namespace std;

int binarySearch(int *a, int n, int x)
{
    int l = 0, r = n - 1;
    while (l < r)
    {
        if (x < a[(l + r) / 2])
            r = (l + r) / 2 - 1;
        else
            l = (l + r) / 2;
    }
    return (a[l] == x ? l : -1);
}

int main()
{
    int n, a[100000], m, q, x;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> q >> x;
        switch (q)
        {
        case 0:
        {
            cout << binarySearch(a, n, x);
            break;
        }
        case 1:
        {
            cout << binarySearch(a, n, x );
            break;
        }
        default:
            break;
        }
    }

    return 0;
}