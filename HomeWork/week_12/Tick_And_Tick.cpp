#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
/*
Title:Tick and Tick
Source:HDOJ 1006 

问题描述:时钟有三个指针每一天有很多次会重合在一起，最终他们厌烦了这样的日常,想要
         远离另外两个指针。如果一个指针与其他的两个指针的夹角都大于D度，那么这个指针
		 是快乐的。你需要计算出一天当中有多长时间使得所有指针都是快乐的。
Input
The input contains many test cases. Each of them has a single line with a real number 
D between 0 and 120, inclusively. The input is terminated with a D of -1.
 

Output
For each D, print in a single line the percentage of time in a day that all of the 
hands are happy, accurate up to 3 decimal places.
 
Sample Input
0
120
90
-1
 
Sample Output
100.000
0.000
6.251

*/
/*
ps:题目背景很有意思,看着很快乐,然而敲代码的时候各种不快乐，将这个实际问题用代码实现属实头疼,看来自己还是太弱了，
   想了很久想不出来最后还是去看了网上别人博客的代码，不过理解起来也够呛的。。

思路分析:对于这个问题需要将实际问题转换成数学问题进行求解,并且不能按每秒的位置进行遍历所有情况因为在这题里面指针的
         运动是连续的(即这里秒针是不停的走，而不是一小格一小格的走)。
		 首先可以假设以三根指针都指向12:00的位置为开始,会发现12小时后三指针又重新指向原位,故我们的搜索范围只需要遍历
		 12小时(12*60*60S)即可。
		 我们需要求的则是在12小时内利用计算机遍历求出其中有多长时间满足三指针都相差D度,即任意两指针间都相差D度,故可将
		 原问题转化为求其中满足任意两个指针相差D度的连续区间(时与分,时与秒,分与秒),求其交集可得满足题目要求得结果区间.
		 
		 一圈为360度，钟表一圈有60小格,故可以得出1格=6度,所以秒钟转速sv=6度/s,分钟转速mv=6/60=0.1
		 度/s,时钟转速hv=1.0/120度/s。同时我们可以得到任意两指针的相对角速度(转速),单独分析两指针相差D度的区间可以理解成
		 初中物理追及问题计算时间区间。故我们遍历的开始满足任意两指针重合时开始,任意两指针重合为结束,这样的周期,遍历所有这样的
		 周期同时求出周期内有多长时间满足要求便能得出结果。
*/
const double hv=1.0/120;//时钟转速,单位为弧度/s 
const double mv=0.1;//分钟转速
const double sv=6.0;//秒钟转速

double N=12.0*60.0*60.0;//总共12小时的时间,单位为S 

double w_hm=mv-hv;//时钟与分钟角速度差值 
double w_hs=sv-hv;//时钟与秒钟角速度差值
double w_ms=sv-mv;//分钟与秒钟角速度差值
 
double t_hm=360.0/w_hm;//时钟与分钟每一次重合间的周期 
double t_hs=360.0/w_hs;//时钟与秒钟每一次重合间的周期 
double t_ms=360.0/w_ms;//分钟与秒钟每一次重合间的周期 

 
int main()
{
    double D;//输入的度数 
  	while(cin>>D&&D!=-1)
  	{
  		double result=0.0;
  		
  		//从两针分离到相距D度所需要的时间 
  		double D_hm1=D/w_hm;
  		double D_hs1=D/w_hs;
  		double D_ms1=D/w_ms;
  		
  		//两针合并到D度时所需要的时间(还差n度就再次重合) 
  		double D_hm2=(360-D)/w_hm;
  		double D_hs2=(360-D)/w_hs;
  		double D_ms2=(360-D)/w_ms;
  		
  	    for(double hs=0.0;hs<=N;hs+=t_hs)
		{
		  	for(double hm=0.0;hm<=N;hm+=t_hm) 
		  	{
		  		//判断是否两个集合间又交集 
		  		if(hm+D_hm2<hs+D_hs1) continue;//因为hm会随着循环增大  
		  		if(hs+D_hs2<hm+D_hm1) break;//hs在这个循环中不变,而hm一直在增大,所以break 
		  		
		  		for(double ms=0.0;ms<=N;ms+=t_ms){		  			
					
					//同上,用于判断两个集合间是否有交集 
					if(ms+D_ms2<hs+D_hs1||ms+D_ms2<hm+D_hm1) continue;
					if(hm+D_hm2<ms+D_ms1||hs+D_hs2<ms+D_ms1) break;
					
					double res1=max(max(hs+D_hs1,hm+D_hm1),ms+D_ms1);
		  			double res2=min(min(hs+D_hs2,hm+D_hm2),ms+D_ms2);
					//相当于取res1对应图与res2对应图的交集,只有交集部分才大于n度 
					if(res1<res2) result+=(res2-res1);	  			
		  		} 
		  	}
		}
		printf("%.3lf\n",result/N*100.0);//输出结果百分比 
  	}
  	return 0;
}

