/*
д���º����������������е���
1������һ��������
2����������
3�������� 
*/ 

#include <stdio.h>

void input(int A[],int n)    //����һ��һά��������뺯��
{
	int i;
	
	for(i = 0;i < n;i++)
	{
		printf("A[%d] = ",i);
		scanf("%d",&A[i]);
	}
} 

void sort(int A[],int n)
{
	int i,j,t;
	
	for(i = 0;i < n - 1;i++)
	    for(j = 0;j < n-i-1;j++)
	        if(A[j] > A[j+1])
	        {
	        	t = A[j];
	        	A[j] = A[j+1];
	        	A[j+1] = t;
			}
}

void output(int A[],int n)
{
	int i;
	for(i = 0;i < n;i++)
	    printf("%5d",A[i]);
	printf("\n");
}

int main()
{
	int A[20],n;
	printf("Please inter n:");
	scanf("%d",&n);
	
	input(A,n);
	sort(A,n);
	output(A,n);
	
	return 0;
}
