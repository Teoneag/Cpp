#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct piece
{
    int x;
    int y;
} rege, piece, knightValues[8];

char a[9][9];
int damage[9][9];

vector<string> pie;

void prepareMatrix()
{
    for (int i = 1; i < 9; i++)
        for (int j = 1; j < 9; j++)
            a[i][j] = '0';
}

void showMatrix()
{
    for (int i = 8; i > 0; i--)
    {
        for (int j = 1; j < 9; j++)
            cout << a[j][i] << ' ';
        cout << '\n';
    }
}

void showDamage()
{
    for (int i = 8; i > 0; i--)
    {
        for (int j = 1; j < 9; j++)
            cout << setw(3) << damage[j][i] << ' ';
        cout << '\n';
    }
}

int sePoateMisca(int x, int y)
{
    int ok = 0;
    if (a[x + 1][y + 1] != -1)
        ok = 1;
    if (a[x + 1][y - 1] != -1)
        ok = 1;
    if (a[x + 1][y] != -1)
        ok = 1;
    if (a[x][y + 1] != -1)
        ok = 1;
    if (a[x][y - 1] != -1)
        ok = 1;
    if (a[x - 1][y + 1] != -1)
        ok = 1;
    if (a[x - 1][y - 1] != -1)
        ok = 1;
    if (a[x - 1][y] != -1)
        ok = 1;
    return ok;
}

string find_king_status(string pieces)
{
    prepareMatrix();
    for (char *i = strtok(&pieces[0], " "); i; i = strtok(0, " "))
        pie.push_back(i);
    string verticalCoordonates = "0abcdefgh";
    for (int i = 0; i < pie.size(); i++)
    {
        //cout << i << ' ' << pie[i][0] << ' ';
        piece.x = verticalCoordonates.find(pie[i][1]);
        piece.y = (int)(pie[i][2] - '0');
        switch (pie[i][0])
        {
        case 'K':
        {
            rege.x = piece.x;
            rege.y = piece.y;
            break;
        }
        case 'Q':
        {
            a[piece.x][piece.y] = 'Q';
            //cout << i << ' ' << pie[i][0] << ' ';
            for (int j = 1; j < 9; j++)
                damage[piece.x][j] = damage[j][piece.y] = -1;
            int ix = piece.x, iy = piece.y;
            while (ix >= 1 && iy >= 1)
            {
                damage[ix][iy] = -1;
                ix -= 1;
                iy -= 1;
            }
            while (ix <= 8 && iy <= 8)
            {
                damage[ix][iy] = -1;
                ix += 1;
                iy += 1;
            }
            break;
        }
        case 'R':
        {
            a[piece.x][piece.y] = 'R';
            for (int j = 1; j < 9; j++)
                damage[piece.x][j] = damage[j][piece.y] = -1;
            break;
        }
        case 'B':
        {
            a[piece.x][piece.y] = 'B';
            int ix = piece.x, iy = piece.y;
            while (ix >= 1 && iy >= 1)
            {
                damage[ix][iy] = -1;
                ix -= 1;
                iy -= 1;
            }
            while (ix <= 8 && iy <= 8)
            {
                damage[ix][iy] = -1;
                ix += 1;
                iy += 1;
            }
            break;
        }
        case 'N':
        {
            a[piece.x][piece.y] = 'N';
            damage[piece.x][piece.y] = -1;
            knightValues[0].x = 1, knightValues[0].y = 2;
            knightValues[1].x = 1, knightValues[1].y = -2;
            knightValues[2].x = -1, knightValues[2].y = 2;
            knightValues[3].x = -1, knightValues[3].y = -2;
            knightValues[4].y = 1, knightValues[4].x = 2;
            knightValues[5].y = 1, knightValues[5].x = -2;
            knightValues[6].y = -1, knightValues[6].x = 2;
            knightValues[7].y = -1, knightValues[7].x = -2;
            for (int j = 0; j < 8; j++)
                damage[piece.x + knightValues[j].x][piece.y + knightValues[j].y] = -1;
            break;
        }
        case 'P':
        {
            a[piece.x][piece.y] = 'P';
            damage[piece.x][piece.y] = damage[piece.x + 1][piece.y + 1] = damage[piece.x - 1][piece.y + 1] = -1;
        }
        }
    }
    string situation;
    if (damage[rege.x][rege.y] == -1)
    {
        if (sePoateMisca(rege.x, rege.y))
            situation = "CHECK";
        else
            situation = "CHECKMATE";
    }
    else
    {
        if (sePoateMisca(rege.x, rege.y))
            situation = "SAFE";
        else
            situation = "STALEMATE";
        
    }
    //cout << '\n';
    //showMatrix();
    //cout << '\n';
    //showDamage();
    return situation;
}

int main()
{
    string s;
    getline(cin, s);
    cout << find_king_status(s);
    return 0;
}