# 合并两个有序链表

将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

## 示例：
```
输入：1->2->4, 1->3->4  
输出：1->1->2->3->4->4
```

>题解：  
1.递归：重复调用函数，来比较两个链表的大小。  
2.迭代：创建一个头节点，用来指向数值小的那个链表，然后比较两个链表值的大小。（穿针引线）

### 代码一（递归）：
```chameleon
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
//递归
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    if(l1->val < l2->val)
    {
        l1->next = mergeTwoLists(l1->next,l2);
        return l1;
    }
    else
    {
        l2->next = mergeTwoLists(l1,l2->next);
        return l2;
    }
}
```

### 代码二（迭代）：
```chameleon
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * Phead = (struct ListNode *)malloc(sizeof(struct ListNode));//创建头节点
    struct ListNode * Ptail = Phead;

    while (l1 != NULL && l2 != NULL)
    {
        if(l1->val <= l2->val)
        {
            Ptail->next = l1;
            l1 = l1->next;
        }
        else
        {
            Ptail->next = l2;
            l2 = l2->next;
        }
        Ptail = Ptail->next;
    }
    Ptail->next = (l1 == NULL) ? l2 : l1;
    return Phead->next;
}
```