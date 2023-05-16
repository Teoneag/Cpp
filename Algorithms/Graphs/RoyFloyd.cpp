#include <iostream>
using namespace std;

#define INF (1 << 30) - 1

int n, m, a[101][101];

void read()
{
    int x, y, z;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        a[x][y] = z;
    }
    for (int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if (a[i][j] == 0 && i != j)
                a[i][j] = INF;
}

void show()
{
    for (int i = 1; i <= n; i++, cout << '\n')
        for (int j = 1; j <= n; j++)
            cout << (a[i][j] == INF? -1: a[i][j]) << ' ';
}

void RoyFloyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] > a[i][k] + a[k][j])
                    a[i][j] = a[i][k] + a[k][j];
}

int main()
{
    read();
    // show();
    RoyFloyd();
    show();
    return 0;
}
