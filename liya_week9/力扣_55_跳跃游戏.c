//�Ǹ���������ֻ�����0��λ�ú͸���     max-(i-pos)
//Ȼ������ǰ�ң����ܷ�����ȥ
bool canJump(int* nums, int numsSize)
{
    if(numsSize==0)
    {
        return true;
    }    
    int max=nums[0];       //��������Զ�Ĳ���
    int maxpos=0;       //��Զ�Ĳ���������λ��
    
    
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]>=max+maxpos-i)
        {
            max=nums[i];
            maxpos=i;
        }
        if(nums[i]==0)
        {
           if((max+maxpos-i)<=0)
           {              
               if(max+maxpos>=numsSize-1)
               {
                   return true;
               }
               else
               {
                   return false;
               }
           }
            
        }
        
    }
    return true;

}
