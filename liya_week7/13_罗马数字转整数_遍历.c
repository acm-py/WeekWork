#include<stdio.h>
int romanToInt(char * s){
int x = 0;
    while(*s)
    {
        switch(*s)
        {                       //��ƥ���������
            case 'I' :          //�Ż�������switch,�������������ƥ�䷽ʽ
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
                    printf("���ַ������ַ��������ֳ���3999");
                break;
        }
        s++;//ָ��ָ����һ���ַ�
    }
    printf("ת���ɵ�����Ϊ:%d\n",x); 
    return x;
}
void main()
{
	char a[50];//������������󲻳���3999����������Ӧ�þ�ʮ�����ַ� 
	printf("�������ֲ��ô򣬿�ʹ�����²������������и���ճ��\n");
	printf("III  LVIII MCMXCIV \n");
	
	printf("������������\n");
	 scanf("%s", a); 
	 romanToInt(&a);
	 
	 
}
