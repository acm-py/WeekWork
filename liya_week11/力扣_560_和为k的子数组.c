#define MAX_SIZE 100000
int subarraySum(int* nums, int numsSize, int k)
{
    int dp[MAX_SIZE] = {0};
    dp[0] = nums[0] == k ? 1 : 0;
    for (int i = 1; i < numsSize; i++) 
    {
        int sum = 0;
        int res = 0;
        for (int j = i; j >= 0; j--)    
        {
            sum += nums[j];
            if (sum == k) 
                res++;
        }
        dp[i] = dp[i - 1] + res;
    }
    return dp[numsSize - 1];
}
