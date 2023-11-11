#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int>> G, GT;
int n, nr;

vector<bool> V;
stack<int> S;

void read()
{
    int m, a, b;
    cin >> n >> m;
    G = GT = vector<vector<int>>(n + 1);
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        G[a].push_back(b);
        GT[b].push_back(a);
    }
}

void dfs(int k)
{
    V[k] = 1;
    for (auto x : G[k])
        if (!V[x])
            dfs(x);
    S.push(k);
}

void dfsGT(int k)
{
    V[k] = 1;
    for (auto x : GT[k])
        if (!V[x])
            dfsGT(x);
}

int main()
{
    read();
    V = vector<bool>(n + 1, false);
    for (int i = 1; i <= n; i++)
        if (!V[i])
            dfs(i);
    V = vector<bool>(n + 1, false);
    while(!S.empty())
    {
        // cout << S.top() << ' ';
        if (!V[S.top()])
        {
            nr++;
            dfsGT(S.top());
        }
        S.pop();
    }
    cout << nr;
    return 0;
}