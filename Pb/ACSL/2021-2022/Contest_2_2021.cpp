#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string rearrangeString(string s, int n)
{
    vector<string> v[11];
    int n_s = s.size(), i_i = 0, n_c;
    char c = s[0];
    for (int i = 1; i <= n_s; i++)
    {
        if (s[i] != c)
        {
            n_c = i - i_i;
            v[n_c].push_back(s.substr(i_i, n_c));
            i_i = i;
            c = s[i];
        }
    }
    for (int i = 0; i < 11; i++)
        sort(v[i].begin(), v[i].end());

    s = "", n_c = 0, c = '0';
    for (int i = 10; i > 0; i--)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            s += v[i][j];
            if (s.back() == c)
                n_c += i;
            else
                n_c = i, c = s.back();
            while (n_c > n)
            {
                s.pop_back();
                n_c--;
            }
        }
    }
    return s;
}

int main()
{
    string s;
    int n;
    cin >> n >> s;
    cout << rearrangeString(s, n);
    return 0;
}