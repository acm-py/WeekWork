#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>


using namespace std;
#define MAXN 100010


/*
title:Quoit Design
Source:HDOJ P1007 Quoit Design

问题简述:X-Y坐标系存在N个点(x,y),其中满足2<=N<=100000,求其中最小的 
         两点间距离d,输出结果d/2,保留两位小数。
PS:原题描述了一大堆这个游戏背景的废话,虽然挺有意思的。

input
  The input consists of several test cases. For each case, the first 
line contains an integer N (2 <= N <= 100,000), the total number of 
toys in the field. Then N lines follow, each contains a pair of (x, y) 
which are the coordinates of a toy. The input is terminated by N = 0.

Output
  For each test case, print in one line the radius of the ring required by the 
Cyberground manager, accurate up to 2 decimal places.

*/

/*说下整体思路:问题本身经过理解后可以转化为求最短的两点间距离,由于N最大为100000,
               故纯粹的遍历所有两点间距离的算法O(n^2)必然超时不可取。可以采用分治法
			   的策略,将所有点按x坐标升序排序后,求N个点中的最短两点距离可以划分为三部分,
			   即两点在区间[0,mid]内d1,两点均在[mid+1,N-1]内d2,两点分别在mid左边区间和mid右边区间内d3。 
               同时子问题可继续划分为相同的三个子问题,最终两点间距离最小值便是三个部分所求结果的最小值,
			   分治法算法时间复杂度为O(nlogn)。
			   问题的划分没有什么难度,但在合并时求子问题中两点分别在mid两边时可以继续优化,
			   由于所有点以X升序排列,所以若某点距离p[mid]的横向距离大于min(d1,d2),则该点不可能为最小两点中的一个。 
 
 
 */              
struct Point{
	double x;
	double y;
};//点结构用(x,y)坐标表示
Point px[MAXN],py[MAXN];

int cmpx(Point a,Point b){
	if(a.x==b.x)
	  return a.y<b.y;
	return a.x<b.x;
}

int cmpy(Point a,Point b)
{
    return a.y<b.y;
}
double dis(Point a,Point b)//求两点距离公式 
{
	return pow(pow(a.x-b.x,2)+pow(a.y-b.y,2),0.5);
}
double Min_dt(int s,int e)//求两点间最小距离分治法 
{
	if(s==e)
	 return 1000000;//返回一个很大的值不影响求最小值的结果 
	if(s+1==e)
	  return dis(px[s],px[e]);//只有两点时求出两点距离 
	int mid=(s+e)/2;//取中点 
	double ans=min(Min_dt(s,mid),Min_dt(mid+1,e));//划分子问题为左右两部分并求其最小值 
	int k=0; 
	//若两点分别在mid一左一右时,遍历满足条件的两点距离求最小值 
	for(int i=s;i<=e;i++)//对于任意p[i],若满足px[mid].x-px[i]<ans则将其加入新集合再次优化 
		if(fabs(px[mid].x-px[i].x)<ans)
		  py[k++]=px[i];
	sort(py,py+k,cmpy);
	for(int i=0;i<k;i++)
	 for(int j=i+1;j<k&&py[j].y-py[i].y<ans;j++)
	    ans=min(ans,dis(py[i],py[j]));//三部分问题合并求最小值 
	return ans;
}
int main()
{
	int N;
	while(scanf("%d",&N)&&N)
	{
		for(int i=0;i<N;i++)
			scanf("%lf%lf",&px[i].x,&px[i].y);		
		sort(px,px+N,cmpx);
		
		printf("%.2lf\n",Min_dt(0,N-1)/2);
	}
} 
