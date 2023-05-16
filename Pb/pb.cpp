#include <iostream>
#include <string>
using namespace std;

int n;
string a[10][10];  // * = target

int v[10];
int h[10];

int ia, ja;

int it, jt;

char c;

int charToInt(char c) { return int(c) - int('0'); }

void print() {
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    // for (int i = 0; i < n; i++) {
    //     cout << v[i] << ' ';
    // }
    // cout << '\n';
    // for (int i = 0; i < n; i++) {
    //     cout << h[i] << ' ';
    // }
    // cout << '\n';
    // cout << ia << ' ' << ja << '\n';
    // cout << it << ' ' << jt << '\n';
}

string missingArrow(int size, string targets, string numbers, string arrows) {
    // cout << size << '\n' << targets << '\n' << numbers << '\n' << arrows;
    n = size;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = '0';
        }
    }

    for (int i = 0; i < targets.size(); i += 3) {
        // cout << charToInt(targets[i]) << ' ' << charToInt(targets[i + 1])
        //      << '\n';
        a[charToInt(targets[i])][charToInt(targets[i + 1])] = '*';
    }

       for (int k = 0; k < arrows.size(); k += 4) {
        // cout << charToInt(arrows[i]) << ' ' << charToInt(arrows[i + 1]) <<
        // '\n';
        int i = charToInt(arrows[k]);
        int j = charToInt(arrows[k + 1]);
        a[i][j] = arrows[k + 2];
        int di, dj;
        switch (arrows[k + 2]) {
            case 'A':
                di = 0, dj = -1;
                break;
            case 'B':
                di = -1, dj = 0;
                break;
            case 'C':
                di = 0, dj = 1;
                break;
            case 'D':
                di = 1, dj = 0;
                break;
            case 'E':
                di = -1, dj = -1;
                break;
            case 'F':
                di = -1, dj = 1;
                break;
            case 'G':
                di = 1, dj = 1;
                break;
            case 'H':
                di = 1, dj = -1;
                break;
        }
        // cout << arrows[k + 2] << ' ' << di << ' ' << dj << '\n';
        while (a[i][j] != "*") {
            i += di;
            j += dj;
            // cout << i << ' ' << j << '\n';
        }
        a[i][j] = '-';
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] != "0" && a[i][j] != "*" && a[i][j] != "-") {
                v[i]++;
                h[j]++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (charToInt(numbers[i]) != v[i]) {
            ia = i;
        }
    }

    for (int i = 0; i < n; i++) {
        if (charToInt(numbers[n + 1 + i]) != h[i]) {
            // cout << "diff: " << charToInt(numbers[n + 1 + i]) << h[i] << ' ' << i << '\n';
             ja = i;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == "*") {
                it = i, jt = j;
                break;
            }
        }
    }

    // cout << ia << ' ' << ja << '\n';
    // cout << it << ' ' << jt << '\n';

    if (ia > it) {
        if (ja > jt) c = 'E';
        else if (ja == jt) c = 'B';
        else c = 'F';
    } else if (ia == it) {
        if (ja > jt) c = 'A';
        else c = 'C';
    } else {
        if (ja > jt) c = 'H';
        else if (ja == jt) c = 'D';
        else c = 'G';
    }

    // cout << char(ia + int('0')) << char(ja + int('0')) << c;

    string res = "";
    res += char(ia + int('0'));
    res += char(ja + int('0'));
    res += c;

    return res;
    // print();
}

int main() {
    int size;
    string targets, numbers, arrows;
    cin >> size;
    cin.ignore();
    getline(cin, targets);
    getline(cin, numbers);
    getline(cin, arrows);
    cout << missingArrow(size, targets, numbers, arrows);
    return 0;
}
/*
4
02 11 20 21
0103 1012
13E 30B 33E
*/