#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector> 
/* 
 ���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ����(i,ai)��
 �������ڻ�n����ֱ�ߣ���ֱ��i�������˵�ֱ�Ϊ(i,ai) �� (i, 0)��
 �ҳ����е������ߣ�ʹ��������?x?�Ṳͬ���ɵ�����������������ˮ��

˵�����㲻����б��������n��ֵ����Ϊ 2��

ʾ��:
����: [1,8,6,2,5,4,8,3,7]
���: 49
*/ 
 
using namespace std;
int maxArea(vector<int>& height);
int main()
{
	int a;
	vector<int> height;
	while(cin>>a)//ֱ������ΪEOF(��ֵΪ-1)ʱ����ѭ����CMD�������¸�����Ϊcrtl+Z�� 
	  height.push_back(a);
	cout<<maxArea(height)<<endl;
	return 0;
}
/*˼·����: ����ѡ���˵�ֱ�Ϊi,j(j>i),��i���˵㴦�ĸ߶�Ϊheight[i], 
 �������������ʢˮ���S=min(height[i],height[j])*(j-i)��
 ͬʱ��������,����i,j��ʼ�ֱ�Ϊ0,height.size-1(�������Զ�����˵�)��
 ���涨�˵�ֻ�ܴ����������ƶ��������ƶ��ϸߵİ��ӣ�
 ��Sһ�����С((j-i)��С��min(height[i],height[j])������С)��
 ͬ�����ƶ��ϵ͵İ���S����������ܼ�С��
 ���ڱ�����ÿ��ֻ���ƶ���ǰ��С�İ��ӣ���¼���п��ܳ��ֵ����ֵ��
 ����ͨ��˫ָ��������˵�ķ�ʽ���ɣ�ʱ�临�Ӷ�ΪO(N); 
 */int maxArea(vector<int>& height) {
        int max_S=0;//��¼���ֵ 
        int i=0,j=height.size()-1;
        int S;
        while(i<j)//˫ָ����� 
        {
            S=min(height[i],height[j])*(j-i);
            if(S>max_S) max_S=S;
            if(height[i]>height[j])//�ƶ��̰������ſ������� 
            {  
                j--;
            }else
            {
                i++;
            }
            
        }
        return max_S;
    }
