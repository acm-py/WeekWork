#include<stdio.h> 
//如果一个数组的总和非负，
//那么一定可以找到其中找到一个点开始，
//累加和一直都是非负的
//基于上面的定理可以得到，
//那就是如果累加和大于等于0，
//肯定会有一个点存在；反之不存在。
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int i=0,gas_sum=0,cost_sum=0;
    int start=0,sum=0;
//若耗油量大于总油量，则不可能完成 
    for(i=0;i<gasSize;i++)
    {
    gas_sum+=gas[i];
    cost_sum+=cost[i];
    }
    if(cost_sum>gas_sum)
    {
    	start=-1;
		printf("%d",start);
        return start;
    }
//排除特殊情况后，按数学定理来 
    else
    {
    	start=0;
        for (i= 0; i < gasSize; i++)
        {
            sum = gas[i] - cost[i];
            if (sum < 0)
            {
                sum = 0;
                start = i + 1;
            }
        }
        printf("%d",start);
        return  start;
    }
    
}
int main()
{
	int* a;
	int* b; 
    int n,i=0,k=0,z=0;
    printf("请输入两个数组的长度(两数组长度相等)\n"); 
    scanf("%d",&n);
    z=n;
      a = (int*)malloc(sizeof(int)*n);
      b = (int*)malloc(sizeof(int)*z);
       printf("输入数组a数据，以空格间隔，以回车结束\n"); 
        while(1) 
    { 
        scanf("%d",&a[i++] );    
        if( getchar() == '\n') 
        { 
            break; 
        } 
    }
	i=0;
    printf("输入数组b数据，以空格间隔，以回车结束\n"); 
        while(1) 
    { 
        scanf("%d",&b[i++] );    
        if( getchar() == '\n') 
        { 
            break; 
        } 
    }
    printf("返回加油站的编号为:");
  canCompleteCircuit(a, n, b, z);
    // for(i=0;i<n;i++)
    // {
    //	printf("%d,",a[i]);
    //	printf("%d\n",b[i]);
	//	}
} 

