/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//双指针，两指针之间相差N个节点
//当指针1移到最后时，和指针2相差N个，即为倒数N个
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if(!(head->next))
    {
        return NULL;
    }
    struct ListNode* p,*q,*t;
    p=q=t=head;
    
    for(int i=0;i<n;i++)
    {
        p=p->next;
    }
    while(p)//p不为空，有指向时
    {
        p=p->next;
        q=q->next;
        if(p)//当p存在时执行下列（t比q少执行一次，为q的前节点）
        {
            t=t->next;
        }
    }
    //当q就在头节点时
    if(q==head)
    {
      head=head->next;  
    }
    else
    {
        t->next=q->next;
    }
    return head;
}
