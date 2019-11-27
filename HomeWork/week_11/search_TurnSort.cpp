#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

/*
假设按照升序排序的数组在预先未知的某个点上进行了旋转。

( 例如，数组?[0,1,2,4,5,6,7]?可能变为?[4,5,6,7,0,1,2]?)。

搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回?-1?。

你可以假设数组中不存在重复的元素。

你的算法时间复杂度必须是?O(log?n) 级别。

示例 1:

输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例?2:

输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/
/*关于二分查找:对于顺序排列数组nums[]与目标值target,令i=0,j=nums.size()-1,即两端点角标，
               令mid=(i+j)/2,在搜索时每次检索nums[mid],若targrt==nums[mid],即找到目标值，即可退出循环 
			   若nums[mid]>target,即搜索区域应该[i,mid)间,若nums[mid]<target,即搜索区域应在[mid+1,j]之间，
			   之后再对相应搜索区域进行重复迭代，直到target==nums[mid]出现或者i>=j(即数组内找不到目标值)。
			   
			   概括的话:因为数组顺序排列，每次将搜索区域减半，不断缩小target的取值范围，最后锁定目标值，这就是二分法
			   
			   二分法的查找思路类似于分治法其中的"分"的思想。 
 */ 
/*
时间复杂度为O(logn)并且不使用额外空间可以想到用二分法查找,但原数组并不是纯粹的顺序排列数组，。
二分法的使用重点在于判断什么时候向前规约，什么时候向后规约，这也是本题难点所在。

分析:分析所有可能的集合,以i==0为基础进行分析
     (1)nums[0]<=nums[mid]时([0-mid]不包含旋转),若nums[0]<=target<=nums[mid]时则向前规约，
     若nums[0]<nums[mid]<target时向后规约。(常规数组二分法就是这种情况)
	 (2)nums[mid]<nums[0]时([0,mid]包含旋转点),
	    若target<=nums[mid]<nums[0]时向前规约(target在旋转点到mid之间) 
	    若nums[mid]<target<nums[0]时向后规约(target在[mid-0]之间),
	    若nums[mid]<nums[0]<=target时向前规约(target在0到旋转点间)
	    
 	 综上所述:nums[mid]<nums[0],nums[0]>target,target>nums[mid]三项均为真或只有一项为真时向后规约。
	 
	 原文的分析是:
	  (1)if nums[0]<=nums[I],则当nums[0]<=target<=nums[i]时在0-i范围内查找。
	  (2)if nums[i]<nums[0],则在0-i区间某点发生下降，i+1到最后一个数字为有序数组，数字都小于nums[0]且
	     且大于nums[i],当target不属于nums[0]到nums[i]时(target<=nums[i]<nums[0] or nums[i]<nums[0]<=target),
		 我们应该在0-i区间内查找。
	   
       上述三种情况总结如下:
       nums[0]<=target<=nums[i]
                target<=nums[i]<nums[0]
                        nums[i]<nums[0]=target
	   所以我们进行三项判断:
       (nums[0]<=target),(target<=nums[i]),(nums[i]<nums[0]),现在我们想知道那两项为真(不可能三项均为真或均为假)	   
	    
		所以我们只需要区别三项中有两项为真还是一项为真即可。
		
		此类判断可用异或操作^来判定(相同为假，不同为真)
		
	    之后通过二分查找不断做小target可能位于区间直到start==end,此时nums[start]==target则
		找到了，若不等则说明数组无此项。
 
*/

int search(vector<int>& nums, int target) {
    int start=0,end=nums.size()-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if((nums[0]>target)^(nums[0]>nums[mid])^(target>nums[mid]))//核心判断，为真则后规约，假则前规约
            start=mid+1;
        else
            end=mid;
    }
    return start==end&&nums[start]==target?start:-1;
}
int main()
{
	int a,n,target=0;
	vector<int> nums;
	cin>>n;
	while(n--)
	{
		cin>>a;
		nums.push_back(a);
	}
	cin>>target;
	cout<<search(nums,target);
} 
