#include <iostream>
#include <deque>
#include <vector>
#include <bitset>
#include <queue>
#include <unordered_set>
#include <algorithm>
#include <cmath>
#include <cstring>

#define MOD 1000000007

using namespace std ;

///ifstream cin ("inversmodular.in") ;
///ofstream cout ("inversmodular.out") ;

int post = 0 ;

long long rez(int a, int b, int semn)
{

    if(post)swap(a, b) ;

    if(semn == '+')
    {

        return a + b ;

    }
    if(semn == '-')
    {

        return a - b ;

    }
    if(semn == '*')
    {

        return a * b ;

    }
    if(semn == '/')
    {

        return a / b ;

    }
    if(semn == '^')
    {

        long long aux = 1 ;

        for(int f = 1 ; f <= b ; f ++)
            aux *= a ;

        return aux ;

    }

}

long long eval_postfix(string a)
{

    deque<pair<int, int> > dq ; /// 1 inseamna nr si 0 inseamna semn

    for(int f = 0 ; f < a.size() ; f ++)
    {
        while(f < a.size() && a[f] == ' ')f ++ ;

        string auxx ;

        while(f < a.size() && isdigit(a[f]))
            auxx += a[f ++] ;

        int aux = 0 ;

        if(!auxx.empty())
        aux = atoi(&auxx[0]) ;

        if(aux) /// am dat de nr
            dq.push_back({aux, 1}), f -- ;
        else if(f < a.size())dq.push_back({a[f], 0}) ;

        if(!dq.empty() && !dq.back().second)
        {

            int semn = dq.back().first ;
            dq.pop_back() ;
            int nr2 = dq.back().first ;
            dq.pop_back() ;
            int nr1 = dq.back().first ;
            dq.pop_back() ;

            dq.push_back({rez(nr1, nr2, semn), 1}) ;

        }

    }

    post = 0 ;

    return dq.back().first ;

}

long long eval_prefix(string a)
{

    reverse(a.begin(), a.end()) ;

    post = 1 ;

    return eval_postfix(a) ;

}

string strng ;

string ch ;

int next_sgn(int st, int dr, string degasit) /// gaseste o operatie de tipul precizat in 'degasit' care nu are parantezate in ea si returneaza locatia acesteia, face asta intrun string global
{

    for(int f = dr, cnt = 0 ; f >= st ; f --)
    {
        if(ch[f] == ')')cnt ++ ;
            else if(ch[f] == '(')cnt -- ;

        if(!cnt && strchr(&degasit[0], ch[f]))
        {
            return f ;
        }
    }

    return 0 ; /// daca nu gaseste nimic returneaza 0
}

int frecv[10009] ;

long long recur(int st, int dr)
{
    int ptr ;

    /// acum luam dupa ordinea operatiilor, deci +- primele, apoi */ si dupa parantezele

    if(ptr = next_sgn(st, dr, "+-"))
    {
        if(post == 1)if(!frecv[ptr])strng += ch[ptr], strng += " ", frecv[ptr] = 1 ;

        int a = recur(st, ptr - 1) ;
        int b = recur(ptr + 1, dr) ;
        int rez ;

        if(ch[ptr] == '+')rez = recur(st, ptr - 1) + recur(ptr + 1, dr) ;
            else rez =  recur(st, ptr - 1) - recur(ptr + 1, dr) ;

        if(!post)if(!frecv[ptr])strng += ch[ptr], strng += " ", frecv[ptr] = 1 ;

        return rez ;

    }

    if(ptr = next_sgn(st, dr, "*/"))
    {

        int rez ;

        if(post == 1)if(!frecv[ptr])strng += ch[ptr], strng += " ", frecv[ptr] = 1 ;

        if(ch[ptr] == '*')rez = recur(st, ptr - 1) * recur(ptr + 1, dr) ;
            else rez = recur(st, ptr - 1) * recur(ptr + 1, dr) ; //// era / in mod obisnuit da lam scos sa mearga pe necunoscute

        if(!post)if(!frecv[ptr])strng += ch[ptr], strng += " ", frecv[ptr] = 1 ;

        return rez ;

    }

    if(ptr = next_sgn(st, dr, "^"))
    {

        int rez ;

        int a = recur(st, ptr - 1) ;
        int b = recur(ptr + 1, dr) ;

        rez = 1 ;

        if(post == 1)if(!frecv[ptr])strng += ch[ptr], strng += " ", frecv[ptr] = 1 ;

        for(int f = 1 ; f <= b ; f ++)
            rez *= a ;

        if(!post)if(!frecv[ptr])strng += ch[ptr], strng += " ", frecv[ptr] = 1 ;

        return rez ;

    }

    if(ch[st] == '(')return recur(st + 1, dr - 1) ;

    string aux ;

    for(int f = st ; f <= dr ; f ++)
        aux += ch[f] ;

    if(frecv[st])return 0 ;

    strng += aux ;
    strng += ' ' ;

    frecv[st] = 1 ;

    return 0 ;
    return atoll(&aux[0]) ;
}

long long postfix_to_infix(string a)
{

    deque<pair<int, int> > dq ; /// 1 inseamna nr si 0 inseamna semn

    for(int f = 0 ; f < a.size() ; f ++)
    {
        while(f < a.size() && a[f] == ' ')f ++ ;

        string auxx ;

        while(f < a.size() && isdigit(a[f]))
            auxx += a[f ++] ;

        int aux = 0 ;

        if(!auxx.empty())
        aux = atoi(&auxx[0]) ;

        if(aux) /// am dat de nr
            dq.push_back({aux, 1}), f -- ;
        else if(f < a.size())dq.push_back({a[f], 0}) ;

        if(!dq.empty() && !dq.back().second)
        {

            int semn = dq.back().first ;
            dq.pop_back() ;
            int nr2 = dq.back().first ;
            dq.pop_back() ;
            int nr1 = dq.back().first ;
            dq.pop_back() ;

            dq.push_back({rez(nr1, nr2, semn), 1}) ;

        }

    }

    post = 0 ;

    return dq.back().first ;

}

/// se evaleaza one at a time ecuatiile fiindca sunt multe variabile globale care nu se reseteaza
/// se apeleaza recur(0, ch.size() - 1) si ecuatia rezultanta se va afla in strng, daca se mentioneaza post = 1 atunci va fi prefixata in strng, altfel va fi postfixata

int main()
{

    getline(cin, ch) ;

    ///post = 1 ;
    recur(0, ch.size() - 1) ;

    cout << strng << "\n" << eval_postfix(strng) ;

    return 0 ;
}
/// A*(B+C)/2-(3*A+4)/(A-C)
/// + − / + 2 4 3 / − 9 1 2 / / * 8 3 * 6 2 ^ 1 − 4 1
/// ((a+b)*c)-d

