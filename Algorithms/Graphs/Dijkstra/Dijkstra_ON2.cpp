// Dijkstra without PriorityQueue, with adiacence matrix: O(n^2)
/*
s a b c d e f g h
1 2 3 4 5 6 7 8 9
9 1
1 2 1
2 1 1
2 4 6
4 2 6
2 3 8
3 2 8
2 5 9
5 2 9
3 5 2
5 3 2
3 7 9
7 3 9
4 6 12
6 4 12
4 5 5
5 4 5
5 6 6
6 5 6
5 7 7
7 5 7
6 8 8
8 6 8
6 9 6
9 6 6
8 9 1
9 9 1

5 4
1 3 1
2 1 2
4 2 1
4 3 8
5 3 5
5 4 2
*/

#include <fstream>
using namespace std;
ifstream cin("dijkstra.in");
ofstream cout("dijkstra.out");

// #define INF (1 << 30) - 1
#define INF 0

int n, p, a[1001][1001];

void read()
{
    int i, j, c;
    cin >> n >> p;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = INF;
    while (cin >> i >> j >> c)
        a[i][j] = c;
}

void show() 
{
    for (int i = 0; i <= n; i++) cout << i << " ";
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << i << ' ';
        for (int j = 1; j <= n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << "\n\n";
}

void Dijkstra()
{
    int d[1001], idmin;
    for (int i = 1; i <= n; i++)
        d[i] = a[p][i];
    bool f[1001] = {0};
    d[p] = 0;
    for (int k = 0; k < n; k++)
    {
        idmin = 1;
        for (int i = 1; i <= n; i++)
            if (!f[i] && d[i] < d[idmin])
                idmin = i;
        if (d[idmin] == INF)
            break;
        f[idmin] = 1;
        for (int i = 1; i <= n; i++)
            if (!f[i] && d[i] > d[idmin] + a[idmin][i])
                d[i] = d[idmin] + a[idmin][i];
    }
    for (int i = 1; i <= n; i++) cout << i << ' ';
    cout << '\n';
    for (int i = 1; i <= n; i++)
        cout << (d[i] == INF ? -1 : d[i]) << ' ';
}

int main()
{
    read();
    show();
    Dijkstra();
    return 0;
}
