/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
  //����˫ָ��
struct ListNode *detectCycle(struct ListNode *head) 
{
    //����ָ��ͬʱָ��ͷ�ڵ�
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
        //��ָ��Ϳ�ָ��֮��Ĳ�ָ���
    while (fast != NULL && fast->next != NULL) 
    {
        //����ָ��ͬʱ����
        slow = slow->next;
        fast = fast->next->next;
        
        //����ָ��ָ����ͬʱ
        if (slow == fast) 
        {
            slow = head;
            //��ʱ��ָ���β������pos��λ��
            while (slow != fast)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return slow;
        }
    }
    return NULL;
}
