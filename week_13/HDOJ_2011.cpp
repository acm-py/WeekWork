#include <cstdio>
#include <cmath>
// 看清输出要求，要不然连错三次!!!!!
/*
根据题目描述:
多项式是这样组成的。分奇偶性。
奇数是+
偶数是-
考虑采用递归或者迭代

 */
// 迭代版本如下
int main()
{
	int m, n;
	int i;
	double sum;
	scanf("%d",&m);
	for(;m > 0; m--)
	{
			while(scanf("%d",&n)!= EOF)
		{
			sum = 0.00;
			for(i = 1; i <= n; i++)
				sum += ((i&1)? 1.0:-1.0) / i;
			printf("%.2lf\n",sum);
		}
	}

	return 0;
}
/*
递归版本如下：

 */

#include <cstdio>

int n;

double rev(int c)
{
    return c <= n ?( ((c & 1) ? 1.0 : -1.0) / c + rev(c + 1) ): 0 ;
}

int main()
{
    int t;

    scanf("%d", &t);
    while (t-- && scanf("%d", &n))
        printf("%.2lf\n", rev(1));

    return 0;
}
			
				
 
