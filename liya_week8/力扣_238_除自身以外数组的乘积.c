#include<stdio.h> 


void productExceptSelf(int* nums, int numsSize, int* returnSize)
{
    int  res[numsSize];
    *returnSize = numsSize;                                                                          
    int k = 1;     //�ȴ����������飬����res�д洢num[i]����߸����ĳ˻�
    int i=0;
    for(i = 0; i <numsSize; i++)
    {
        res[i] = k;
        k = k * nums[i];        // ��ʱ����洢���ǳ�ȥ��ǰԪ����ߵ�Ԫ�س˻�
    }    
        k = 1;
                                //�ٴ����������飬��res[i]�洢num[i]��߸����ɼ������ұ߸����˻�
        for(i = numsSize - 1; i >= 0; i--)
        {
            res[i] *= k;          // kΪ�����ұߵĳ˻���
            k *= nums[i];           // ��ʱ���������ߵ� * �����ұߵġ�
        }
    for(i=0;i<numsSize;i++)
    {
       // nums[i]=res[i];
        printf("%d, ",res[i]);
    }    
        
}
int main()
{
	printf("������Ҫ���м��������Ԫ�ظ���\n");
	int numsSize,returnSize=0;
	scanf("%d",&numsSize);
	int nums[numsSize];
	int *a=nums;
	printf("������Ҫ���м��������Ԫ��(������)\n");
	int i=0;
	for(i=0;i<numsSize;i++)
	{
		scanf("%d",&nums[i]);	
	}
	printf("�����������������ĳ˻�(����ʹ�ó���)\n");
	productExceptSelf(a,numsSize,&returnSize);
	return 0; 
	 
	 
	
}
