#include<cstdio>
#include<iostream>
using namespace std;
/*
title:HDU 1003 Max Sum(������������к�)

ps:ԭ��Ӣ�İ�Ͳ������ˡ���ֱ������վ�Ͽ����ˣ�����ֻ˵����Ŀ�����ˡ�
��Ŀ����:����һ������a(��a[1],a[2]...a[n])������������������кͣ�����ѧ�е������ص�,
         ����,��������(6,-1,5,4,-7),The max sum in this sequence��6+(-1)+5+4=14
����:һ������T(1<=T<=20),Ȼ������T������,ÿ��������һ������N(1<=N<=100000),Ȼ������N����������һ������(ÿ������������[-1000,1000]����Ϊ����)
���:��������==

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
// ����Ķ�̬�滮�����⣬�š�����������������ĿҪ��д��������ֳ�BUG�������˼��η�����BUGȴ��֪����ô�޸ġ�������ͦ���ܵ�== 
/*����˼·:��������a{}{a[0],a[1]...a[n]},Ҫ��������������кͣ� 
              
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
