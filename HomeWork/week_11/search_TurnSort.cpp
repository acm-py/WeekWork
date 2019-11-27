#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

/*
���谴�����������������Ԥ��δ֪��ĳ�����Ͻ�������ת��

( ���磬����?[0,1,2,4,5,6,7]?���ܱ�Ϊ?[4,5,6,7,0,1,2]?)��

����һ��������Ŀ��ֵ����������д������Ŀ��ֵ���򷵻��������������򷵻�?-1?��

����Լ��������в������ظ���Ԫ�ء�

����㷨ʱ�临�Ӷȱ�����?O(log?n) ����

ʾ�� 1:

����: nums = [4,5,6,7,0,1,2], target = 0
���: 4
ʾ��?2:

����: nums = [4,5,6,7,0,1,2], target = 3
���: -1
*/
/*���ڶ��ֲ���:����˳����������nums[]��Ŀ��ֵtarget,��i=0,j=nums.size()-1,�����˵�Ǳ꣬
               ��mid=(i+j)/2,������ʱÿ�μ���nums[mid],��targrt==nums[mid],���ҵ�Ŀ��ֵ�������˳�ѭ�� 
			   ��nums[mid]>target,����������Ӧ��[i,mid)��,��nums[mid]<target,����������Ӧ��[mid+1,j]֮�䣬
			   ֮���ٶ���Ӧ������������ظ�������ֱ��target==nums[mid]���ֻ���i>=j(���������Ҳ���Ŀ��ֵ)��
			   
			   �����Ļ�:��Ϊ����˳�����У�ÿ�ν�����������룬������Сtarget��ȡֵ��Χ���������Ŀ��ֵ������Ƕ��ַ�
			   
			   ���ַ��Ĳ���˼·�����ڷ��η����е�"��"��˼�롣 
 */ 
/*
ʱ�临�Ӷ�ΪO(logn)���Ҳ�ʹ�ö���ռ�����뵽�ö��ַ�����,��ԭ���鲢���Ǵ����˳���������飬��
���ַ���ʹ���ص������ж�ʲôʱ����ǰ��Լ��ʲôʱ������Լ����Ҳ�Ǳ����ѵ����ڡ�

����:�������п��ܵļ���,��i==0Ϊ�������з���
     (1)nums[0]<=nums[mid]ʱ([0-mid]��������ת),��nums[0]<=target<=nums[mid]ʱ����ǰ��Լ��
     ��nums[0]<nums[mid]<targetʱ����Լ��(����������ַ������������)
	 (2)nums[mid]<nums[0]ʱ([0,mid]������ת��),
	    ��target<=nums[mid]<nums[0]ʱ��ǰ��Լ(target����ת�㵽mid֮��) 
	    ��nums[mid]<target<nums[0]ʱ����Լ(target��[mid-0]֮��),
	    ��nums[mid]<nums[0]<=targetʱ��ǰ��Լ(target��0����ת���)
	    
 	 ��������:nums[mid]<nums[0],nums[0]>target,target>nums[mid]�����Ϊ���ֻ��һ��Ϊ��ʱ����Լ��
	 
	 ԭ�ĵķ�����:
	  (1)if nums[0]<=nums[I],��nums[0]<=target<=nums[i]ʱ��0-i��Χ�ڲ��ҡ�
	  (2)if nums[i]<nums[0],����0-i����ĳ�㷢���½���i+1�����һ������Ϊ�������飬���ֶ�С��nums[0]��
	     �Ҵ���nums[i],��target������nums[0]��nums[i]ʱ(target<=nums[i]<nums[0] or nums[i]<nums[0]<=target),
		 ����Ӧ����0-i�����ڲ��ҡ�
	   
       ������������ܽ�����:
       nums[0]<=target<=nums[i]
                target<=nums[i]<nums[0]
                        nums[i]<nums[0]=target
	   �������ǽ��������ж�:
       (nums[0]<=target),(target<=nums[i]),(nums[i]<nums[0]),����������֪��������Ϊ��(�����������Ϊ����Ϊ��)	   
	    
		��������ֻ��Ҫ����������������Ϊ�滹��һ��Ϊ�漴�ɡ�
		
		�����жϿ���������^���ж�(��ͬΪ�٣���ͬΪ��)
		
	    ֮��ͨ�����ֲ��Ҳ�����Сtarget����λ������ֱ��start==end,��ʱnums[start]==target��
		�ҵ��ˣ���������˵�������޴��
 
*/

int search(vector<int>& nums, int target) {
    int start=0,end=nums.size()-1;
    while(start<end)
    {
        int mid=(start+end)/2;
        if((nums[0]>target)^(nums[0]>nums[mid])^(target>nums[mid]))//�����жϣ�Ϊ������Լ������ǰ��Լ
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
