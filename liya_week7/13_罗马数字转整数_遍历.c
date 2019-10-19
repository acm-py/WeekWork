#include<stdio.h>
int romanToInt(char * s){
int x = 0;
    while(*s)
    {
        switch(*s)
        {                       //先匹配特殊情况
            case 'I' :          //优化，改用switch,并更改特殊情况匹配方式
                if((*(s+1) == 'V') || (*(s+1) == 'X'))
                    x-= 1;
                else
                    x+= 1;
                break;
            case 'V' :
                    x+=5;
                break;
            case 'X' :
                if((*(s+1) == 'L') || (*(s+1) == 'C'))
                    x-=10;
                else
                    x+=10;
                break;
            case 'L' :
                    x+=50;
                break;
            case 'C' :
                if((*(s+1) == 'D') || (*(s+1) == 'M'))
                    x-=100;
                else
                   x+=100;
                break;
            case 'D' :
                    x+=500;
                break;
            case 'M' :
                    x+=1000;
                break;
            default  :
                    printf("出现非罗马字符，或数字超出3999");
                break;
        }
        s++;//指针指向下一个字符
    }
    printf("转化成的整数为:%d\n",x); 
    return x;
}
void main()
{
	char a[50];//题意上数字最大不超过3999，罗马数字应该就十几个字符 
	printf("罗马数字不好打，可使用以下测试用例，自行复制粘贴\n");
	printf("III  LVIII MCMXCIV \n");
	
	printf("输入罗马数字\n");
	 scanf("%s", a); 
	 romanToInt(&a);
	 
	 
}
