/*
写以下函数，并在主函数中调用
1、输入一组整型数
2、对其排序
3、输出结果 
*/ 

#include <stdio.h>

void input(int A[],int n)    //定义一个一维数组的输入函数
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
