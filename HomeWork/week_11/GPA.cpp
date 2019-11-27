#include<cstdio>
#include<iostream>
#include<cstring> 
/*

取自HDOJ，pro.ID:1.2.5(HUD2399),入门题型，用来适应ACM竞赛的书写规范。 
title:GPA

Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 6230 Accepted Submission(s): 2473

Problem Description(问题描述)
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
HDU “Valentines Day” Open Programming Contest 2009-02-14
 

Recommend
lcy
*/
/*题目大意:每门课程成绩用A,B,C,D,F(没有E)分别表示分数4,3,2,1,0。
           每行输入若干个字母表示每门课程成绩，求出个人的所有
		   课程平均成绩(用数字表示),输入输出参考样例。 
		    
*/
//题目本身不难，只是单纯的用来适应竞赛输入输出等等规范的水题(我就是用来凑水题的==) 
using namespace std;

char letter[1000];
int i,len,k,flag,n;
double gpa;
int judge(char ch)//判断字符对应的数字 
{
	if(ch>='A'&&ch<='D')
	  return ('E'-ch);
	else if(ch=='F')
	  return 0;
	else return -1;
}
int main()
{
	while(gets(letter)!=NULL)//每次读取一行,直到遇到crtl+Z(EOF) 
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
