//��������numSize-1��1֮��

int findDuplicate(int* nums, int numsSize)
{
    int a[numsSize];
    memset(a,0,sizeof(a));
    int i=0;
    for(i=0;i<numsSize;i++)
    {
        a[nums[i]]+=1;
        if( a[nums[i]]==2)
        {
             break;
        }
    }
   return nums[i];

}
