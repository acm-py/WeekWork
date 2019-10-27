//输出字符串，当R和L数量一致时count+1
//最后输出count即为平衡字符串最大值
int balancedStringSplit(char * s)
{
    int count=0;
    int x=0,y=0;
    for(int i=0;*s!=0;*s++)
    {
        if(*s=='L')
        {
            x++;
        }
        if(*s=='R')
        {
            y++;
        }
        if(x==y)
        {
            count++;
            x=0;
            y=0;
        }
    }
    return count;

}
