/*
����һ���ǿ��������飬����ĳ��Ԫ��ֻ����һ�����⣬����ÿ��Ԫ�ؾ����������Ρ��ҳ��Ǹ�ֻ������һ�ε�Ԫ��
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
	printf("ֻ����һ�ε������ǣ�");
	printf("%d",one(a,4)); 
}
