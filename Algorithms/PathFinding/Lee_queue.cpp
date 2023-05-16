#include <iostream>
#include <utility>
#include <queue>
using namespace std;

int n, m, a[100][100], b[100][100];

int di[4] = {0, 0, 1, -1};
int dj[4] = {1, -1, 0, 0};

void show(int a[][100])
{
    cout << '\n';
    for (int i = 1; i <= n; i++, cout << '\n')
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << ' ';
}

void read()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j], a[i][j]--;
}

void pathGen(int i, int j)
{
    int iv, jv;
    b[i][j] = a[i][j];
    if (a[i][j] == 1)
        return;
    for (int k = 0; k < 4; k++)
    {
        iv = i + di[k], jv = j + dj[k];
        if (a[i][j] == a[iv][jv] + 1)
        {
            b[i][j] = a[i][j];
            pathGen(iv, jv);
        }
    }
}

int Lee(int is, int js, int ie, int je)
{
    queue<pair<int, int>> q;
    q.push(make_pair(is, js));
    a[is][js] = 1;
    int i, j, iv, jv;
    while (!q.empty())
    {
        i = q.front().first, j = q.front().second;
        for (int k = 0; k < 4; k++)
        {
            iv = i + di[k], jv = j + dj[k];
            if (a[iv][jv] == -1)
            {
                a[iv][jv] = a[i][j] + 1;
                if (iv == ie && jv == je)
                    return a[iv][jv];
                q.push(make_pair(iv, jv));
            }
        }
        q.pop();
    }
}

int main()
{
    int is, js, ie, je;
    read();
    cin >> is >> js >> ie >> je;
    cout << Lee(is, js, ie, je) - 1 << '\n';
    show(a);
    pathGen(ie, je);
    show(b);
    return 0;
}

/*
4 8
0 0 0 1 0 0 0 0
0 1 0 0 0 1 0 0
0 0 0 1 0 0 0 1
0 0 0 0 0 1 0 0
1 1 4 8
*/