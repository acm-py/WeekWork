int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

// ����˼·�����⡶����֮�͡�һ�£������迼�Ǽ����ڴ�ķ��䡣

int threeSumClosest(int* nums, int numsSize, int target)
{
    if (numsSize == 0) {
        return 0;
    }
    int i,l,r;
    int ans = nums[0] + nums[1] + nums[2];
    
    qsort(nums, numsSize, sizeof(int), comp);//�Ƚ��������򻯣�Ϊ˫ָ��������׼��

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
