/*����˼·�����⡶��ͬ·������ȫһ�£�����������һЩ�ϰ��㣬ֻ��Ҫ�����ϰ���ʱ�����õ��·��������Ϊ0����*/

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    long **dp;
    int m,n;
    int i, j;
    
    m = obstacleGridSize;
    n = *obstacleGridColSize;
    
    for (i = 0; i < obstacleGridSize; i++) 
    {
        if(obstacleGrid[i][0] == 1) break;           // ��ʼ����1�е�ֵ��������ڲ��ɴ��ʣ������ɴ
        dp[i][0] = 1;
    }
    for (j = 0; j < * obstacleGridColSize; j++) 
    {
        if(obstacleGrid[0][j] == 1) break;            //  ��ʼ����1�е�ֵ��������ڲ��ɴ��ʣ������ɴ
        dp[0][j] = 1;
    }
    for (i = 1; i < obstacleGridSize; i++) 
        for (j = 1; j < * obstacleGridColSize; j++) 
            if(obstacleGrid[i][j] != 1)               // ����ڵ㲻�ɴ����Ҫ���㣬Ĭ��ֵ0�����˽ڵ㲻�ɴ����������һ���ڵ㣬���������սڵ�Ϊֹ��
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
    return dp[obstacleGridSize-1][* obstacleGridColSize-1];    // dp���Ѿ���¼��ÿ���ڵ����·����ֱ�ӷ�������ڵ�ֵ���ɡ�
}
