
/*
给定一个字符串， 求出字符串中单词的个数 
分析： 
1、明确单词是以空格分开的   ------用gets 函数    （scanf函数不能接收带空格的字符串）
2、以空格为着手点 进行判断 
*/


#include <stdio.h> 

int main()
{
	char str[1000];
	int i,word,count;
	count = 0;
	word = 0;
	gets(str);
	
	//空格后是一个新的单词   
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] ==' ') 
			word = 0;
		if(str[i] != ' ' && word == 0)  // 以 word == 0 或 word == 1 为判断对象 
		{
		    count++;
		    word = 1;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
