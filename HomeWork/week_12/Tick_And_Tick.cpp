#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
/*
Title:Tick and Tick
Source:HDOJ 1006 

��������:ʱ��������ָ��ÿһ���кܶ�λ��غ���һ�����������ᷳ���������ճ�,��Ҫ
         Զ����������ָ�롣���һ��ָ��������������ָ��ļнǶ�����D�ȣ���ô���ָ��
		 �ǿ��ֵġ�����Ҫ�����һ�쵱���ж೤ʱ��ʹ������ָ�붼�ǿ��ֵġ�
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
ps:��Ŀ����������˼,���źܿ���,Ȼ���ô����ʱ����ֲ����֣������ʵ�������ô���ʵ����ʵͷ��,�����Լ�����̫���ˣ�
   ���˺ܾ��벻���������ȥ�������ϱ��˲��͵Ĵ��룬�����������Ҳ��Ǻ�ġ���

˼·����:�������������Ҫ��ʵ������ת������ѧ����������,���Ҳ��ܰ�ÿ���λ�ý��б������������Ϊ����������ָ���
         �˶���������(�����������ǲ�ͣ���ߣ�������һС��һС�����)��
		 ���ȿ��Լ���������ָ�붼ָ��12:00��λ��Ϊ��ʼ,�ᷢ��12Сʱ����ָ��������ָ��ԭλ,�����ǵ�������Χֻ��Ҫ����
		 12Сʱ(12*60*60S)���ɡ�
		 ������Ҫ���������12Сʱ�����ü����������������ж೤ʱ��������ָ�붼���D��,��������ָ��䶼���D��,�ʿɽ�
		 ԭ����ת��Ϊ������������������ָ�����D�ȵ���������(ʱ���,ʱ����,������),���佻���ɵ�������ĿҪ��ý������.
		 
		 һȦΪ360�ȣ��ӱ�һȦ��60С��,�ʿ��Եó�1��=6��,��������ת��sv=6��/s,����ת��mv=6/60=0.1
		 ��/s,ʱ��ת��hv=1.0/120��/s��ͬʱ���ǿ��Եõ�������ָ�����Խ��ٶ�(ת��),����������ָ�����D�ȵ������������
		 ��������׷���������ʱ�����䡣�����Ǳ����Ŀ�ʼ����������ָ���غ�ʱ��ʼ,������ָ���غ�Ϊ����,����������,��������������
		 ����ͬʱ����������ж೤ʱ������Ҫ����ܵó������
*/
const double hv=1.0/120;//ʱ��ת��,��λΪ����/s 
const double mv=0.1;//����ת��
const double sv=6.0;//����ת��

double N=12.0*60.0*60.0;//�ܹ�12Сʱ��ʱ��,��λΪS 

double w_hm=mv-hv;//ʱ������ӽ��ٶȲ�ֵ 
double w_hs=sv-hv;//ʱ�������ӽ��ٶȲ�ֵ
double w_ms=sv-mv;//���������ӽ��ٶȲ�ֵ
 
double t_hm=360.0/w_hm;//ʱ�������ÿһ���غϼ������ 
double t_hs=360.0/w_hs;//ʱ��������ÿһ���غϼ������ 
double t_ms=360.0/w_ms;//����������ÿһ���غϼ������ 

 
int main()
{
    double D;//����Ķ��� 
  	while(cin>>D&&D!=-1)
  	{
  		double result=0.0;
  		
  		//��������뵽���D������Ҫ��ʱ�� 
  		double D_hm1=D/w_hm;
  		double D_hs1=D/w_hs;
  		double D_ms1=D/w_ms;
  		
  		//����ϲ���D��ʱ����Ҫ��ʱ��(����n�Ⱦ��ٴ��غ�) 
  		double D_hm2=(360-D)/w_hm;
  		double D_hs2=(360-D)/w_hs;
  		double D_ms2=(360-D)/w_ms;
  		
  	    for(double hs=0.0;hs<=N;hs+=t_hs)
		{
		  	for(double hm=0.0;hm<=N;hm+=t_hm) 
		  	{
		  		//�ж��Ƿ��������ϼ��ֽ��� 
		  		if(hm+D_hm2<hs+D_hs1) continue;//��Ϊhm������ѭ������  
		  		if(hs+D_hs2<hm+D_hm1) break;//hs�����ѭ���в���,��hmһֱ������,����break 
		  		
		  		for(double ms=0.0;ms<=N;ms+=t_ms){		  			
					
					//ͬ��,�����ж��������ϼ��Ƿ��н��� 
					if(ms+D_ms2<hs+D_hs1||ms+D_ms2<hm+D_hm1) continue;
					if(hm+D_hm2<ms+D_ms1||hs+D_hs2<ms+D_ms1) break;
					
					double res1=max(max(hs+D_hs1,hm+D_hm1),ms+D_ms1);
		  			double res2=min(min(hs+D_hs2,hm+D_hm2),ms+D_ms2);
					//�൱��ȡres1��Ӧͼ��res2��Ӧͼ�Ľ���,ֻ�н������ֲŴ���n�� 
					if(res1<res2) result+=(res2-res1);	  			
		  		} 
		  	}
		}
		printf("%.3lf\n",result/N*100.0);//�������ٷֱ� 
  	}
  	return 0;
}

