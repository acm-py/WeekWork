int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

// 本题思路与上题《三数之和》一致，但无需考虑计算内存的分配。

int threeSumClosest(int* nums, int numsSize, int target)
{
    if (numsSize == 0) {
        return 0;
    }
    int i,l,r;
    int ans = nums[0] + nums[1] + nums[2];
    
    qsort(nums, numsSize, sizeof(int), comp);//先将数组有序化，为双指针排序做准备

    for(i = 0;i<numsSize;i++)
    {
        l = i+1;
        r = numsSize - 1;
        while (l < r)
        {
            int sum = nums[i] + nums[l] + nums[r];
            if(abs(target - sum) < abs(target - ans))   
            {
                ans = sum;
            }
            if(sum < target) l++;
            else if(sum > target) r--;
            else return sum;
        }
    }
    
    return ans;
}
