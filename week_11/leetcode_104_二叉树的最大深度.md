### **leetcode_104_二叉树的最大深度**

#### 毫无疑问肯定要用递归或者迭代：

#### 搜索算法有两种：

- BFS（广度优先搜索）
- DFS（深度优先搜索）

#### 1. DFS

```python
# python 语言描述
class Solution:
    def maxDepth(self, root):
        '''
        
       	'''
        if root is None:
            return 0
        else:
            left_height = self.maxDepth(root.left)
            right_height = self.maxDepth(root.right)
            # max 函数帮了很大的忙
            return max(left_height, right_height) + 1
```

#### 2. BFS

```python
# python 语言描述

def maxDepth(self, root):
    if root is None:
        return 0
    queue = [(root, 1)]
# 层次遍历最后得到的深度就是最大最大深度
    while queue:
        node, height = queue.pop(0)
        if node.left:
            queue.append((node.left, height + 1))
        if node.right:
            queue.append((node.right, height + 1))
    return height

```

