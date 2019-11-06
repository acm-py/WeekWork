/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素
*/ 

#include <stdio.h>

int one(int *a, int len)
{
	int i, j, k, r=0;
	if(len == 1)
	{
		return a[0];	
	}	
	for(i=0;i<len;i++)
	{
		for(j=0;j<len;j++)
		{
			if(a[i] == a[j] && i != j)
			{
				r = 0;
				break;
			}
			else if(a[i] != a[j])
			{
				k = a[i];
				r = 1;
			}
		}
		if(r == 1)
			break;
	}
	return k;
} 

int main()
{
	int a[10] = {2,2,3,2};
	printf("只出现一次的数字是：");
	printf("%d",one(a,4)); 
}
