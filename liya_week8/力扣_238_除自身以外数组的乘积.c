#include<stdio.h> 


void productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int  res[numsSize];
    *returnSize = numsSize;                                                                          
    int k = 1;     //先从右向左历遍，将向res中存储num[i]中左边各数的乘积
    int i=0;
    for(i = 0; i <numsSize; i++)
    {
        res[i] = k;
        k = k * nums[i];        // 此时数组存储的是除去当前元素左边的元素乘积
    }    
        k = 1;
                                //再从左向右历遍，向res[i]存储num[i]左边各数成绩乘以右边各数乘积
        for(i = numsSize - 1; i >= 0; i--)
        {
            res[i] *= k;          // k为该数右边的乘积。
            k *= nums[i];           // 此时数组等于左边的 * 该数右边的。
        }
    for(i=0;i<numsSize;i++)
    {
       // nums[i]=res[i];
        printf("%d, ",res[i]);
    }    
        
}
int main()
{
	printf("请输入要进行计算的数组元素个数\n");
	int numsSize,returnSize=0;
	scanf("%d",&numsSize);
	int nums[numsSize];
	int *a=nums;
	printf("请输入要进行计算的数组元素(仅数字)\n");
	int i=0;
	for(i=0;i<numsSize;i++)
	{
		scanf("%d",&nums[i]);	
	}
	printf("计算除自身以外数组的乘积(不能使用除法)\n");
	productExceptSelf(a,numsSize,&returnSize);
	return 0; 
	 
	 
	
}
