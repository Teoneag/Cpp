#include <fstream>
using namespace std;

ifstream cin ("level1_5.in");
ofstream cout ("level1_5.out");

int main()
{
    //for (char *i = strtok(&a[0], " "); i; i = strtok(0, " "))
    int n ; 
    cin >> n ;

    string a ;

    cin >> a ;

    while(cin >> a)    
        if(a != "print" && a != "end")
            cout << a ;

    return 0;
}