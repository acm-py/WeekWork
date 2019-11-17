#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

/*  title:��ӽ�������֮��  */
 
/* ����һ������?n ������������?nums?�� һ��Ŀ��ֵ?target���ҳ�?nums?�е���
   ��������ʹ�����ǵĺ���?target?��ӽ���
   �������������ĺ͡��ٶ�ÿ������ֻ����Ψһ�𰸡�

���磬�������� nums = [-1��2��1��-4], �� target = 1.

�� target ��ӽ����������ĺ�Ϊ 2. (-1 + 2 + 1 = 2).


�������:ʵ���ϻ���ͨ���̶������㣬�����������˫ָ��Ϳ�������ķ�ʽ��ʡ
         �ظ�������ɽ�� 
*/
int threeSumClosest(vector<int>& nums, int target); 

int main()
{
	int a;
	vector<int> nums; 
	int target;
	cin>>target;
	while(cin>>a)
		nums.push_back(a);
	int result=threeSumClosest(nums,target);
	cout<<result;
}
int threeSumClosest(vector<int>& nums, int target) {
        int sum_slr=0;
        int approach=LONG_MAX;
        sort(nums.begin(),nums.end());//�����������鰴��С�������� 
        for(int i=0;i<nums.size()-2;i++)
		/*i,j,k�ֱ�Ϊ�����������������й̶�i,���α���
		  j,k�򽫶�Ӧ�������˫ָ��ķ�ʽ������ 
		*/                              
        {
            int l=i+1,r=nums.size()-1;
            while(l<r)
            {
                int sum=nums[i]+nums[l]+nums[r];
                if(sum==target)
                {
                    sum_slr=sum;
                    break;
                }
                if(abs(sum-target)<approach)
                {
                    sum_slr=sum;
                    approach=abs(sum_slr-target);
                }
                if(sum>target)
                {
                    r--;                    
                    while(nums[r]==nums[r+1]&&r>l) r--;
                }else
                {
                    l++;                    
                    while(nums[l]==nums[l-1]&&l<r) l++;
                }
            }
        } 
        return sum_slr;
    }
