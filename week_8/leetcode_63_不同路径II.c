/*本题思路与上题《不同路径》完全一致，额外设置了一些障碍点，只需要遇到障碍点时，将该点的路径数设置为0即可*/

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    long **dp;
    int m,n;
    int i, j;
    
    m = obstacleGridSize;
    n = *obstacleGridColSize;
    
    for (i = 0; i < obstacleGridSize; i++) 
    {
        if(obstacleGrid[i][0] == 1) break;           // 初始化第1列的值，如果存在不可达，则剩余均不可达。
        dp[i][0] = 1;
    }
    for (j = 0; j < * obstacleGridColSize; j++) 
    {
        if(obstacleGrid[0][j] == 1) break;            //  初始化第1行的值，如果存在不可达，则剩余均不可达。
        dp[0][j] = 1;
    }
    for (i = 1; i < obstacleGridSize; i++) 
        for (j = 1; j < * obstacleGridColSize; j++) 
            if(obstacleGrid[i][j] != 1)               // 如果节点不可达，则不需要计算，默认值0，到此节点不可达，继续计算下一个节点，遍历到最终节点为止。
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[obstacleGridSize-1][* obstacleGridColSize-1];    // dp中已经记录好每个节点最多路径，直接返回数组节点值即可。
}
