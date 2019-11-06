/*
给定一个确定为山脉的数组，返回任何满足?A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]?的 i?的值。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/peak-index-in-a-mountain-array
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

#include <stdio.h>

int F(int *A, int ASize)
{
	int i = 0, r = ASize - 1;
	while (i+1 < r)  //判断条件为  (i+1 < r) 是为了排除数组中只有两个元素的情况 
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
 	printf("请输入数组的个数：");
 	scanf("%d",&n);
 	printf("请输入一组数：\n");
 	for (i = 0; i < n; i++)
 	{
 		scanf("%d",&A[i]);
	}
 	printf("%d",F(A,n));
 	return 0;
 }
