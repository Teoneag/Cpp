#include <iostream>
using namespace std;

int baseBTo10(string s, int b) {
    int p = 1, m = 0, c;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] >= '0' && s[i] <= '9')
            c = int(s[i]) - int('0');
        else if (s[i] >= 'A' && s[i] <= 'F')
            c = int(s[i]) - int('A') + 10;
        else if (s[i] >= 'a' && s[i] <= 'f')
            c = int(s[i]) - int('a') + 10;
        m += c * p;
        p *= b;
    }
    return m;
}

string base10ToB(int n, int b) {}

int base_10_to_b(int n, int b)  // cout << base_10_to_b(24, 8);
{
    int m = 0, p = 1;
    while (n) {
        m += (n % b) * p;
        n /= b;
        p *= 10;
    }
    return m;
}

int digitToNr(char c) {
    if (c >= '0' && c <= '9') return int(c) - int('0');
    if (c >= 'A' && c <= 'F')
        return int(c) - int('A') + 10;
    else if (c >= 'a' && c <= 'f')
        return int(c) - int('a') + 10;
}

char nrToDigit(int d) {
    if (d < 10)
        return char(d + int('0'));
    else
        return char(d - 10 + int('a'));
}

string add1(string s, int b) {
    // char c = s[s.size() - 1];
    int i = s.size() - 1;
    bool ok = 0;

    while (!ok) {
        // cout << "i: " << i << ' ' << digitToNr(s[i]) + 1 << ' ';
        if (digitToNr(s[i]) + 1 >= b) {
            // cout << "Prea mare boss: ";
            // cout << s << '\n';
            s[i] = '0';
            // cout << s << '\n';
        } else {
            s[i] = nrToDigit(digitToNr(s[i]) + 1);
            ok = 1;
        }
        i--;
        if (i < 0) {
            break;
        }
    }
    // cout << "Almost s: " << s << '\n';
    if (!ok) {
        s = "1" + s;
    }
    return s;
}

int findModeCount(int num, int base, string start) {
    string s = start;
    int max = 0, a[16] = {0}, c;
    while (num--) {
        // cout << "S: " << s << ", digits: ";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9')
                c = int(s[i]) - int('0');
            else if (s[i] >= 'A' && s[i] <= 'F')
                c = int(s[i]) - int('A') + 10;
            else if (s[i] >= 'a' && s[i] <= 'f')
                c = int(s[i]) - int('a') + 10;
            // cout << c << ' ';
            a[c]++;
        }
        s = add1(s, base);
        // cout << "Added: " << s << '\n';
    }
    for (int i = 0; i < 16; i++) {
        if (a[i] > max)
            max = a[i];
    }
    return max;
}

// int findModeCount(int num, int base, string start) {
//     string s = start;
//     int nr = 0, a[16] = {0}, c;

//     while (num--) {
//         cout << "S: " << s << ", digits: ";
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] >= '0' && s[i] <= '9')
//                 c = int(s[i]) - int('0');
//             else if (s[i] >= 'A' && s[i] <= 'F')
//                 c = int(s[i]) - int('A') + 10;
//             else if (s[i] >= 'a' && s[i] <= 'f')
//                 c = int(s[i]) - int('a') + 10;
//             cout << c << ' ';
//             a[c]++;
//         }
//         int x = baseBTo10(start, base);
//         cout << ", X: " << x << '\n';
//         s = base10ToB(x + 1, base);
//         cout << "S: " << s << ", digits: ";
//         num = 0;
//     }
//     for (int i = 0; i < 16; i++) {
//         nr += a[i];
//     }
//     return nr;
// }

int main() {
    // cout << digitToNr('F') << '\n';
    // cout << nrToDigit(15);
    // cout << add1("11", 2) << '\n';
    // cout << base_b_t0_10(10, 10) << "\n\n";
    // cout << baseBTo10("0", 2);
    cout << findModeCount(15, 8, "2");
    return 0;
}
