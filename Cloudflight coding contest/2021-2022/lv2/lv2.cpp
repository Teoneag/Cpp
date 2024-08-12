#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream cin("level2_5.in");
ofstream cout("level2_5.out");

vector<string> v;

void printProtocol(int &indice)
{
    indice++;
    cout << v[indice++];
}

void ifProtocol(int &indice);

int error;

string functie(int &indice) /// ne teleporteaza dupa ultimul indice, deci dupa end
{
    while (indice < v.size())
    {
        //cout << '\n';
        //     << indice << "\n";

        if (v[indice] == "if")
            ifProtocol(indice);
        else if (v[indice] == "print")
            printProtocol(indice);

        else if (v[indice] == "end")
        {
            indice++;
            return "";
        }
        else if (v[indice] == "return")
        {
            return "";
        }
        else
            error = indice, indice++;
    }
    return "";
}

void findNextend(int &indice)
{
    int contor = 1;
    while (contor)
    {
        if (v[indice] == "if")
            contor++;
        else if (v[indice] == "end")
            contor--;
        indice++;
    }
}

void ifProtocol(int &indice)
{
    bool ifIsTrue = 0;
    if (v[++indice] == "true")
    {
        functie(++indice);
        ifIsTrue = 1;
    }
    else
        findNextend(indice);

    if (ifIsTrue)
        findNextend(indice);
    else
        functie(++indice);
}

int main()
{
    int nrOfLines;
    string a;
    cin >> nrOfLines;
    cin.ignore();
    for (int f = 1; f <= nrOfLines; f++)
    {
        getline(cin, a);
        for (char *i = strtok(&a[0], " "); i; i = strtok(0, " "))
            v.push_back(i);
    }
    /*
    for (int f = 0; f < v.size(); f++)
        cout << f << ' ' << v[f] << "\n";
    */
    int i = 1;

    functie(i);

    //cout << endl
//         << error;

    return 0;
}