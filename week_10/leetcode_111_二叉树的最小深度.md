### **leetcode_111_二叉树的最小深度**

![image-20191124212846817](F:\C工程\数据结构\image_explain\LeetCode_107_二叉树的最小深度.png)

#### 和上道题差不多可用递归+迭代

#### 算法：1. DFS，2. BFS

```python
#递归 + DFS
# python 语言描述
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # 特判
        if root is None:
            return 0
        if not any(children):
            return 1
        # 设置无穷大，第一次比较的时候所有数都比它小
        min_depth = float('inf')
        for c in children:
            if c:
                min_depth = min(self.minDepth(c), min_depth)
        return min_depth + 1        
```

```python
# python 语言描述
# 非递归BFS
class Solution:
    def minDepth(self, root: TreeNode) -> int:
        # 特判
        if root is None:
            return 0
        queue = [(1, root)]
        while queue:
            depth, node = queue.pop(0)
            if not node.left and node.right:
                return depth
            if node.left:
                queue.append((depth + 1, node.left))
            
            if node.right:
                queue.append((depth + 1, node.right))
        return depth
```

