#include <cstdio>
#include <cmath>
int main(void)
{
	int x;
	while(scanf("%d",&x)!=EOF)
	{
		if(r < 0)
			puts("Score is error!");
		else if (x < 60)
			puts("E");
		else if (x < 70)
			puts("D");
		else if (x < 80)
			puts("C");
		else if (x < 90)
			puts("B");
		else if (x < 100)
			puts("A");
		else
			puts("Score is error!");
	}
	return 0;
}

