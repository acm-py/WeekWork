#include<stdio.h> 
//���һ��������ܺͷǸ���
//��ôһ�������ҵ������ҵ�һ���㿪ʼ��
//�ۼӺ�һֱ���ǷǸ���
//��������Ķ�����Եõ���
//�Ǿ�������ۼӺʹ��ڵ���0��
//�϶�����һ������ڣ���֮�����ڡ�
int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize)
{
    int i=0,gas_sum=0,cost_sum=0;
    int start=0,sum=0;
//���������������������򲻿������ 
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
//�ų���������󣬰���ѧ������ 
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
    printf("��������������ĳ���(�����鳤�����)\n"); 
    scanf("%d",&n);
    z=n;
      a = (int*)malloc(sizeof(int)*n);
      b = (int*)malloc(sizeof(int)*z);
       printf("��������a���ݣ��Կո������Իس�����\n"); 
        while(1) 
    { 
        scanf("%d",&a[i++] );    
        if( getchar() == '\n') 
        { 
            break; 
        } 
    }
	i=0;
    printf("��������b���ݣ��Կո������Իس�����\n"); 
        while(1) 
    { 
        scanf("%d",&b[i++] );    
        if( getchar() == '\n') 
        { 
            break; 
        } 
    }
    printf("���ؼ���վ�ı��Ϊ:");
  canCompleteCircuit(a, n, b, z);
    // for(i=0;i<n;i++)
    // {
    //	printf("%d,",a[i]);
    //	printf("%d\n",b[i]);
	//	}
} 

