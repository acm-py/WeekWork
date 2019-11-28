## **leetcode_15_三数之和**
![图片](https://github.com/acm-py/Weekwork/raw/hmb/image_explain/LeetCode_15_三数之和.png)
#### 对于任一问题都应该先考虑特判情况

```python
例如，给定数组 nums = [-1, 0, 1, 2, -1, -4]
满足要求的三元组集合为：
[
    [-1, 0 ,1],
    [-1, -1, 2]
]
```

#### 算法流程：

1. 特判，对于数组长度n，如果数组为null或者数组长度小于3，返回[]。

2. 对数组进行排序。

3. 遍历排序后数组：
	- 若nums[i] > 0: 因为已经排序好，所以后面不可能有三个数加和等于0，直接返回结果。
	- 对于重复元素：跳过，避免出现重复解。
	- 令左指针L = i + 1，右指针R = n - 1，当L < R 时， 执行循环：
		- 当nums[i] + nums[L] + nums[R] == 0，执行循环，判断左界和右界是否和下一位置 重复，去除重复解。并同时将L，R移到下一位置，寻找新的解
		- 若和大于 0，说明nums[R]太大，R左移
		- 若和小于0， 说明nums[L]太小，L右移
	
	#### 代码如下：
	
	```python
	# 三数之和
	class Solution:
	    def threeSum(self, nums: List[int]) -> List[List[int]]
	    n =len(nums)
	    res = []
	    if (not nums or n<3):
	        return []
	    nums.sort()# 排序好后，如果nums[i] = 0,那么nums[i++] 都大于0，后面的三个数之和一定大于0。无需考虑
	    for i in range(n):
	        #排序好后，如果nums[i] = 0,那么nums[i++] 都大于0，后面的三个数之和一定大于0。无需考虑
	        if(nums[i]) > 0:
	            return res# 返回空
	        #如果元素重复，跳过，避免出现重复解
	        if(i > 0 and nums[i] == nums[i-1])
	            continue
	            # 双指针开始移动，如果对双指针法不太熟悉的话，leetcode 有道经典题目——盛水最多的容器
	        L = i + 1
	        R = n - 1
	        while(L<R):
	            if(nums[i] + nums[L] + nums[R] == 0):
	                res.append([nums[i], nums[L],nums[R]])
	                # 去重
	                while(L<R and nums[L] == nums[L+1]):
	                    L = L + 1
	                    # 去重
	                while(L<R and nums[R] == nums[R-1]):
	                    R = R-1
	                L = L + 1
	                R = R - 1
	            elif(nums[i] + nums[L] + nums[R] > 0):
	                # 因为nums[R] > nums[L] nums有序
	                R = R - 1
	            else:
	                # 相加小于0的情况
	                L = L + 1
	        return res
	```
	
	

##### 反思，起初这道题我直接采用了暴力法，结果超时。第二次用了双指针，解法一直错误。原因是因为没有去重，在某些特殊测试用例的情况下，报错。例如[0, 0, 0, 0]。双指针法使用还是不够熟练，数组数据类型的掌握也不熟悉。

