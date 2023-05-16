#include <iostream>
#include <climits>
#include <cstring>
using namespace std;
/*
3 4
1 2 3 4 7 7 8 9 5 6 7 8
6 8 6 4 4 5 3 2 8 3 1 9
3 6 7 3 4 6 2 1 3 2 5 5
*/
int sumSmallestInVisitedCells(string rows_cols, string array1, string array2, string array3)
{
    int n[2] = {0}, iv = 0;
    for (char *c = strtok(&rows_cols[0], " "); c; c = strtok(0, " "))
    {
        char *cc = c;
        while (*cc != '\0')
            n[iv] = n[iv] * 10 + int(*cc - '0'), cc++;
        iv++;
    }

    int i = 0, j = 0, a[15][15][3] = {0};
    for (char *c = strtok(&array1[0], " "); c; c = strtok(0, " "))
    {
        char *cc = c;
        if (c[0] == '-')
            cc++;
        while (*cc != '\0')
            a[i][j][0] = a[i][j][0] * 10 + int(*cc - '0'), cc++;
        if (c[0] == '-')
            a[i][j][0] *= -1;
        j++;
        if (j >= n[1])
            j = 0, i++;
    }

    i = 0, j = 0;
    for (char *c = strtok(&array2[0], " "); c; c = strtok(0, " "))
    {
        char *cc = c;
        if (c[0] == '-')
            cc++;
        while (*cc != '\0')
            a[i][j][1] = a[i][j][1] * 10 + int(*cc - '0'), cc++;
        if (c[0] == '-')
            a[i][j][1] *= -1;
        j++;
        if (j >= n[1])
            j = 0, i++;
    }

    i = 0, j = 0;
    for (char *c = strtok(&array3[0], " "); c; c = strtok(0, " "))
    {
        char *cc = c;
        if (c[0] == '-')
            cc++;
        while (*cc != '\0')
            a[i][j][2] = a[i][j][2] * 10 + int(*cc - '0'), cc++;
        if (c[0] == '-')
            a[i][j][2] *= -1;
        j++;
        if (j >= n[1])
            j = 0, i++;
    }

    i = 0, j = 0;
    int m = INT_MIN, im, jm, ok = 0;
    long long s = 0;
    s += min(a[i][j][0], min(a[i][j][1], a[i][j][2]));
    while (i < n[0] - 1 && j < n[1] - 1)
    {
        for (iv = 0; iv < 3; iv++)
        {
            if (a[i + 1][j][iv] > m)
                m = a[i + 1][j][iv], im = i + 1, jm = j, ok = 0;
            else if (a[i + 1][j][iv] == m)
                ok = 1;
            if (a[i][j + 1][iv] > m)
                m = a[i][j + 1][iv], im = i, jm = j + 1, ok = 0;
            else if (a[i][j + 1][iv] == m)
                ok = 1;
        }
        if (ok)
            i = i + 1, j = j + 1, m = 0, ok = 0;
        else
            i = im, j = jm, m = INT_MIN, ok = 0;
        s += min(a[i][j][0], min(a[i][j][1], a[i][j][2]));
    }
    /*for (i = 0; i < n[0]; i++)
    {
        for (j = 0; j < n[1]; j++)
            cout << a[i][j][0] << ' ';
        cout << '\n';
    }*/
    return s;
}

int main()
{
    cout << sumSmallestInVisitedCells("3 4", "1 2 3 4 7 7 8 9 5 6 7 8", "6 8 6 4 4 5 3 2 8 3 1 9", "3 6 7 3 4 6 2 1 3 2 5 5");
    return 0;
}