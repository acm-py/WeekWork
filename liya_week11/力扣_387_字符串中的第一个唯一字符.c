int firstUniqChar(char * s)
{
    int k,i,j;
       k=i=j=0;
    int len=strlen(s);
    //���ų��������
    if(len==1)
        return 0;
    if(len==0)
        return -1;
    //����Ƚϣ��ҳ�Ψһ�ַ�
    for(i=0;i<len;i++)
    {
        k=0;//ÿ�ζ���ʼ��
        for(j=0;j<len;j++)
            if(s[i]==s[j]&&i!=j)
            {
                k=1;
                break;
            }
        if(k==0)//s[i]��Ψһ�ַ����ǵ�һ��
            return i;
    }
    return -1; 
}
