/*
��ֵԪ����ָ��ֵ������������ֵ��Ԫ�ء�

����һ����������?nums������ nums[i] �� nums[i+1]���ҵ���ֵԪ�ز�������������

������ܰ��������ֵ������������£������κ�һ����ֵ����λ�ü��ɡ�

����Լ���?nums[-1] = nums[n] = -�ޡ�
*/ 
#include <stdio.h>

int F(int *nums, int n)
{
    if(n <= 1)  //����Ԫ��Ϊһʱ��ֱ�ӷ��� 
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
	printf("����һ��һά���飬��������Ԫ�ز���ȣ�\n");
	printf("����������ĸ�����");
	scanf("%d",&n);
	printf("�����������Ԫ�أ�\n");
	for (i = 0; i < n; i++)
	{
		scanf("%d",&A[i]);
	}
	printf("�����еķ�ֵ��λ����%d\n",F(A,n)); 
	
	return 0;
}
