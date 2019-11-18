int search(int* nums, int numsSize, int target)
{
int i=0;
for( i=0;i<numsSize;i++)
{
    if(nums[i]==target)
        return i;
}
return -1;
}
//暴力历遍不太好意思
//不过我在力扣上战胜了97.74%的人........暴力万岁 
