/*
leetcode_7_������ת
 
����һ�� 32 λ���з�������������Ҫ�����������ÿλ�ϵ����ֽ��з�ת��

������
   ��ת�����ǰ���������һ�� ����Сλ������λ 
*/ 

#include <stdio.h>
#include <math.h>

int reverse(int x)
{	
	long int r = 0;
	//���������� 
	while(x != 0)
	{
		r = 10*r + x%10;
		x = x/10;	
	} 
	//�ж� �����Ƿ񳬳���Χ
	if(r > pow(2,31)-1 || r < -pow(2,31))
		return 0;   //���������Χֱ�ӷ���
	return r;   // ����  ���ú���� 
} 

int main(void)
{
	long int i;
	printf("������һ������:");
	scanf("%d",&i);
	printf("��תǰ������ֵ��:%d\n",i);
	
	printf("��ת֮�������ֵ�ǣ�%d\n",reverse(i));
	
	return 0;
}
