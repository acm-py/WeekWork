#include <cstdio>
#include <cmath>

int main()
{
	double n;
	int m, i;
	while (scanf("%lf%d", &n, &m) != EOF)
	{
		double sum = 0;
		for (i = 0; i < m; i++)
		{
			sum += n;
			n = sqrt(n);
		}
		printf("%.2f\n", sum);
	}

	return 0;
}