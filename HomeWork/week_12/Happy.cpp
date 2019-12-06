#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;


//title:HDOJ P1003 A+B Problem II

/* 
Problem Description
I have a very simple problem for you. Given two integers A and B, your job is to calculate the Sum of A + B.
 

Input
The first line of the input contains an integer T(1<=T<=20) which means the number of test cases. Then T lines follow, each line consists of two positive integers, A and B. Notice that the integers are very large, that means you should not process them by using 32-bit integer. You may assume the length of each integer will not exceed 1000.
 

Output
For each test case, you should output two lines. The first line is "Case #:", # means the number of the test case. The second line is the an equation "A + B = Sum", Sum means the result of A + B. Note there are some spaces int the equation. Output a blank line between two test cases.
 

Sample Input
2
1 2
112233445566778899 998877665544332211
 

Sample Output
Case 1:
1 + 2 = 3

Case 2:
112233445566778899 + 998877665544332211 = 1111111111111111110
*/

/*问题大概描述:先输入一个整数T(1<=T<=20),之后的T行里每行输入两个整数A,B(A,B很大,最大长度小于等于1000位)
               现在让你计算A+B的值，输入输出模式见样例和描述,另外需要注意最后一行输出后不再换行。 

  大整型计算问题，通常使用字符串或字符数组来表示大整型数，然后从数的个位开始每一位一一对应相加,同时
  判断是否需要进位，类似于模拟小学时学习的竖式加法的过程。 
*/
int main()
{
	int T;
	cin>>T;
	char a[1002],b[1002];
	int n=1;
	while(n<=T)
    {
    	cin>>a>>b;
    	int len_a,len_b,len,a1[1001],b1[1001],s1[1001];    
		len_a=strlen(a);
    	len_b=strlen(b);
    	len=len_a>=len_b?len_a:len_b;
    	for(int i=0;i<len_a;i++)
    	   a1[i]=a[len_a-1-i]-'0';
    	for(int i=0;i<len_b;i++)
    	   b1[i]=b[len_b-1-i]-'0';
    	for(int i=len_a;i<=len;i++)
    	   a1[i]=0;
    	for(int i=len_b;i<=len;i++)
    	   b1[i]=0;
    	for(int i=0;i<=len;i++)
			s1[i]=a1[i]+b1[i];
		for(int i=0;i<len;i++)
		{
			if(s1[i]>=10)
			{
				s1[i+1]=s1[i+1]+1;
				s1[i]=s1[i]%10;
			}
		}	
		cout<<"Case "<<n<<":"<<endl;
		for(int i=0;i<len_a;i++)
		  cout<<a[i];
		cout<<" "<<"+"<<" ";
		for(int i=0;i<len_b;i++)
		  cout<<b[i];
		cout<<" "<<"="<<" ";
		if(s1[len]>0)
		  cout<<s1[len];
		for(int i=len-1;i>=0;i--)
		   cout<<s1[i];
		cout<<endl;
		if(n<T)
		cout<<endl;
		n++; 
    }
    return 0;
} 
