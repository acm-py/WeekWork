#include <cstdio>

int main()
{
	unsigned int m, n, x, y, t;
	while(scanf("%u%u",&m,&n) != EOF)
	{
		// 为了保证下面循环时，能够 i <= n能够完整遍历
		if (m > n)
		{
			i = n;
			n = m;
			m = i;
		}
		x = y = 0;
		for (i = m; i <= n; i++)
			(i & 1)?(y += i*i*i):(x += i*i);
		printf("%u %u", x, y);
	}
	return 0;
}