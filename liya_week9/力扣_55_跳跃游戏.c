//非负整数，则只需查找0的位置和个数     max-(i-pos)
//然后再向前找，看能否跳过去
bool canJump(int* nums, int numsSize)
{
    if(numsSize==0)
    {
        return true;
    }    
    int max=nums[0];       //能跳的最远的步数
    int maxpos=0;       //最远的步数所处的位置
    
    
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
