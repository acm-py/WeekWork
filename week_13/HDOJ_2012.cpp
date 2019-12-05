#include <cstdio>
#include <cmath>

int prime_number(int n)
{
	int j = 0;
	for (j = 2; j < n; j++)
	{
		if(n%j == 0)
			return 0;
	}
	return 1;
}
int main(void)
{
	int x, y, n, count = 0;
	// 题目给了输入： -39<=x<=50，y也是
	while(scanf("%d%d",&x, &y) != EOF)
	{
		count = 0;
		if(x == 0 && y == 0)
			break;
		else
		{
			for(int i = x; i <= y; i++)
			{
				// 题目所给的表达式
				n = i*i+i+41;
				if(prime_number(n))
					count++;
			}
			// 遍历完成
			if(count == y-x+1)
				printf("OK\n");
			else
				printf("Sorry\n");
		}
	}
	return 0;
}