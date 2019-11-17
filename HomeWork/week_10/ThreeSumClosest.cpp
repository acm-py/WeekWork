#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
using namespace std;

/*  title:最接近的三数之和  */
 
/* 给定一个包括?n 个整数的数组?nums?和 一个目标值?target。找出?nums?中的三
   个整数，使得它们的和与?target?最接近。
   返回这三个数的和。假定每组输入只存在唯一答案。

例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.

与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).


问题分析:实质上还是通过固定其他点，最后两点利用双指针和快速排序的方式节省
         重复遍历完成结果 
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
        sort(nums.begin(),nums.end());//快速排序将数组按从小到大排序 
        for(int i=0;i<nums.size()-2;i++)
		/*i,j,k分别为遍历的三个数，其中固定i,依次遍历
		  j,k则将对应区域进行双指针的方式遍历。 
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
