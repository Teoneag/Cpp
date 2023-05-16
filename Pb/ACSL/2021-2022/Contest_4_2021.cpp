#include <bits/stdc++.h>
using namespace std;

int sumPathsOfLength2(string edges)
{
    int s = 0, c1, c2, c3;
    vector<int> a[10];
    int n = edges.size(), m;
    for (int i = 0; i < n; i += 3)
        a[int(edges[i] - '0')].push_back(int(edges[i + 1] - '0'));

    for (int i = 1; i < 10; i++)
    {
        c1 = i;
        n = a[c1].size();
        for (int j = 0; j < n; j++)
        {
            c2 = a[i][j];
            m = a[c2].size();
            for (int k = 0; k < m; k++)
            {
                c3 = a[c2][k];
                if (c3 != c2 && c3 != c1 && c2 != c1)
                    s += c1 * 100 + c2 * 10 + c3;
            }
        }
    }
    return s;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    string edges;
    getline(cin, edges);
    int result = sumPathsOfLength2(edges);
    fout << result << "\n";
    fout.close();
    return 0;
}