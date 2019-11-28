### **leetcode_16_最接近的三数之和**

#### 相同点：与上一题相同所用的方法和考虑的角度大致相同。

#### 不同点：本题添加了target 值，要对不同组合的三数之和与target之差的绝对值进行比较，取绝对值之差最小的一种组合。

```html
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2)
```

##### 代码如下

```python
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        n = len(nums)
        # 特判
        if (not nums or n < 3):
            return None
        nums.sort()
        # 表示无穷小
        res = float("inf")
        for i in range(n):
            # 特殊情况
            if(i>0 and nums[i]==nums[i-1]):
                continue
            L = i + 1
            R = n - 1
            # 特殊情况
            # 如果不加这个 会慢12ms
            if(target <= 0 and nums[0]>0):
                res = nums[0]+nums[1]+nums[2]
                return res
            while(L < R):
                sum_nums = nums[i] + nums[L] + nums[R]
                if(sum_nums == target):
                    return target
                if(abs(sum_nums - target)< abs(res - target)):
                    res = sum_nums
                if(sum_nums-target<0):
                    L += 1
                else:
                    R -= 1
        return res
```

##### 总得来说本题基本思路和上一题，差不多。尤其要注意特例的判断，会优化用时。