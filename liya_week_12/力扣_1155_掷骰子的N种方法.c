int min(int x,int y)
{
    return x>y?y:x;
}
int max(int x,int y)
{
    return x>y?x:y;
}
int numRollsToTarget(int d, int f, int target)
{
    if(target>d*f || target<d || d==0)
        return 0;
    if(d==1)
        return 1;
    int x=pow(10,9)+7;
    //ȡģ���㲻����int��double֮����У���pow�������double��
    int dp[target];
    //��dp���±��ʾ����֮�ͣ�ֵΪ������
    for(int k=0;k<min(f,target);k++)
        dp[k]=1;
    for(int i=1;i<d;i++)
    {
        for(int j=min((i+1)*f,target)-1;j>=i;j--)
        {
            //�Ӻ���ǰ���£���Ϊ����Ľ����Ҫ�õ�ǰһ��ǰ��Ľ��
            dp[j]=0;
            for(int t=max(i-1,j-f);t<min(j,i*f);t++)
            {
                //ע��t�����½�
                dp[j]+=dp[t];
                dp[j]=dp[j]%x;
            }
        }
    }
    return dp[target-1];
}
