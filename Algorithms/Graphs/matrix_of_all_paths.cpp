// it creates the matrix of all the paths:
// from a adjacent matrix, where only the direct paths from i to j are marked with 1
// in the matrix of all the paths, all the paths from i to j are marked with 1

#include <iostream>
using namespace std;

int n, m, a[101][101];

void read()
{
    int x, y;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        a[x][y] = 1;
    }
}

void matrixOfAllPaths()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] == 0)
                    a[i][j] = a[i][k] * a[k][j];
}

void show()
{
    for (int i = 1; i <= n; i++, cout << '\n')
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << ' ';
}

int main()
{
    read();
    matrixOfAllPaths();
    show();
    return 0;
}
