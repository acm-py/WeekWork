/*
除了1和该数自身外，无法被其他自然数整除的数 --素数 
*/ 

#include <stdio.h>

int main()
{
	int i, j;
	for (i = 2; i <= 100; i++)
	{
		for(j = 2; j < i; j++)  // 判断 i 是否为素数 
		{
			if(i % j == 0)    //取余数， 若余数为 0 （能整除） 则结束循环 
				break;     //用来终止循环 
		}
		if (i == j)
		{
			printf("%5d",i);
		}
	}
	return 0;
} 
