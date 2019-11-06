/*
����һ��ȷ��Ϊɽ�������飬�����κ�����?A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]?�� i?��ֵ��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/peak-index-in-a-mountain-array
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 

#include <stdio.h>

int F(int *A, int ASize)
{
	int i = 0, r = ASize - 1;
	while (i+1 < r)  //�ж�����Ϊ  (i+1 < r) ��Ϊ���ų�������ֻ������Ԫ�ص���� 
	{
		int mid = (i + r)/2;
		if (A[mid+1] > A[mid])
		{
			i = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	return (i==r || A[i]>A[i+1])?i:r;
 } 
 
 int main()
 {
 	int i = 0,n,A[20];
 	printf("����������ĸ�����");
 	scanf("%d",&n);
 	printf("������һ������\n");
 	for (i = 0; i < n; i++)
 	{
 		scanf("%d",&A[i]);
	}
 	printf("%d",F(A,n));
 	return 0;
 }
