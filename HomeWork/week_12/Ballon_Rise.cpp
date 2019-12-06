#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<map>

using namespace std;
/*
title;Let the Ballon Rise
source:HDOJ 1004
题目大意:统计不同气球颜色的数目,求其中某个颜色数目最多的气球，并输出该颜色，保证输入结果唯一。

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
/*入门题目，思路方面更多是去理解map结构的简单应用，对于C++可以直接使用STL类库的map,
  C语言可能需要用两个数组来自行实现一个简易版的map结构了。
  
  关于map<key,value>,原义为映射, 类似于数组中a[0]=1一样，map[key]=value,其中key,value可以是任何
  基本数据类型和类库中常用的各种模板类,主要用于将两个不同的数据集构成联系,形成其中一一对应的关系,
  数组可以当作其中的一个特殊范例,生活中很多方面都有类似的应用，比如学籍表学籍号对应于个人姓名,班级等信息。 
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
