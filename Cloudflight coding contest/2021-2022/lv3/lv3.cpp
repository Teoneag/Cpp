#include <fstream>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

ifstream cin("level3_0.in");
ofstream cout("level3_0.out");

unordered_map<string, string> Map;

vector<string> v;
string printNow = "";

bool eInMap(string a) /// 1 inseamna ca este in Map
{
    if (Map.find(a) == Map.end())
        return 0; /// nu e in Map

    return 1;
}

void mutaIndice(int &indice)
{
    //cout << "Muta indice " << indice << '\n';
    while (v[indice] != "start")
        indice++;

    indice--;
}

void terminateCurenta(int &indice)
{
    printNow = "ERROR";
    mutaIndice(indice);
}

string ObjectToString(int indice)
{
    if (eInMap(v[indice]))
        return Map[v[indice]];
    return v[indice];
}

void printProtocol(int &indice)
{
    indice++;
    printNow += ObjectToString(indice++);
}

void ifProtocol(int &indice);

void declareProtocol(int &indice)
{
    string val, nume;

    nume = v[indice];
    val = ObjectToString(++indice);

    if (eInMap(nume)) /// terminate
    {
        terminateCurenta(indice);
        return;
    }
    Map[nume] = val;

    indice++;
}

void setProtocol(int &indice)
{
    string val, nume;

    nume = v[indice];
    val = ObjectToString(++indice);

    if (!eInMap(nume)) /// terminate !!!!!
    {
        terminateCurenta(indice);
        return;
    }
    Map[nume] = val;

    indice++;
}

string functie(int &indice) /// ne teleporteaza dupa ultimul indice, deci dupa end
{

    while (indice < v.size())
    {
        ///cout << indice << endl ;

        if (v[indice] == "if")
            ifProtocol(indice);
        else if (v[indice] == "print")
            printProtocol(indice);
        else if (v[indice] == "var")
            declareProtocol(++indice);
        else if (v[indice] == "set")
            setProtocol(++indice);
        else if (v[indice] == "end")
        {
            indice++;
            return "";
        }
        else if (v[indice] == "return")
        {
            mutaIndice(indice);
            return "    ";
        }
        else
            return "";
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
    int boolean = -1;

    if (ObjectToString(++indice) == "true")
        boolean = 1;
    else if (ObjectToString(indice) == "false")
        boolean = 0;

    if (boolean == -1)
    {
        terminateCurenta(indice);
        return;
    }

    if (boolean == 1)
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
    for (int i = 0; i < v.size(); i++)
        cout << i << ' ' << v[i] << '\n';
    cout << '\n';
    */
    int indice = 0;
    while (indice < v.size())
    {

        functie(++indice);
        cout  << printNow ;
        if(printNow.size() || 1)cout << '\n' ;
        Map.clear();
        printNow.clear();
    }
    return 0;
}