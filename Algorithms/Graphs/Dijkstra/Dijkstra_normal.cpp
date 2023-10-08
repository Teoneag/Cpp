// Dijkstra without PriorityQueue, with adiacence matrix: O(n^2)
/*
a b c d e f g h
1 2 3 4 5 6 7 8
9 1
1 3 6
1 2 8
1 4 9
2 4 2
2 6 9
3 5 12
3 4 5
4 5 6
4 6 7
5 7 8
5 8 6
7 8 1

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
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

// #define INF (1 << 30) - 1
// #define INF 2000
# define INF 0

int n, p, a[1001][1001];

void read()
{
    int i, j, c;
    fin >> n >> p;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            a[i][j] = INF;
    while (fin >> i >> j >> c)
        a[i][j] = c, a[j][i] = c;
}

void show() 
{
    for (int i = 0; i <= n; i++) fout << i << " ";
    fout << '\n';
    for (int i = 1; i <= n; i++) {
        fout << i << ' ';
        for (int j = 1; j <= n; j++) {
            fout << a[i][j] << ' ';
        }
        fout << '\n';
    }
    fout << "\n\n";
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
    for (int i = 1; i <= n; i++) fout << i << ' ';
    fout << '\n';
    for (int i = 1; i <= n; i++)
        fout << (d[i] == INF ? -1 : d[i]) << ' ';
}

int main()
{
    read();
    show();
    Dijkstra();
    return 0;
}
