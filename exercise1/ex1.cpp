#include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <stdio.h>
#define BSIZE 1<<15
using namespace std;

char buffer[BSIZE];
long bpos = 0L, bsize = 0L;

long readLong() 
{
	long d = 0L, x = 0L;
	char c;
	while (1)  {
		if (bpos >= bsize) {
			bpos = 0;
			if (feof(stdin)) return x;
			bsize = fread(buffer, 1, BSIZE, stdin);
		}
		c = buffer[bpos++];
		if (c >= '0' && c <= '9') { x = x*10 + (c-'0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}
struct home
{
	long x = 0;
	long y = 0;
	long long x_distance = 0;
	long long y_distance = 0;
};
bool sort_x (const home& a, const home& b)
{
	return (a.x < b.x);
}
bool sort_y (const home& a, const home& b)
{
	return (a.y < b.y);
}
int main ()
{
	long n;
	n=readLong();
	vector<home> myVector;
	for (long i = 0; i < n ; i++)
	{
		myVector.push_back(home());
		myVector[i].x=readLong();
		myVector[i].y=readLong();
	}
	sort(myVector.begin(), myVector.end(), sort_x);
	for (long i = 0; i < n; i++)
	{
		cout<< myVector[i].x << " " ;
		myVector[0].x_distance = myVector[0].x_distance + abs(myVector[i].x - myVector[0].x);
	}
	for (long i = 1; i < n; i++)
	{
		myVector[i].x_distance = myVector[i-1].x_distance + (2 * i - n) * (myVector[i].x - myVector[i - 1].x);
		//cout << i << ": " << myVector[i].x_distance << endl;
	}

	sort(myVector.begin(), myVector.end(), sort_y);
	for (long i = 0; i < n; i++)
	{
		myVector[0].y_distance = myVector[0].y_distance + abs(myVector[i].y - myVector[0].y);
	}
	long long min=myVector[0].x_distance + myVector[0].y_distance;

	for (long i = 1; i < n; i++)
	{
		myVector[i].y_distance = myVector[i-1].y_distance + (2 * i - n) * (myVector[i].y - myVector[i - 1].y);
		if ((myVector[i].x_distance + myVector[i].y_distance) < min)
			min = myVector[i].x_distance + myVector[i].y_distance;
	}
	cout << min << endl;
}