bool hasCycle(struct ListNode *head) {
      if (head==NULL|| head->next==NULL) 
      {
        return false;
    }
    struct ListNode *x=head;
    struct ListNode *y=head->next;
     if (NULL == y->next || NULL == y->next->next) 
     {
         return false;
     }
    y = y->next->next;
    while(y!=x&&y!=x->next)
    {
        if(y->next==NULL||y->next->next==NULL)
        {
            return false;
        }
        else
        {
            y=y->next->next;
            x=x->next;
        }
    }
    return true;
}
