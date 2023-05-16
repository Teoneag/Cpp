#include <iostream>
#include <vector>
using namespace std;

int findMinNode(int *weight, bool *visited, int n) {
    int minIndex = -1;
    for (int i = 0; i < n; i++) {
        if (!visited[i] && (minIndex == -1 || weight[i] < weight[minIndex])) {
            minIndex = i;
        }
    }
    return minIndex;
}

int primMST(vector<vector<int>> &city, int n) {
    int weight[100];
    bool visited[100];
    int parent[100];
    for (int i = 0; i < n; i++) {
        weight[i] = 1000000000;
        visited[i] = false;
    }
    parent[0] = -1;
    weight[0] = 0;
    for (int i = 1; i <= n - 1; i++) {
        int minNode = findMinNode(weight, visited, n);
        visited[minNode] = true;
        for (int j = 0; j < n; j++) {
            if (city[minNode][j] > 0 && !visited[j]) {
                if (city[minNode][j] < weight[j]) {
                    weight[j] = city[minNode][j];
                    parent[j] = minNode;
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++) {
        cout << weight[i] << ' ';
        cout << '\n';
        ans += weight[i];
    }
    return ans;
}

int main() {
    int n = 8;

    vector<vector<int>> city = {
        {0, 8, 6, 9, 0, 0, 0, 0},
        {8, 0, 0, 2, 0, 9, 0, 0},
        {6, 0, 0, 5, 12, 0, 0, 0},
        {9, 2, 5, 0, 6, 7, 0, 0},
        {0, 0, 12, 6, 0, 3, 8, 6},
        {0, 9, 0, 7, 3, 0, 0, 0},
        {0, 0, 0, 0, 8, 0, 0, 1},
        {0, 0, 0, 0, 6, 0, 1, 0}};

    int minCost = primMST(city, n);
    cout << "The minimum cost to connect all cities = " << minCost << endl;
}