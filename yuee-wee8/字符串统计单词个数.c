#include <stdio.h> 

int main()
{
	char str[1000];
	int i,word,count;
	count = 0;
	word = 0;
	gets(str);
	
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] ==' ') 
			word = 0;
		if(str[i] != ' ' && word == 0)
		{
		    count++;
		    word = 1;
		}
	}
	
	printf("%d\n",count);
	
	return 0;
}
