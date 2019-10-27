/*�㷨˼��
��������󣬼���ÿ��һ����������ܺͣ������������ص�
һֱ�����ĵ㣬�õ���ֵ������С��ֵ
[1,3,1]
[1,5,1]
[4,2,1]
����
[1,4,5]
[2,7,6]
[6,8,7]


*/

int min(int x,int y)
{
    return x<y? x:y;
 
}
int minPathSum(int** arr , int m , int* ns )
{
   if(!arr || !m || !ns[0]) return 0;
    
    int i, j, dp[m][ns[0]];
    
    //arr[0][]
    for(i=0; i<m; i++)
    {
        for(j=0; j<ns[0]; j++)
        {
            dp[i][j] = INT_MAX;                  
        }
    }
    
    for(i=0; i<m; i++)
    {
        for(j=0; j<ns[0]; j++)
        {
            if(j-1>=0) 
            {
                dp[i][j] = min(dp[i][j], dp[i][j-1]);
            }    
            if(i-1>=0) 
            {
                dp[i][j] = min(dp[i][j], dp[i-1][j]);
            }    
            if(dp[i][j] == INT_MAX)
            {
                dp[i][j] = arr[i][j];
            }
            else
                dp[i][j] += arr[i][j];
            
        }
    }
    
    return dp[m-1][ns[0]-1];
}
