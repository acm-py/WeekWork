#include <cstdio>
#include <cmath>
int main(void)
{
	double x;
	while(scanf("%lf",&x) !=EOF)
		// 这里要采用fabs 保证双精度.
		printf("%.2lf\n",fabs(x));
	return 0;
}