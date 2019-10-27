 /*
        解题思路：
            题都看不懂。。！(出这题的人真是生怕别人把题看懂了)
            还是先把题目的意思搞明白吧，看了好几个人的题解才搞懂这题到底是啥意思，直接把别人的解释复制过来了：
                
                1、先找出最大的索引 k 满足 nums[k] < nums[k+1]，如果不存在，就翻转整个数组；
                2、再找出另一个最大索引 l 满足 nums[l] > nums[k]；
                3、交换 nums[l] 和 nums[k]；
                4、最后翻转 nums[k+1:]。
                
                举个例子：

                比如 nums = [1,2,7,4,3,1]，下一个排列是什么？

                我们找到第一个最大索引是 nums[1] = 2

                再找到第二个最大索引是 nums[4] = 3

                交换，nums = [1,3,7,4,2,1];

                翻转，nums = [1,3,1,2,4,7]

                完毕!
        
        实现步骤：
            弄清楚题意后这题的思路就很清楚了
            *先倒序查找满足 nums[k] < nums[k+1] 的索引k
            *从索引k开始正序查找满足 nums[l] > nums[k]的索引l
                *找到满足条件的索引l，则交换nums[k] 和 nums[l] 的值
                    *将交换后的数组，从k开始按降序排列
                *否则将整个数组按升序重新排列
    */

// 从倒序列表中找出比 target 大的第一个元素
int findIndex(int * nums, int start, int end, int target) {
    // 二分法中点
    int mid = start;
    while (end > start) {
        mid = (start + end) >> 1;
        // start == mid 时只剩 1 个元素
        if (start == mid)
            return target < nums[end]? end: mid;
        else if (nums[mid] > target)
            start = mid;
        else
            end = mid;
    }
    return mid;
}

// 对 nums 数组的 start 到 end 做倒序排列
void reverse(int * nums, int start, int end) {
    nums += start;
    end -= start;
    int tmp;
    for (int i = 0; i < (end >> 1); i++) {
        tmp = nums[i];
        nums[i] = nums[end - i - 1];
        nums[end - i - 1] = tmp;
    }
}

void nextPermutation(int* nums, int numsSize){
    int index = -1;    // 记录第一个下降点的索引
    // 从后往前遍历，直到遇到 nums[i - 1] < nums[i]，记录 index
    for (int i = numsSize - 1; i > 0; i--) {
        if (nums[i - 1] < nums[i]) {
            index = i - 1;
            break;
        }
    }
    // 当 index == -1，说明没有下降点，直接对全数组做反转
    if (index == -1) {
        reverse(nums, 0, numsSize);
        return;
    }
    // 获取待交换的索引
    int swap = findIndex(nums, index + 1, numsSize - 1, nums[index]);
    int tmp = nums[index];
    nums[index] = nums[swap];
    nums[swap] = tmp;
    reverse(nums, index + 1, numsSize);
}
