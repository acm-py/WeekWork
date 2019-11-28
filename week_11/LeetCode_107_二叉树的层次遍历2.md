### **LeetCode_107_二叉树的层次遍历**

#### ![image-20191126171532537](F:\C工程\数据结构\image_explain\LeetCode_107_二叉树的遍历层次2.png)

```python
class Solution:
    def levelOrderBottom(self, root):
        queue = []
        cur = [root]
        while cur:
            # 先初始化，然后 存val 的
            cur_layer_val = []
            # 初始化下一层的节点， 存节点。
            next_layer_node = []
            for node in cur:
                if node:
                	cur_layer_val.append(node.val)
                    next_layer_node.extend([node.left, node.right])
            if cur_layer_val:
                queue.insert(0, cur_layer_val)
                # 下一层变成当前层
            cur = next_layer_node
        return queue
```

