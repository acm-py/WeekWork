//翻转链表
bool isPalindrome(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        {
            return true;
        }
    //找链表中点 
    struct ListNode* slow = head;
    struct ListNode* fast = head->next;
 
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    // 反转后半段链表
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
        
        // 比较前后段链表是否相等
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
