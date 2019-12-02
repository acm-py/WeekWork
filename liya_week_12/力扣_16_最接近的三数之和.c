/*首先对数组进行排序
之后使用数组下标i来历遍整个数组，用right=i+1 left=numsSize-1来模拟三个数，i初始为0
初定义result = nums[0] + nums[1] + nums[2]
用result来做最接近的和，若res<tar则right++,若res>tar则left--
逐渐更新res
然后当right==left时数组遍历完，进入下一个循环
最后输出result
*/
int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //由小到大排序
}

int threeSumClosest(int* nums, int numsSize, int target)
{
    qsort(nums, numsSize, sizeof(int), cmp);
    int result = nums[0] + nums[1] + nums[2];
    for(int i=0;i<numsSize-2;i++)
    {
        int left = i+1;
        int right = numsSize - 1;
        while(left != right)
        {
            // 判断最小值
            int min = nums[i] + nums[left] + nums[left + 1];
            if(target < min)
            {
                if(abs(result - target) > abs(min - target))
                    result = min;
                break;
            }
            //判断最大值
            int max = nums[i] + nums[right] + nums[right - 1];
            if(target > max)
            {
                if(abs(result - target) > abs(max - target))
                    result = max;
                break;  
                }
            int sum = nums[i] + nums[left] + nums[right];
            if(abs(sum - target) < abs(result - target))
                result = sum;
            if(sum > target)
            {
                right--;
                while(left != right && nums[right] == nums[right+1])
                    right--;
            }
            else
            {
                left++;
                while(left != right && nums[left] == nums[left-1])
                    left++;
            }
        }
        while(i<numsSize-2 && nums[i] == nums[i+1])
            i++;
    }
    return result;
}
