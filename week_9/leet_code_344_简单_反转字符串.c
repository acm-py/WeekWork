#include <stdio.h>
#include <string.h>

void F(char* s, int sSize)
{
    int i=0, j=sSize - 1;
    char t;
    while(i < j)
    {
        t = s[i];
        s[i] = s[j];
        s[j] = t;
        i++;
        j--;
    }
}

int main()
{
	int i;
	char s[10] = "hello";
	F(s,strlen(s));
	for(i = 0;i<strlen(s);i++)
		printf("%c",s[i]);
	return 0;
}
