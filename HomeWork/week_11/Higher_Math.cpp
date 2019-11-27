#include<cstdio>
#include<iostream>
#include<math.h>
using namespace std;
/*
ȡ��HDOJ Pro.ID:1.2.4���������ͣ�������ӦACM��������д�淶 
Higher Math
Time Limit: 2000/1000 MS (Java/Others) Memory Limit: 32768/32768 K (Java/Others)
Total Submission(s): 8648 Accepted Submission(s): 2750

Problem Description
You are building a house. You��d prefer if all the walls have a precise right angle relative to the ground, but you have no device to measure angles. A friend says he has a great idea how you could ensure that all walls are upright: All you need to do is step away a few feet from the wall, measure how far away you are from the wall, measure the height of the wall, and the distance from the upper edge of the wall to where you stand. You friend tells you to do these measurements for all walls, then he��ll tell you how to proceed. Sadly, just as you are done, a timber falls on your friend, and an ambulance brings him to the hospital. This is too bad, because now you have to figure out what to do with your measurements yourself.

Given the three sides of a triangle, determine if the triangle is a right triangle, i.e. if one of the triangle��s angles is 90 degrees.
 

Input
The inputs start with a line containing a single integer n. Each of the n following lines contains one test case. Each test case consists of three integers 1 <= a, b, c <= 40000 separated by a space. The three integers are the lengths of the sides of a triangle.
 

Output
The output for every scenario begins with a line containing ��Scenario #i:��, where i is the number of the scenario counting from 1. After that, output a single line containing either the string ��yes�� or the string ��no��, depending on if the triangle in this test case has a right angle. Terminate each test case with an empty line.
 

Sample Input
2
36 77 85
40 55 69
 

Sample Output
Scenario #1:
yes

Scenario #2:
no
 

Source
HDU 2008-10 Public Contest
 

Recommend
lcy
*/
//��Ŀ����:����n��,Ȼ��ÿ������a,b,c��ʾ�����ε������ߣ�����1<=a,b,c<=40000,�жϸ��������Ƿ���right triangle(ֱ��������)�� 
 //˼·:���ɶ������б𣬵�����������Ϥ��������������淶��.˳����һ���Լ�������Ӣ��=haha�� 
int main()
{
   int n;
   cin>>n;
   double a,b,c;
   for(int i=1;i<=n;i++)
   {
    cin>>a>>b>>c;
    double d,e,f;
    d=a*a;
    e=b*b;
    f=c*c;
    cout<<"Scenario #"<<i<<":\n";  
	if(d+e==f||d+f==e||e+f==d)
	  cout<<"yes\n"<<endl;
	else
	  cout<<"no\n"<<endl; 
   }
} 
