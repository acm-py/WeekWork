### **LeetCode_226_翻转二叉树**

![image-20191128183007643](F:\C工程\数据结构\image_explain\LeetCode_226_翻转二叉树.png)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def invertTree(self, root: TreeNode) -> TreeNode:
        stack = []
        cur = root
        while stack or cur:
            while cur:
                cur.left, cur.right = cur.right, cur.left
                stack.append(cur)
                cur = cur.left
            cur = stack.pop()
            cur = cur.right
        return root
```

