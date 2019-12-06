#include<cstdio>
#include<iostream>
using namespace std;
/*
title:HDU 1003 Max Sum(最大连续子序列和)

ps:原题英文版就不复制了。。直接在网站上看好了，这里只说下题目大意了。
题目大意:对于一个数列a(由a[1],a[2]...a[n])，求数列中最大子序列和，该子学列的起点和重点,
         例如,对于数列(6,-1,5,4,-7),The max sum in this sequence是6+(-1)+5+4=14
输入:一个整数T(1<=T<=20),然后输入T行数据,每行先输入一个整数N(1<=N<=100000),然后输入N个整数构成一个数列(每个数均在区间[-1000,1000]内且为整数)
输出:见样例吧==

Sample Input
2
5 6 -1 5 4 -7
7 0 6 -1 1 -6 7 -5
 

Sample Output
Case 1:
14 1 4

Case 2:
7 1 6 
*/
// 经典的动态规划入门题，嗯。。。。不过根据题目要求写个代码各种出BUG。调试了几次发现了BUG却不知道怎么修改。反正这挺难受的== 
/*解题思路:对于数列a{}{a[0],a[1]...a[n]},要求其中最大子序列和， 
              
*/
int main()
{
	int T;
	cin>>T;
	int i=1;
	while(i<=T)
	{
		int N;
		cin>>N;
		int t;	
		int sum=-1001,max=-1001,start=1,end=1,a,b;	    
		for(int j=1;j<=N;j++)
		{
		//	printf("sum=%d max=%d j=%d",sum,max,j);
			cin>>t;
			if(sum+t<t)
			  sum=t,a=b=j;
			else
			  sum+=t,++b;
			if(max<sum)
			  max=sum,start=a,end=b;
		}
		cout<<"Case "<<i<<":"<<endl;
		cout<<max<<" "<<start<<" "<<end<<endl;
		if(i<T)
		  cout<<endl;
		i++;
		
	}
	return 0;
}
