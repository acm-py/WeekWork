//��ת����
bool isPalindrome(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        {
            return true;
        }
    //�������е� 
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
 
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // ��ת��������
    struct ListNode* prev = NULL;
    struct ListNode* cur = slow->next;
    struct ListNode* next;
        while(cur)
        {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        // �Ƚ�ǰ��������Ƿ����
        slow = head;
        fast = prev;
        while(fast)
        {
            if(slow->val != fast->val)
            {
                return false;
            }
            slow = slow->next;
            fast = fast->next;
        }
        return true;
}
