#include<stdio.h>
//λ����^����λ������㣩���г������ε�Ԫ�ض����������ʣһ������һ�ε�
//����^��������������λ��ͬʱ�����Ϊ 1����ͬʱ���Ϊ 0������0^1Ϊ1��0^0Ϊ0��1^1Ϊ0��
int singleNumber(int* nums, int numsSize){
int result = nums[0];
int i=1; 
	for (i = 1; i < numsSize; i++)
	{
		result ^= nums[i];
	}
	printf("ֻ����һ�ε�������: %d\n",result);
	return result;

}
 
void main()
{
	int* a;
    int n,i=0,k=0;
    printf("���������鳤��,����Ϊ0\n"); 
    scanf("%d",&n);   
      a = (int*)malloc(sizeof(int)*n);
       printf("�����������ݣ��Կո������Իس�����\n"); 
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
