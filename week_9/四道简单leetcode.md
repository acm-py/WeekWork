### LeetCode_69_x的平方根

#### 解法一：牛顿迭代法

```python
# python 语言描述
# 牛顿迭代法--非常巧妙的思路
# 本题要求输出整数
# 例子： 
'''
输入为4 输出为2
输入为8 输出为2，虽然8的平方根是2.8

'''
# 该学习牛顿迭代法了
class Solution:
    def mySqrt(self, x: int) -> int:
        if x <= 1:
            return x
        r = x
        while r > x / r:
            r = (r + x / r) // 2
        return int(r)
```

#### 解法二：二分法

```python
#python语言描述
# 二分查找要避免堆栈溢出
class Solution:
    def mySqrt(self, x: int) -> int:
        l,r = 0,x
        while l != r:
            mid = (l+r)//2
            if x < mid*mid:
                r = mid
            else:
                l = mid+1
        return l-1 if l*l>x else l
```

### leetcode_70_爬楼梯

#### 解法一：动态规划

```python
'''
每次你可以爬 1 或 2 个台阶。
'''
class Solution:
    def climbStairs(self, n: int) -> int:
        #特判
        i = 1 # 爬到1台阶仅有一种方法
        i = 2 # 爬到2台阶有2种方法 1+1 或者 2
        for _ in range(3,n):
            i, j = j, i+1
        return i + j if n > 2 else n

```

### leetcode_83_删除排序链表中的重复元素

#### 解法一：双指针法（快慢指针）

```python
#python 语言描述
'''
示例1：
输入:1->1->2
输出:1->2
示例2:
输入:1->1->2->3->3
输出:1->2->3

'''
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        dummy = ListNode(-1000)
        dummy.next = head
        # 直接用dummy的话循环过程中会改变dummy的值，最后返回dommy的时候就不是你想要的的dummy了。
        # 所以才会再定义一个slow
        slow = dummy
        fast = dummy.next
        while fast :
            if slow.val == fast.val:
                fast = fast.next
                slow.next = fast
            else:
                slow = slow.next
                fast = fast.next
        return dummy.next
```

#### 解法二：递归写法

```python
class Solution:
    def deleteDuplicates(self, head: ListNode) -> ListNode:
        if head is None or head.next is None:
            return head
        
        child and head.val == child.val:
            head.next = child.next
            child.next = None
            
            
        return head
```

### leetcode_100_相同的树

#### 解法一：递归

```python
#python 语言描述
'''
给定两个二叉树，编写一个函数来检验它们是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
'''
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if not p and not q:
            return True
        elif p is not None and q is not None:
            if p.val == q.val:
                return self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)
            else:
                return False
        else:
            return False
```



### leetcode_101_对称二叉树

![image-20191104193856109](F:\hmb_work\Weekwork\week_9\image-20191104193856109.png)

```python
# python 语言描述
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def check(node1, node2):
            if not node1 and not node2:
                return True
            elif not node1 or not node2:
                return False
            
            if node1.val != node2.val:
                return False
            # 第一次提交把递归条件句写成了下面这样。测试案列正确，解答错误。
            # return check(node1.left,node2.left) and check(node2.right, node2.right)
            # 因为是镜像对称所以应该是最左和最右对比
            return check(node1.left, node2.right) and check(node1.right, node2.left)
        return check(root, root)
```

