#include <iostream>
#include <random>
using namespace std;

bool notsorted(int v[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if(v[i] > v[i + 1])
            return 1;
    return 0;
}

int main()
{
    int n, a[1000], i1, i2;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    while (notsorted(a, n))
    {
        i1 = rand() % n;
        i2 = rand() % n;
        swap(a[i1], a[i2]);
    }
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    return 0;
}