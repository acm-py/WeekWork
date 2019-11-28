### **LeetCode_257_二叉树的所有路径**

#### ![图片](https://github.com/acm-py/Weekwork/raw/hmb/image_explain/LeetCode_257_二叉树的所有路径.png)

#### 简言之递归

```python
class Solution:
    defbinaryTreePaths(self, root: TreeNode) -> List[str]:
        def conut_paths(root, path):
            # 如果是根节点
            if root:
                # 字符串拼接
                path += str(root.val)
                # 如果当前是叶子节点
                if not root.left and not root.right:
                    paths.append(path)
                else:
                    path += '->'
                    conut_paths(root.left, path)
                    conut_paths(root.right, path)
          
        
        paths = []
        conut_paths(root, '')
        return paths
```

