#include <stdio.h>

int main()
{
	int i, j;
	int sum = 0; 
	printf("������һ����������������0Ϊ�����������\n");
	for(j=1;;j++) 
	{
		printf("�������%d���������������",j);
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
	printf("�����������Ϊ%d\n",sum); 
	return 0;
} 
