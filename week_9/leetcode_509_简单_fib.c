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
	printf("����������֪���ڼ���쳲���������");
	scanf("%d",&i);
	printf("����֪����쳲��������ǣ�%d\n",fib(i));
	return 0;
}
