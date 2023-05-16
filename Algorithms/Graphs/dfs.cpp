#include <iostream>
using namespace std;

int n, a[100][100], v[100];

void read()
{
    int x, y, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }
}

void show()
{
    for (int i = 1; i <= n; i++, cout << '\n')
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
}

void dfs(int k)
{
    cout << k << ' ';
    v[k] = 1;
    for (int i = 1; i <= n; i++)
    {
        // cout << i << ' ';
        // cout << a[k][i] << ' ' << v[i] << '\n';
        if (a[k][i] && !v[i])
            dfs(i);
    }
}
/*
9 10
1 2
1 4
2 3
2 5
4 5
4 6
5 7
7 8
7 9
8 9
*/
int main()
{
    read();
    // show();
    dfs(5);
    return 0;
}
