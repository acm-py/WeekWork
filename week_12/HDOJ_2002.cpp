#include <cstdio>
#include <cmath>
#define PI 3.1415927
int main(void)
{
	double r;
	// 上次报错，nm 写成中文的感叹号了，查了半天没查除了。日
	while(scanf("%lf", &r) != EOF)
		// 这里必须用4.0
		printf("%.3f\n",4.0*PI*r*r*r/3.0);
	return 0;
}