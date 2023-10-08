#include <iostream>
using namespace std;

int main() {
    int num, m, fact, acc, quot;

    num = 440;
    m = 0;
    
    top1: 
    acc = num;
    acc -= 2;
    if (acc < 0) {
        goto stop;
    }
    acc = 2;
    fact = acc;
    
    top2:
    acc = num;
    acc /= fact;
    quot = acc;
    acc *= fact;
    acc -= num;
    if (acc == 0) {
        goto next;
    }
    acc = fact;
    acc += 1;
    fact = acc;
    goto top2;

    next:
    acc = fact;
    acc -= m;
    if (acc < 0) {
        goto cont;
    }
    acc = fact;
    m = acc;

    cont:
    acc = quot;
    num = acc;
    goto top1;

    stop:
    cout << m;
    return 0;
}