#include <stdio.h>
/*
  title:��������
  tags:����

����ʵ��:C

 ��������:����һ����A�����麬��n��Ԫ�أ���ÿ���������֮ǰ�������бȽϴ�С�����뵽��Ӧ��(���С)λ�ã�
���������㷨ʱ�临�Ӷ�ΪO(n^2).
*/

//���������㷨(����)
void Insertion_sort(int *A,int len)
{
	int j=2;
                for(j=2;j<len;j++)
	{
		int key=A[j];��¼��j������ֵͬʱ��������֮ǰ�ĸ��������бȽ�
		int i=j-1;
		while(i>0&&A[i]<key)//ֱ������A[j]>A[i]��i==0ʱ(��ʱ��ζ��A[j]���Ӧ����λ)����ӦҪ�����λ�ÿճ����������������������һλ
		{
                                   A[i+1]=A[i];
		   i=i-1;
		}
		A[i+1]=key;//��ɲ������
	}
}
//��ӡ����A
void print_A(int *A,int len)
{
	int i=0;
	for(i=0;i<len;i++)
	  printf("%d ",A[i]);
}
int main(int argc, char *argv[])
{
	int A[]={5,2,6,4,1,3};
	Insertion_sort(A,sizeof(A)/sizeof(A[0]));
	print_A(A,sizeof(A)/sizeof(A[0]));
	return 0;
}
