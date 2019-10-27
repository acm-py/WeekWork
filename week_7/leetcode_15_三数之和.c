int comp(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}

/*解题思路：
    看到题首先想到三重循环暴力解法，但执行代码超时；
    
    看了题解的思路，并按照思路实现。
    思路如下：
        *首先将无序的数组有序化，方便双指针查询；
        *外循环固定一个元素，使用两个指针。每次更换固定元素初始化左指针指向固定元素的下一个元素，右指针指向该数组的最后一个元素；
        *内循环判断左右指针对应位置的元素与当前固定元素之和是否满足条件：
            大于0，则令左指针不动，右指针向左偏移（因为数组排序为从左向右递增）
            小于0，则令左指针向右偏移，右指针不懂
            等于0，则将当前对应的三个元素记录到ans中；

        *特别要注意的是：判断结束后要处理跳过数组中连续重复的值，每个重复的元素都会多做一次无意义的循环（剪枝）
*/

//个人认为这题的思路比较简单，但如何给ans数组进行动态内存分配是个比较难以处理的点


int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    if (numsSize == 0) {
        return 0;
    }
    int **ret = (int **)malloc(sizeof(int *) * (numsSize + 1) * 6);
    *returnSize = 0;
    short left = 0;
    short right = numsSize - 1;;
    int target = 0;
    
    *returnColumnSizes = malloc(sizeof(int) * (numsSize + 1) * 6);
    qsort(nums, numsSize, sizeof(int), comp);
    ret[*returnSize] = malloc(sizeof(int) * 3);

    while (left + 1 < right) {
        int i = left + 1;
        int j = right;
        target = 0 - nums[left];
        while (i < j) {
            if (nums[i] + nums[j] < target) {
                i++;
            } else if (nums[i] + nums[j] > target) {
                j--;
            } else {
                ret[*returnSize][0] = nums[left];
                ret[*returnSize][1] = nums[i];
                ret[*returnSize][2] = nums[j];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;
                ret[*returnSize] = malloc(sizeof(int) * 3);

                while(nums[i] == nums[++i] && i < j) {}
                while(nums[j] == nums[--j] && i < j) {}
            }
        }
        while(nums[left] == nums[++left] && left + 1 < right) {}
    }
    
    return ret;
}
