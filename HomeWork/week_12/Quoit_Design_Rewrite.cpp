#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>


using namespace std;
#define MAXN 100010


/*
title:Quoit Design
Source:HDOJ P1007 Quoit Design

�������:X-Y����ϵ����N����(x,y),��������2<=N<=100000,��������С�� 
         ��������d,������d/2,������λС����
PS:ԭ��������һ��������Ϸ�����ķϻ�,��Ȼͦ����˼�ġ�

input
  The input consists of several test cases. For each case, the first 
line contains an integer N (2 <= N <= 100,000), the total number of 
toys in the field. Then N lines follow, each contains a pair of (x, y) 
which are the coordinates of a toy. The input is terminated by N = 0.

Output
  For each test case, print in one line the radius of the ring required by the 
Cyberground manager, accurate up to 2 decimal places.

*/

/*˵������˼·:���Ȿ�����������ת��Ϊ����̵���������,����N���Ϊ100000,
               �ʴ���ı�����������������㷨O(n^2)��Ȼ��ʱ����ȡ�����Բ��÷��η�
			   �Ĳ���,�����е㰴x�������������,��N�����е�������������Ի���Ϊ������,
			   ������������[0,mid]��d1,�������[mid+1,N-1]��d2,����ֱ���mid��������mid�ұ�������d3�� 
               ͬʱ������ɼ�������Ϊ��ͬ������������,��������������Сֵ����������������������Сֵ,
			   ���η��㷨ʱ�临�Ӷ�ΪO(nlogn)��
			   ����Ļ���û��ʲô�Ѷ�,���ںϲ�ʱ��������������ֱ���mid����ʱ���Լ����Ż�,
			   �������е���X��������,������ĳ�����p[mid]�ĺ���������min(d1,d2),��õ㲻����Ϊ��С�����е�һ���� 
 
 
 */              
struct Point{
	double x;
	double y;
};//��ṹ��(x,y)�����ʾ
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
double dis(Point a,Point b)//��������빫ʽ 
{
	return pow(pow(a.x-b.x,2)+pow(a.y-b.y,2),0.5);
}
double Min_dt(int s,int e)//���������С������η� 
{
	if(s==e)
	 return 1000000;//����һ���ܴ��ֵ��Ӱ������Сֵ�Ľ�� 
	if(s+1==e)
	  return dis(px[s],px[e]);//ֻ������ʱ���������� 
	int mid=(s+e)/2;//ȡ�е� 
	double ans=min(Min_dt(s,mid),Min_dt(mid+1,e));//����������Ϊ���������ֲ�������Сֵ 
	int k=0; 
	//������ֱ���midһ��һ��ʱ,�������������������������Сֵ 
	for(int i=s;i<=e;i++)//��������p[i],������px[mid].x-px[i]<ans��������¼����ٴ��Ż� 
		if(fabs(px[mid].x-px[i].x)<ans)
		  py[k++]=px[i];
	sort(py,py+k,cmpy);
	for(int i=0;i<k;i++)
	 for(int j=i+1;j<k&&py[j].y-py[i].y<ans;j++)
	    ans=min(ans,dis(py[i],py[j]));//����������ϲ�����Сֵ 
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
