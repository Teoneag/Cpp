#include <iostream>
#include <regex>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> s;
    cout << (regex_match(s, regex ("[or]*b[aeiou]*s*")) ? "Da": "Nu");
    return 0;
}