//����һ�� haystack �ַ�����һ�� needle �ַ�����
//�� haystack �ַ������ҳ� needle �ַ������ֵĵ�һ��λ�� 
//(��0��ʼ)����������ڣ��򷵻�  -1��
#include<stdio.h>
int strStr(char * haystack, char * needle)
{       
    int l1=strlen(haystack);
    int l2=strlen(needle);
    int i=0,j=0; 
	//������������ų�   
    if(l1 ==0&&l2!=0)        
    {
       printf("-1\n");
	    //return -1;
    }
    if(l2==0)
    {
    	printf("0\n");
        //return 0;
    }
    //�������������ַ� 
    for( i = 0 ; i <l1;  i++)
    {
        if(haystack[i] == needle[j])
        {
            j++;
            if(j==l2)
            {
                printf("%d\n",i-j+1);
				//return i-j+1;
                break;
            }
        }
        else
        {
           if(i!=0)
           {               
               i=i-j;
               
               j=0;
           }
            else
            {
                j=0;   
            }
        }        
    }
    return 0;
}
int main()
{
	char x[50];
	char y[50];
	printf("����haystack�ַ���\n");
	scanf("%s",&x); 
	printf("����needle�ַ���\n");
	scanf("%s",&y);
	printf("��haystack�ַ�����Ѱ��needle�ַ����������±�\n");
	strStr(&x,&y);
 } 
