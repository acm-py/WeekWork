#include <stdio.h>

int fib(int N)
{
    if (N == 0 || N == 1)
    {
        return N;
    }
    return fib(N-1) + fib(N-2);

}

int main(void)
{
	int i;
	printf("请输入你想知道第几个斐波那契数：");
	scanf("%d",&i);
	printf("你想知道的斐波那契数是：%d\n",fib(i));
	return 0;
}
