#include<stdio.h>
//位运算^（按位异或运算）所有出现两次的元素都抵消，最后剩一个出现一次的
//参与^运算两个二进制位不同时，结果为 1，相同时结果为 0。例如0^1为1，0^0为0，1^1为0。
int singleNumber(int* nums, int numsSize){
int result = nums[0];
int i=1; 
	for (i = 1; i < numsSize; i++)
	{
		result ^= nums[i];
	}
	printf("只出现一次的数字是: %d\n",result);
	return result;

}
 
void main()
{
	int* a;
    int n,i=0,k=0;
    printf("请输入数组长度,不能为0\n"); 
    scanf("%d",&n);   
      a = (int*)malloc(sizeof(int)*n);
       printf("输入数组数据，以空格间隔，以回车结束\n"); 
        while(1) 
    { 
        scanf("%d",&a[i++] );    
        if( getchar() == '\n') 
        { 
            break; 
        } 
    }
    singleNumber(a, n);
}
