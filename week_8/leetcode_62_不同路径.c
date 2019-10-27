/*
    解题思路：
    由于机器人每次只能向下或者向右移动一步，观察可以得出机器人在第一排和第一列每个位置，都只存在一种路径可以抵达。所以dp[i][o] = 1,dp[0][1] = 1;
    因为机器人每次只能向下或者向右移动一步，所以dp[i][j]只能由d[i-1][j]（即dp[i-1][j]左边的位置）或dp[i][j-1]（即dp[i][j-1]上边的位置）抵达。所以得到dp的动态方程dp[i][j] = dp[i-1][j] +dp[i][j-1];
    求解：将dp的第一行和第一列的路径数都设置为1,其余位置的路径数皆可由动态方程推得；
*/

int uniquePaths(int m, int n){
    int dp[m][n];
    int i,j;
    memset(dp,0,sizeof(dp));
    for(i = 0;i<m;i++) dp[i][0] = 1;
    for(i = 0;i<n;i++) dp[0][i] = 1;
    
    for(i=1;i<m;i++)
    {
        for(j=1;j<n;j++) dp[i][j] = dp[i-1][j] + dp[i][j-1];
    }
    
    return dp[m-1][n-1];
}
