//��������������
int Max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
//�򵥵�˼·�����Ǵ��������봿ż������ȣ����ǲ���ѽ
//
int rob(int* nums, int numsSize){
    int sumOdd = 0;
	int sumEven = 0;

	for (int i = 0; i < numsSize; i++)//������������
	{
		if (i % 2 == 0)//�������±�Ϊż��
		{
			sumEven += nums[i];//����ż����
			sumEven = Max(sumOdd, sumEven);//������߽�ȡ���ֵ
		}
		else//�±�Ϊ����ʱ
		{
			sumOdd += nums[i];
			sumOdd = Max(sumOdd, sumEven);
		}
	}
	return Max(sumOdd, sumEven);
}
