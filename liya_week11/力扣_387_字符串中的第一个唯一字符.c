int firstUniqChar(char * s)
{
    int k,i,j;
       k=i=j=0;
    int len=strlen(s);
    //先排除特殊情况
    if(len==1)
        return 0;
    if(len==0)
        return -1;
    //逐个比较，找出唯一字符
    for(i=0;i<len;i++)
    {
        k=0;//每次都初始化
        for(j=0;j<len;j++)
            if(s[i]==s[j]&&i!=j)
            {
                k=1;
                break;
            }
        if(k==0)//s[i]是唯一字符且是第一个
            return i;
    }
    return -1; 
}
