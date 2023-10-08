// Dijkstra's algorithm with priority queue
// Pb from https://chipcie.wisv.ch/resources/candycontribution/problem.pdf
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge {
    int v, p; // v = destination, p = percentage
};

long long solve(vector<vector<Edge>> &Adj, int s, int t, long long c) {
    auto remainingCandies = vector<long long>(Adj.size(), 0);
    auto visited = vector<bool>(Adj.size(), false);

    remainingCandies[s] = c;
    priority_queue<pair<long long, int>> q;
    q.push({c, s});
    while (!q.empty()) {
        auto p = q.top();
        q.pop();
        if (p.second == t) break; // we reached the destination
        if (visited[p.second]) continue; // we already visited this node
        visited[p.second] = true; // mark the node as visited

        for (auto e : Adj[p.second]) {
            if (!visited[e.v]) {
                long long newRemainingCandies = (p.first * (100 - e.p)) / 100;
                if (newRemainingCandies > remainingCandies[e.v]) {
                    remainingCandies[e.v] = newRemainingCandies;
                    q.push({newRemainingCandies, e.v});
                }
            }
        }
    }
    return remainingCandies[t];
}

int main() {
    int n; // nr countries
    int m; // nr borders
    int s; // starting country
    int t; // destination country
    long long c; // nr candies
    cin >> n >> m >> s >> t >> c;

    auto Adj = vector<vector<Edge>>(n + 1, vector<Edge>());

    int u, v, p;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        Adj[u].push_back({v, p});
        Adj[v].push_back({u, p});
    }

    cout << solve(Adj, s, t, c) << '\n';
    return 0;
}