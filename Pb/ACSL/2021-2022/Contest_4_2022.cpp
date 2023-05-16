#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

struct NrR
{
	double r = 0, i = 0;
} c, x;

NrR f[500];
int nrEscapes, n;

double rou(double x)
{
	return round(x * 100) / 100.0;
}

NrR rou(NrR x)
{
	x.r = rou(x.r);
	x.i = rou(x.i);
	return x;
}

NrR add(NrR a, NrR b)
{
	NrR s;
	s.r = a.r + b.r;
	s.i = a.i + b.i;
	return rou(s);
}

NrR mul(NrR a, NrR b)
{
	NrR m;
	m.r = a.r * b.r - a.i * b.i;
	m.i = a.i * b.r + a.r * b.i;
	return rou(m);
}

double abs(NrR x)
{
	return rou(sqrt(x.r * x.r + x.i * x.i));
}

int find(NrR x)
{
	for (int j = 0; j < n; j++)
		if (f[j].r == x.r && f[j].i == x.i)
			return j;
	return 0;
}

string cycleLength(float realPartC, float imagPartC)
{
	c.r = realPartC, c.i = imagPartC;
	while (1)
	{
		if (abs(x) > 4)
			return "ESCAPES " + to_string(nrEscapes);
		if (find(x))
			return to_string(nrEscapes - find(x));
		nrEscapes++;
		f[n++] = x;
		x = add(mul(x, x), c);
	}
}

int main()
{
	float realPartC, imagPartC;
	cin >> realPartC >> imagPartC;
	cout << cycleLength(realPartC, imagPartC);
}
