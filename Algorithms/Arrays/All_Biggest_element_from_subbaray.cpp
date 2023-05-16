#include <deque>
#include <iostream>
using namespace std;

void printKMax(int arr[], int n, int k) {
    deque<int> dq;
    int i = 0;
    for (; i < k; i++) {
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    for (; i < n; i++) {
        cout << arr[dq.front()] << ' ';
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        while (!dq.empty() && arr[dq.back()] <= arr[i]) dq.pop_back();
        dq.push_back(i);
    }
    cout << arr[dq.front()] << '\n';
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int i;
        int arr[n];
        for (i = 0; i < n; i++) cin >> arr[i];
        printKMax(arr, n, k);
        t--;
    }
    return 0;
}