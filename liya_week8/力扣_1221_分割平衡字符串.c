//����ַ�������R��L����һ��ʱcount+1
//������count��Ϊƽ���ַ������ֵ
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
