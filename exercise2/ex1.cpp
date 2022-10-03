#include <bits/stdc++.h>
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
		if (c >= '0' && c <= '9') { x = x * 10 + (c - '0'); d = 1; }
		else if (d == 1) return x;
	}
	return -1;
}
//	GOT HELP BY GEEK_FOR_GEEKS PAGE
int main ()
{
	long n, l;
	n = readLong();
	l = readLong();
	long c[n];
	for (int i = 0; i < n; ++i)
		c[i] = readLong();
	long profit[2][n + 1];
	for (long i = 0; i <= 2; i++)
		profit[i][0] = 0;
	for (long j = 0; j <= n; j++)
		profit[0][j] = 0;
	for (long i = 1; i <= l; i++)
	{
		long cheaper = LONG_MIN;
		for (long j = 1; j < n; j++)
		{
			cheaper = max(cheaper, profit[(i - 1) % 2][j - 1] - c[j - 1]);
			profit[i % 2][j] = max(profit[i % 2][j - 1], c[j] + cheaper);
		}
	}
	cout << profit[l % 2][n - 1] << endl;
}