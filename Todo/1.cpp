#include <iostream>
using namespace std;

class Point
{
public:
	int x, y, nr;
	Point *a = 0, *b = 0, *c = 0, *d = 0;
	Point()
	{
		this->nr = 0;
		this->a = nullptr;
		this->b = nullptr;
		this->c = nullptr;
		this->d = nullptr;
	}
	Point(int x, int y, int nr)
	{
		this->x = x;
		this->y = y;
		this->nr = nr;
		this->a = nullptr;
		this->b = nullptr;
		this->c = nullptr;
		this->d = nullptr;
	}
};

main()
{
	int k, n, x, y;
	cin >> k >> n;
	if (n == 0)
	{
		cout << 0000;
		return 0;
	}

	cin >> x >> y;
	Point *rootNode = new Point(x, y, 1);
	Point *kthNode = new Point();
	Point *curNode = rootNode;
	if (k == 1)
		kthNode = rootNode;

	for (int i = 2; i <= n; i++)
	{
		cin >> x >> y;
		Point *newNode = new Point(x, y, i);
		if (x > curNode->x)
		{
			if (y > curNode->y)
				curNode->a = newNode;
			else
				curNode->d = newNode;
		}
		else
		{
			if (y > curNode->y)
				curNode->b = newNode;
			else
				curNode->c = newNode;
		}
		if (i == k)
			kthNode = newNode;
		curNode = newNode;
	}
	cout << kthNode->nr << ' ' << kthNode->x << ' ' << kthNode->y << '\n';
	cout << kthNode->a->nr << '\n';
	cout << kthNode->d->nr << '\n';
	Point *aNode = new Point();
	Point *bNode = new Point();
	Point *cNode = new Point();
	Point *dNode = new Point();
	aNode = kthNode->a;
	bNode = kthNode->b;
	cNode = kthNode->c;
	dNode = kthNode->d;
	cout << aNode->nr << ' ' << bNode->nr << ' ' << cNode->nr << ' ' << dNode->nr;
	// cout << kthNode->a->nr << kthNode->b->nr << kthNode->c->nr << kthNode->d->nr << '\n';
	return 0;
} // 1 7 4 4 8 9 2 2 6 6 10 -1 11 2 10 1