#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
/*
title;Let the Ballon Rise
source:HDOJ 1004
��Ŀ����:ͳ�Ʋ�ͬ������ɫ����Ŀ,������ĳ����ɫ��Ŀ�������򣬲��������ɫ����֤������Ψһ��

Input
Input contains multiple test cases. Each test case starts with a number N (0 < N <= 1000) 
-- the total number of balloons distributed. The next N lines contain one color each. 
The color of a balloon is a string of up to 15 lower-case letters.
A test case with N = 0 terminates the input and this test case is not to be processed.
 
Output
For each case, print the color of balloon for the most popular problem on a single line. 
It is guaranteed that there is a unique solution for each test case.

Sample Input
5
green
red
blue
red
red
3
pink
orange
pink
0
 

Sample Output
red
pink
 
*/
/*������Ŀ��˼·���������ȥ���map�ṹ�ļ�Ӧ�ã�����C++����ֱ��ʹ��STL����map,
  C���Կ�����Ҫ����������������ʵ��һ�����װ��map�ṹ�ˡ�
  
  ����map<key,value>,ԭ��Ϊӳ��, ������������a[0]=1һ����map[key]=value,����key,value�������κ�
  �����������ͺ�����г��õĸ���ģ����,��Ҫ���ڽ�������ͬ�����ݼ�������ϵ,�γ�����һһ��Ӧ�Ĺ�ϵ,
  ������Ե������е�һ�����ⷶ��,�����кܶ෽�涼�����Ƶ�Ӧ�ã�����ѧ����ѧ���Ŷ�Ӧ�ڸ�������,�༶����Ϣ�� 
  */ 
int main()
{
	int N;
	while(cin>>N&&N)
	{
		map<string,int> br;
	    string color,temp;
		for(int i=0;i<N;i++)
		{
	         cin>>color;
	         br[color]++;
		}
		int max=0;
		map<string,int>::iterator it;
		for(it=br.begin();it!=br.end();it++)
		{
		  	if((*it).second>max){
		  		max=(*it).second;
		  		temp=(*it).first;
		  	}
		}
		cout<<temp<<endl;
	}
	return 0;
} 
