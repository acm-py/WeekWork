#include<cstdio>
#include<iostream>
#include<cstring> 
/*

ȡ��HDOJ��pro.ID:1.2.5(HUD2399),�������ͣ�������ӦACM��������д�淶�� 
title:GPA

Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 6230 Accepted Submission(s): 2473

Problem Description(��������)
Each course grade is one of the following five letters: A, B, C, D, and F. 
(Note that there is no grade E.) The grade A indicates superior achievement ,
whereas F stands for failure. In order to calculate the GPA, the letter 
grades A, B, C, D, and F are assigned the following grade points, respectively: 
4, 3, 2, 1, and 0.
 

Input
The input file will contain data for one or more test cases, 
one test case per line. On each line there will be one or 
more upper case letters, separated by blank spaces.
 

Output
Each line of input will result in exactly one line of output. 
If all upper case letters on a particular line of input came 
from the set {A, B, C, D, F} then the output will consist of 
the GPA, displayed with a precision of two decimal places.Otherwise,
the message "Unknown letter grade in input" will be printed.
 

Sample Input
A B C D F
B F F C C A
D C E F
 

Sample Output
2.00
1.83
Unknown letter grade in input
 

Author
2006Rocky Mountain Warmup
 

Source
HDU ��Valentines Day�� Open Programming Contest 2009-02-14
 

Recommend
lcy
*/
/*��Ŀ����:ÿ�ſγ̳ɼ���A,B,C,D,F(û��E)�ֱ��ʾ����4,3,2,1,0��
           ÿ���������ɸ���ĸ��ʾÿ�ſγ̳ɼ���������˵�����
		   �γ�ƽ���ɼ�(�����ֱ�ʾ),��������ο������� 
		    
*/
//��Ŀ�����ѣ�ֻ�ǵ�����������Ӧ������������ȵȹ淶��ˮ��(�Ҿ���������ˮ���==) 
using namespace std;

char letter[1000];
int i,len,k,flag,n;
double gpa;
int judge(char ch)//�ж��ַ���Ӧ������ 
{
	if(ch>='A'&&ch<='D')
	  return ('E'-ch);
	else if(ch=='F')
	  return 0;
	else return -1;
}
int main()
{
	while(gets(letter)!=NULL)//ÿ�ζ�ȡһ��,ֱ������crtl+Z(EOF) 
	{
		n=flag=gpa=0;
		len=strlen(letter);
		for(int i=0;i<len;i++)
		{
			if(letter[i]!=' ')
			{
				k=judge(letter[i]);
				if(k!=-1){gpa+=k;n++;}
				else {flag=1;break;}
			}
		}
		if(flag){cout<<"Unknown letter grade in input"<<endl;flag=0;}
		else {gpa=gpa/n;printf("%.2f\n",gpa);}
	}
	return 0; 
}
