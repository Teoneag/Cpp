#include <fstream>
#include <vector>
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

#define INF (1 << 30) - 2

int n, s;
vector<vector<pair<int, int>>> g;

void read()
{
    int x, y, w;
    fin >> n >> s;
    g = vector<vector<pair<int, int>>>(n + 1);
    while (fin >> x >> y >> w)
        g[x].push_back(make_pair(y, w));
}

void dijkstra()
{
    vector<bool> f(n + 1, 0);
    vector<int> d(n + 1, INF);
    int nm;
    d[0] = INF + 1, d[s] = 0;
    for (int k = 1; k < n; k++)
    {
        nm = 0;
        for (int i = 1; i <= n; i++)
            if (!f[i] && d[i] < d[nm])
                nm = i;
        f[nm] = 1;
        for (int i = 0; i < g[nm].size(); i++)
            if (d[g[nm][i].first] > d[nm] + g[nm][i].second)
                d[g[nm][i].first] = d[nm] + g[nm][i].second;
    }
    for (int i = 1; i <= n; i++)
        fout << (d[i] == INF ? -1 : d[i]) << ' ';
}

int main()
{
    read();
    dijkstra();
    return 0;
}