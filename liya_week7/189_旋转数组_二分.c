//以1234567为例，K为3 
//数组反转，先转1234为4321以及567为765
//再转4321765为5671234
#include<stdio.h>
void  swap(int *x, int *y)
{
    int  temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void rotate(int* nums, int numsSize, int k)
{
if(k>numsSize)
    {
        k=k%numsSize;
    }
    if(k==0)
    {
    //    return nums;
    exit(0); 
      
    }
    //先转1234
    int i=0;
    for( i=0;i<(numsSize-k)/2;i++)
    {
        swap(&nums[i],&nums[numsSize-k-i-1]);
    }
    //再换567
    for( i=0;i<k/2;i++)
    {
        swap(&nums[numsSize-i-1],&nums[numsSize-k+i]);
    }
    //全体反转
    for( i=0;i<numsSize/2;i++)
    {
        swap(&nums[i],&nums[numsSize-i-1]);
    }
    
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
	printf("输入您想翻转的数组长度\n");
	scanf("%d",&k);
	rotate( a, n, k);
	printf("数组翻转后为\n");
	int x=0;
	for( x=0;x<n;x++)
	{
		printf("%d,",a[x]);
	}
	
}
