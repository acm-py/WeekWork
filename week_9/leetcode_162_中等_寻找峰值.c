/*
峰值元素是指其值大于左右相邻值的元素。

给定一个输入数组?nums，其中 nums[i] ≠ nums[i+1]，找到峰值元素并返回其索引。

数组可能包含多个峰值，在这种情况下，返回任何一个峰值所在位置即可。

你可以假设?nums[-1] = nums[n] = -∞。
*/ 
#include <stdio.h>

int F(int *nums, int n)
{
    if(n <= 1)  //数组元素为一时，直接返回 
        return 0;
    int m = 0,i;
    for (i = 1; i < n - 1; i++)
    {
        if(nums[i] > nums[i-1] && nums[i] > nums[i+1])
        {
            m = i;
            break;
        }
    }
    if(m == 0 && nums[n - 1] > nums[n - 2])
        m = n - 1;
    return m;
}	

int main(void)
{
	int A[10];
	int i,n;
	printf("创建一个一维数组，并且相邻元素不相等！\n");
	printf("请输入数组的个数：");
	scanf("%d",&n);
	printf("请输入数组的元素：\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&A[i]);
	}
	printf("数组中的峰值的位置是%d\n",F(A,n)); 
	
	return 0;
}
