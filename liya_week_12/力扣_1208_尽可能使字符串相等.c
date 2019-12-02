int abs(int a)
{
   return a>0?a:-1*a;
}
int equalSubstring(char * s, char * t, int maxCost)
{
    int ssize =strlen(s);
    int *temp;
    int k=0,sum=0,returnk=0;
    temp= (int *)malloc(sizeof(int) * ssize);
    //为数组temp添加元素，使之等于同下标元素转换所需要的开销
    for(int i=0;i<ssize;i++)
    {
        temp[i]=abs(s[i]-t[i]);
    }

    //找到符合开销的最大子集
    for(int i=0;i<ssize;i++)
    {
        sum+=temp[i];
    
        if(sum>maxCost)
        {
            sum-=temp[i-k];
            k--;
        }
        k++;
        returnk=returnk>k?returnk:k;    
    }
    free(temp);
    return returnk;
}
