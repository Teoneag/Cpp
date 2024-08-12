#include <fstream>
using namespace std;
ifstream cin("a.in");
ofstream cout("a.out");

int nrmatches, nrplayers, scoremax, idscoremax;

struct gameinfo
{
    int idplayer1, scoreplayer1, idplayer2, scoreplayer2;
} g[3000];


void read()
{
    cin>>nrmatches>>nrplayers;
    for (int i=0; i<nrmatches; i++) cin>>g[i].idplayer1>>g[i].scoreplayer1>>g[i].idplayer2>>g[i].scoreplayer2;
}

void highestScore()
{
    for (int i=0; i<nrmatches; i++)
    {
        if(g->scoreplayer1>scoremax) {scoremax=g[i].scoreplayer1, idscoremax=g[i].idplayer1;}
        if(g->scoreplayer2>scoremax) {scoremax=g[i].scoreplayer2, idscoremax=g[i].idplayer2;}
    }
}

void show()
{
    cout<<idscoremax<<" "<<scoremax;
}


int main()
{
    read();
    highestScore();
    show();
    return 0;
}