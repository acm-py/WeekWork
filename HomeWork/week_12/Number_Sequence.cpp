#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

/*
title:Number Sequence
Source:HDOJ 1003

*/ 
int main()
{
	int A,B;
	long long n;
	int f[51]; 
	while(cin>>A>>B>>n&&(A||B||n))
	{		 
	    f[1]=1;
		f[2]=1;
		int i;
	    for(i=3;i<51;i++)
		{
			f[i]=A*f[i-1]+B*f[i-2];
			f[i]=f[i]%7;
			if(f[i]==1&&f[i-1]==1)
			  break;
		}
		n=n%(i-2);
		f[0]=f[i-2];
		cout<<f[n]<<endl;		
		/* 理论上的思路，但由于n太大导致Time Limit Exceeded。 
		int f_n=1,f_n1=1,f_n2=1; 
		for(int i=3;i<=n;i++)
		{
			f_n=(((A%7)*(f_n1%7))%7+((B%7)*(f_n2%7))%7)%7;
			f_n1=f_n2;
			f_n2=f_n;
		}
		cout<<f_n<<endl;*/
		
	}
	return 0;
}
