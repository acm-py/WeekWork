/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
  //快慢双指针
struct ListNode *detectCycle(struct ListNode *head) 
{
    //快慢指针同时指向头节点
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    
        //快指针和快指针之后的不指向空
    while (fast != NULL && fast->next != NULL) 
    {
        //快慢指针同时遍历
        slow = slow->next;
        fast = fast->next->next;
        
        //当两指针指向相同时
        if (slow == fast) 
        {
            slow = head;
            //此时快指针据尾部还差pos个位置
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
