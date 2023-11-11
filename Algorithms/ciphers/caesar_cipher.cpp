#include <iostream>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> s >> n;
    for (int i = 0; i < s.length(); i++) cout << (s[i] - n < (int)'a' ? (char)(s[i] - n + 'z' - 'a' + 1) : (char)(s[i] - n));
    return 0;
}