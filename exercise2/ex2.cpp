#include <bits/stdc++.h>
#define BSIZE 1<<15
using namespace std;

char buffer[BSIZE];
long long bpos = 0L, bsize = 0L;
long long readLong()
{
	long long d = 0L, x = 0L;
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
int main()
{
	int n, a, b, c;
	n = readLong();
	a = readLong();
	b = readLong();
	c = readLong();
	a = -a;
	c = -c;
	int x[n];
	for (int i = 0; i < n; ++i)
	{
		x[i] = readLong();
	}
	long long maxnumber[n + 1], sum[n + 1];
	sum[0] = 0;
	for (int i = 1; i <= n ; ++i)
	{
		sum[i] = sum[i - 1] + x[i - 1];
	}
	maxnumber[0] = 0;
	long long result, temp;
	for (int i = 1; i <= n; ++i)
	{
		result = LONG_MIN;
		for (int j = i - 1; j >= 0 ; --j)
		{
			temp = (a * (sum[i] - sum[j]) * (sum[i] - sum[j]) + b * (sum[i] - sum[j]) + c) + maxnumber[j];
			result = max(result, temp );
		}
		maxnumber[i] = result;
	}
	cout <<maxnumber[n]<<endl;
}