/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//˫ָ�룬��ָ��֮�����N���ڵ�
//��ָ��1�Ƶ����ʱ����ָ��2���N������Ϊ����N��
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
    while(p)//p��Ϊ�գ���ָ��ʱ
    {
        p=p->next;
        q=q->next;
        if(p)//��p����ʱִ�����У�t��q��ִ��һ�Σ�Ϊq��ǰ�ڵ㣩
        {
            t=t->next;
        }
    }
    //��q����ͷ�ڵ�ʱ
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
