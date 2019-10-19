//给定一个 haystack 字符串和一个 needle 字符串，
//在 haystack 字符串中找出 needle 字符串出现的第一个位置 
//(从0开始)。如果不存在，则返回  -1。
#include<stdio.h>
int strStr(char * haystack, char * needle)
{       
    int l1=strlen(haystack);
    int l2=strlen(needle);
    int i=0,j=0; 
	//首先特殊情况排除   
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
    //暴力历遍所有字符 
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
	printf("输入haystack字符串\n");
	scanf("%s",&x); 
	printf("输入needle字符串\n");
	scanf("%s",&y);
	printf("在haystack字符串中寻找needle字符串并返回下标\n");
	strStr(&x,&y);
 } 
