
# 数组拆分  

给定长度为 2n 的数组, 你的任务是将这些数分成 n 对,  
例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从1 到 n 的 min(ai, bi) 总和最大。

## 示例：

``` chameleon
输入: [1,4,3,2]
输出: 4
解释: n 等于 2, 最大总和为 4 = min(1, 2) + min(3, 4).
```
##提示：
```chameleon
1.n 是正整数,范围在 [1, 10000].
2.数组中的元素范围在 [-10000, 10000].
 ```
>个人所想：就是把数组排序一下，然后，从第0个开始每隔两个求和。 
代码如下： 
``` chameleon
int arrayPairSum(int* nums, int numsSize)
{
    int i,j,k,t,sum = 0;
    for(i = 0; i < numsSize - 1; i++)
    {
        for(j = 0; j < numsSize - 1 -i; j++)
        {
            if(nums[j] > nums[j + 1])
            {
                t = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = t;
            }
        }
    }
    for(k = 0;k < numsSize;)
    {
        sum += nums[k];
        k += 2;
    }
    return sum;
}
```
然而，结果提交时，~~出错~~。  
出错显示：
``` c
“超出时间限制”
```
用了C语言内置的函数：  
代码：  
```chameleon
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;   //由小到大排序
    //return *(int*)b - *(int*)a;   由大到小排序
}
int arrayPairSum(int* nums, int numsSize){
    int i,sum = 0;
    qsort(nums, numsSize, sizeof(nums[0]), cmp);
    for(i = 0; i < numsSize; i += 2)
    {
        sum += nums[i];
    }
    return sum;
}
```
结果：
```chameleon
执行结果：通过
执行用时:92 ms
在所有 c 提交中击败了31.48%的用户
内存消耗:9.9 MB
在所有 c 提交中击败了21.67%的用户
```
*** 
最后的最后，评论区大佬的代码：

```  chameleon
/*
思路：
排序，然后将下标为 0、2、4 ... 个数相加即可。
由于是纯数字，并且限定了数字范围，所以可使用基数排序达到 O(n) 复杂度。
数字范围 [-10000, 10000]，所以可创建 n[20001]，对每个元素加 10000 使其变为正数。
*/
int arrayPairSum(int* nums, int numsSize)
{
	int n[20001] = { 0 }, i, j, sum;
	for (i = 0; i < numsSize; i++)					//建立值、键哈希表，即基数排序
		n[nums[i] + 10000]++;						//保证下标为正数
	for (i = j = sum = 0; i < 20001; )				//将下标为 0、2、4 ... 的相加
	{	
		if (n[i])									//判断是否存在该数，若存在则判断是否偶数下标
		{
			if (j % 2 == 0)	sum += i - 10000;		//偶数下标，累加
			j++;									//计数
			n[i]--;									//该值减 1
		}
		else	i++;								//不存在，跳过该值
	}
	return sum;
}
```
