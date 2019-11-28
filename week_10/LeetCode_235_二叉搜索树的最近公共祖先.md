### **LeetCode_235_二叉搜索树的最近公共祖先**

![图片](https://github.com/acm-py/Weekwork/raw/hmb/image_explain/LeetCode_235_二叉树的最近公共祖先.png)

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # 二叉搜索树的特点，左边小，右边大，
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parent_val = root.val

        p_val = p.val
        q_val = q.val

        if p_val > parent_val and q_val > parent_val:
            return self.lowestCommonAncestor(root.right, p, q)
        elif p_val < parent_val and q_val < parent_val:
            return self.lowestCommonAncestor(root.left, p, q)
        else:
            return root 
```

