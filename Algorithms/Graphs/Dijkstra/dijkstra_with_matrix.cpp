// 100 points: https://www.pbinfo.ro/probleme/588/dijkstra
// from here: https://www.pbinfo.ro/articole/6135/algoritmul-lui-dijkstra

#include <fstream>
using namespace std;
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");

#define INF 1000000000

int n, istart, a[101][101], d[101];

void read() {
    int i, j, c;
    fin >> n >> istart;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            a[i][j] = INF;
        }
    }

    while (fin >> i >> j >> c) {
        a[i][j] = c;
    }

    for (int i = 1; i <= n; i++) {
        d[i] = a[istart][i];
    }
}

void dijkstra(int s) {
    bool f[101] = {0};

    d[s] = 0;
    f[s] = 1;
    d[0] = INF;

    for (int k = 1; k < n; k++) {
        int im = 0;
        for (int i = 1; i <= n; i++) {
            if (f[i] == 0 && d[i] < d[im]) im = i;
        }
        f[im] = 1;
        for (int i = 1; i <= n; i++) {
            if (f[i] == 0 && d[i] > d[im] + a[im][i]) d[i] = d[im] + a[im][i];
        }
    }
}

int main() {
    read();
    dijkstra(istart);
    for (int i = 1; i <= n; i++) {
        fout << (d[i] == INF ? -1 : d[i]) << ' ';
    }
    return 0;
}
