//返回其中最大的数
int Max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
}
//简单的思路，就是纯奇数和与纯偶数和相比，但是不对呀
//
int rob(int* nums, int numsSize){
    int sumOdd = 0;
	int sumEven = 0;

	for (int i = 0; i < numsSize; i++)//历遍整个数组
	{
		if (i % 2 == 0)//当数组下标为偶数
		{
			sumEven += nums[i];//计算偶数和
			sumEven = Max(sumOdd, sumEven);//更新最高金额，取最大值
		}
		else//下标为奇数时
		{
			sumOdd += nums[i];
			sumOdd = Max(sumOdd, sumEven);
		}
	}
	return Max(sumOdd, sumEven);
}
