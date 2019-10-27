#include <stdio.h>

int main()
{
	int i, j;
	int sum = 0; 
	printf("请输入一组大于零的数，并以0为结束输入符！\n");
	for(j=1;;j++) 
	{
		printf("请输入第%d个大于零的整数：",j);
		scanf("%d",&i);
		if(i != 0)
		{
			sum += i;
		} 
		else
		{
			break;
		}
	}
	printf("输入的整数和为%d\n",sum); 
	return 0;
} 
