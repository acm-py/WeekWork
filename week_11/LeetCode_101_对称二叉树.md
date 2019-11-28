### **LeetCode_101_对称二叉树**

#### ![图片](https://github.com/acm-py/Weekwork/raw/hmb/image_explain/LeetCode_101_对称二叉树.png)
#### 有一个坑：当结果是这样时也是True [1, 2, 2, 3, null, null, 3]。只要保持对称即可

#### 众所周知还是递归

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        if root is None:
            return True
            # 深度优先
        def dfs(left, right):
            # 两个都为空
            if not (left or right):
                return True
            # 有一个为空
            if not (left and right):
                return False
            if left.val != right.val:
                return False
            return dfs(left.left, right.right) and dfs(left.right, right.left)
        # 比较左右节点
        return dfs(root.left, root.right)
```

