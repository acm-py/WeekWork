### **leetcode_110_平衡二叉树**

给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

> 一个二叉树*每个节点* 的左右两个子树的高度差的绝对值不超过1。

![image-20191125145903864](F:\C工程\数据结构\image_explain\LeetCode_110_平衡二叉树.png)

#### 做深度优先遍历DFS，提前阻断。这种效率很高（从底至顶，最差情况O(n)）

- 对二叉树做深度优先遍历DFS，递归过程中：
	- 终止条件：当DFS 越过叶子节点的时候，返回高度0；
	- 返回值：
		- 从底至顶，返回以每个节点root 为根节点的字树最大高度（左右子树中最大的高度加1 max(left,right) + 1）
		- 当我们发现有一例左/右子树高度差  > 1的情况时，代表此树不是平衡树，返回-1
	- 当发现不是平衡树的时候，就不必再往下遍历了，直接返回-1
- 最差的情况是对树做一边完整的DFS遍历，时间复杂度为O(n)。

```python
# python语言描述
# 递归

class Solution:
    def isBalanced(self, root:TreeNode) -> bool:
        return self.depth(root) != -1
    def depth(self, root):
        if not root:
            return 0
        left = self.depth(root.left)
        if left == -1:
            return -1
        right = self.depth(root.right)
        if right == -1:
            return -1
        return max(left,right) + 1 if abs(left - right) < 2 else -1
```

#### 这种方法的确没想到，看了下题解，感觉是最优的啦。

#### 解法二（自己的解法）---（自顶向下，看了大佬的优化过）

```python
# python 语言描述
# 暴力+ 递归
class Solution:
    def isBalanced(self, root:TreeNode) -> bool:
        if root is None:
            return True
        return abs(self.depth(root.left) - self.depth(root.right)) <= 1 and self.isBalanced(root.left) and self.isBalanced(root.right)
    def depth(self, root):
        if root is None:
            return 0
        return max(self.depth(root.left), self.depth(root.right)) + 1
    	
```

#### 为何大佬这么牛皮，写的这么优雅。我何时能够像他一样