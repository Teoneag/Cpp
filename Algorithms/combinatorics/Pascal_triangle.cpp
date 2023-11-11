// Pascal triangle generation

#include <iostream>
using namespace std;

int a[21][21], n;

void show()
{
  for (int i = 1; i <= n; i++, cout << '\n')
    for (int j = 1; j <= i; j++)
      cout << a[i][j] << ' ';
}

void pascalTriangle()
{
  a[1][1] = a[2][1] = a[2][2] = 1;
  for (int i = 3; i <= n; i++)
    for (int j = 1; j <= i; j++)
      a[i][j] = a[i - 1][j] + a[i - 1][j - 1];
}

int main()
{
  cin >> n;
  pascalTriangle();
  show();
  return 0;
}

/*
Se numește "triunghiul lui Pascal" următorul triunghi de numere
1
1   1
1   2   1
1   3   3   1
1   4   6   4   1
1   5  10  10   5   1
1   6  15  20  15   6   1
1   7  21  35  35  21   7   1
...
format după următoarea regulă:
- linia a "i"-a din triunghi este formată din fix i elemente
- primul și ultimul element de pe fiecare linie este egal
  cu 1
- în afară de acestea, orice alt element de pe o anumită linie
  este egal cu suma dintre elemenul de deasupra și cel de
  deasupra-stânga.

Ex: 21 = 6+15  (să zicem că numerotăm matricea de la 0
                astfel a[7][2]=a[6][2]+a[6][1])

Regula generală este deci:
   a[i][j]=a[i-1][j]+a[i-1][j-1]

Vă rămâne ca temă: citiți n<20 și generați și afișați
triunghiul lui Pascal care are n+1 linii (de exemplu
pt. n=7 se genrează și afișează triungiul de mai sus)

Obs: Acest triunghi are proprietatea specială că fiecare
element a[i][j] are de fapt semnficiația algebrică de a fi
egal cu combinările de i luate câte j.

  combinări de i luate câte j = câte submulțimi distincte
cu fix j elemente se pot forma.
Ex:
i=5 j=3 să ne convingem că numărul de combinări de 5 luate
câte 3 este 10 (ca pe triungiul de mai sus):
luăm mulțimea {1,2,3,4,5} și scriem toate subm. de 3:
{1,2,3}   {2,3,4}   {3,4,5}
{1,2,4}   {2,3,5}
{1,2,5}   {2,4,5}
{1,3,4}
{1,3,5}
{1,4,5}
Deci iată, ele sunt într-adevăr 10.
*/
