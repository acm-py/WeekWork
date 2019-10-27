int max(int a,int b)
{
    if(a>=b)
        return a;
    else
        return b;
    
}

int rob(int* nums, int numsSize){
    if(numsSize==1)
            return nums[0];
    
        int n=numsSize;
        //vector<int>a(n+1),b(n+1);
    int a[n+1];
    int b[n+1];
        for(int i=2;i<n+1;i++)
        {
            a[i]=max(a[i-1],a[i-2]+nums[i-2]);
            b[i]=max(b[i-1],b[i-2]+nums[i-1]);
        }
        return max(a[n],b[n]);


}
