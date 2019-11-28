### **leetcode_31_下一个排列**

#### 这个题完全没有看懂。

#### 最后看题解，维基百科上对它做出了这样的一个解释：

- 1. 先找出最大的满足的索引K Nums[K] < Nums[K+1] ，如果不存在，翻转整个数组；
	2. 再找出另外一个最大的索引L满足Nums[L] > Nums[K]；
	3. 交换Nums[L] 和 Nums[K]；
	4. 最后翻转nums[K + 1]。
- 举个例子：
	1. 比如 nums = [1,2,7,4,3,1]，下一个排列是什么？
	2. 我们找到第一个最大索引是 nums[1] = 2
	3. 再找到第二个最大索引是 nums[4] = 3
	4. 交换，nums = [1,3,7,4,2,1];
	5. 翻转，nums = [1,3,1,2,4,7]
	6. 完毕!所以。时间复杂度：O(n）空间复杂度是O(1)

```python
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        '''
        Do not return anything, modifty nums in-place instead.
        '''
        firstIndex = -1
        n = len(nums)
        def reverse(nums, i, j):
            while i < j:
                nums[i], num[j] = nums[j], nums[i]
                i += 1
                j -= 1
        for i in range(n-2, -1, -1):
            if nums[i] < nums[i+1]:
                # 记录下索引K
                firstIndex = i
                break
                # 遍历完没有找到K 就翻转
        if firstIndex == -1:
            reverse(nums, 0, n-1)
            return
        secondIndex = -1
        for i in range(n-1, firstIndex, -1):
            if nums[i] > nums[firstIndex]:
                # 索引L
                secondIndex = i
                break
        nums[firstIndex], nums[secondIndex] = nums[secondIndex], nums[firstIndex]
        reverse(nums. firstIndex+1, n-1)
```



#### 然后又看了一个题解，才真正明白啥是字典序。

**字典序**
**给定多个字符，可以按照任意顺序进行排列，所有排列称为全排列。**

**每一种排列对应一个字符串，如果这些字符串按照字符串大小的顺序进行排序，那么就这种排序是基于字典序的全排列。**

**比如给定1，2，3，则他们基于字典序的全排列为：**
**123> 132 > 213 >231 > 312 > 321**

