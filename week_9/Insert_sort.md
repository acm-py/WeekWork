#include <stdio.h>
/*
  title:插入排序
  tags:排序

代码实现:C

 插入排序:给定一数组A，数组含有n个元素，将每个数与该数之前的数进行比较大小并插入到对应的(大或小)位置，
进行排序，算法时间复杂度为O(n^2).
*/

//插入排序算法(逆序)
void Insertion_sort(int *A,int len)
{
	int j=2;
                for(j=2;j<len;j++)
	{
		int key=A[j];记录第j个数的值同时将该数与之前的各个数进行比较
		int i=j-1;
		while(i>0&&A[i]<key)//直到遇到A[j]>A[i]或i==0时(此时意味着A[j]最大应放首位)，对应要插入的位置空出来，数组后面的数集体后移一位
		{
                                   A[i+1]=A[i];
		   i=i-1;
		}
		A[i+1]=key;//完成插入操作
	}
}
//打印数组A
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
