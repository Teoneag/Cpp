#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct dict
{
    queue<string> b;
    queue<string> j;
    queue<string> n;
    queue<string> c;
    queue<string> v;
    queue<string> p;
} a;
vector<string> sent;

string generate_prop(int i)
{
    string s = "", x, vowels = "aeiou";
    for (int j = 1; j < sent[i].size(); j++)
    {
        //cout << sent[i][j] << ' ';
        switch (sent[i][j])
        {
        case 'N':
        {
            x = a.n.front();
            a.n.pop();
            a.n.push(x);
            s += x;
            break;
        }
        case 'C':
        {
            x = a.c.front();
            a.c.pop();
            a.c.push(x);
            s += x;
            break;
        }
        case 'V':
        {
            x = a.v.front();
            a.v.pop();
            a.v.push(x);
            s += x;
            break;
        }
        case 'J':
        {
            x = a.j.front();
            a.j.pop();
            a.j.push(x);
            s += x;
            break;
        }
        case 'B':
        {
            x = a.b.front();
            a.b.pop();
            a.b.push(x);
            s += x;
            break;
        }
        case 'P':
        {
            x = a.p.front();
            a.p.pop();
            a.p.push(x);
            s += x;
            break;
        }
        case 'T':
        {
            s += "the";
            break;
        }
        case 'A':
        {
            s += "a";
            switch (sent[i][j + 1])
            {
            case 'N':
            {
                if (vowels.find(a.n.front()[0]) != string::npos)
                    s += 'n';
                break;
            }
            case 'C':
            {
                if (vowels.find(a.c.front()[0]) != string::npos)
                    s += 'n';
                break;
            }
            case 'V':
            {
                if (vowels.find(a.v.front()[0]) != string::npos)
                    s += 'n';
                break;
            }
            case 'J':
            {
                if (vowels.find(a.j.front()[0]) != string::npos)
                    s += 'n';
                break;
            }
            case 'B':
            {
                if (vowels.find(a.b.front()[0]) != string::npos)
                    s += 'n';
                break;
            }
            case 'P':
            {
                if (vowels.find(a.p.front()[0]) != string::npos)
                    s += 'n';
                break;
            }
            }

            break;
        }
        }
        s += ' ';
    }

    return s;
}

string generate_sentences(vector<string> dictionary, string sentences)
{
    for (int i = 0; i < dictionary.size(); i++)
    {
        switch (dictionary[i][0])
        {
        case 'N':
        {
            for (char *j = strtok(&dictionary[i][2], " "); j; j = strtok(0, " "))
                a.n.push(j);
            break;
        }
        case 'C':
        {
            for (char *j = strtok(&dictionary[i][2], " "); j; j = strtok(0, " "))
                a.c.push(j);
            break;
        }
        case 'V':
        {
            for (char *j = strtok(&dictionary[i][2], " "); j; j = strtok(0, " "))
                a.v.push(j);
            break;
        }
        case 'J':
        {
            for (char *j = strtok(&dictionary[i][2], " "); j; j = strtok(0, " "))
                a.j.push(j);
            break;
        }
        case 'B':
        {
            for (char *j = strtok(&dictionary[i][2], " "); j; j = strtok(0, " "))
                a.b.push(j);
            break;
        }
        case 'P':
        {
            for (char *j = strtok(&dictionary[i][2], " "); j; j = strtok(0, " "))
                a.p.push(j);
            break;
        }
        }
    }

    for (char *i = strtok(&sentences[0], " "); i; i = strtok(0, " "))
        sent.push_back(i);

    string s = "", x;
    for (int i = 0; i < sent.size(); i++)
    {
        switch (sent[i][0])
        {
        case 'D':
        {
            //cout << j << ' ';
            x = generate_prop(i);
            s += toupper(x[0]);
            s += &x[1];
            s.erase(s.size() - 1, 1);
            s += ". ";
            break;
        }
        case 'I':
        {
            //cout << j << ' ';
            x = generate_prop(i);
            s += toupper(x[0]);
            s += &x[1];
            s.erase(s.size() - 1, 1);
            s += ". ";
            break;
        }
        case 'Q':
        {
            //cout << j << ' ';
            x = generate_prop(i);
            s += "What ";
            s += x;
            s.erase(s.size() - 1, 1);
            s += "? ";
            break;
        }
        case 'E':
        {
            //cout << j << ' ';
            x = generate_prop(i);
            s += toupper(x[0]);
            s += &x[1];
            s.erase(s.size() - 1, 1);
            s += "! ";
            break;
        }
        }
    }
    return s;
}
/*
6
B productively
J green
N apple tree birds
C pick
V grows fly
P on above below among
ETJNVBPTN QNVP DTJNVPAJNPN ICAN


1
B productively
DBB
*/

int main()
{
    int n;
    string prop;
    vector<string> dictionary;
    string sentences;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin, prop);
        dictionary.push_back(prop);
    }
    getline(cin, sentences);
    cout << generate_sentences(dictionary, sentences);
    return 0;
}