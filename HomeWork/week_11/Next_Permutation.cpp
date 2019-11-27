#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
/*
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。

如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。

必须原地修改，只允许使用额外常数空间。

以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1

*/
void nextPermutation(vector<int>& nums);//主要功能代码,核心思路见实现代码部分上部分 
void swap(int &num_a,int &num_b);//交换两变量a,b 
void reverse(vector<int>& nums,int first,int last);//数组nums中角标属于区间[first,last)内的数全部反转 
void p_V(vector<int> v);//打印vector数组，写成函数方便调试 
int main()
{
	vector<int> v;
	int n;
	while(cin>>a)//输入为EOF停止(windows的cmd命令窗口中为crtl+Z键)
		v.push_back(a);
	nextPermutation(v);
	p_V(v);
}

/*
这个问题的要点在于找到字典序下一个更大的排列与当前排列的关系，
举例分析:对于数列{6,5,4,3,2,1}，很明显这个数列本身就是最大的，因为
该数列排列完美的按照从数字大到小的排序。同时再举例,对于数列{2,3,6,5,4,1}
下一更大排列应为{2,4,1,3,6,5},可以发现将3与4之间互换然后对子数列{6,5,3,1}
反转后的数列。多次实验可发现规律:寻找以nums最后一个数为结尾的最大子递减序列Sn，
设Sn第一个数的前一个数为k(即nums[k+1]==sn[0]),同时在Sn中寻找一个数l,使得nums[l]恰好
刚大于nums[k],将nums[k]与nums[l]互换后将Sn反转整合到原数列中后便是下一更大排列。 
 
  
//思路明确后代码不难写 
*/
 void nextPermutation(vector<int>& nums) {
        if(nums.size()<=1)//只有一个元素直接返回 
          return;
        int k=nums.size()-2,l=nums.size()-1;    
        while(k!=-1)
        {
           if(nums[k]<nums[k+1])//寻找k值满足nums[k]>nums[k+1] 
             break;
           k--;
        }
        if(k==-1)
        {   
            reverse(nums,0,nums.size()-1);
            return;
        }
        while(l)
        {
            if(nums[l]>nums[k])//寻找l并且交换nums[k],nums[l]，然后反转nums在角标区间为[k+1,nums.size())上子序列 
            { 
            // p_V(nums);
               swap(nums[l],nums[k]);               
            //   p_V(nums);
            //   printf("%d %d\n",k,l);
			   reverse(nums,k+1,nums.size()-1);
               break;
            }
            l--;
        }
    }
 
void swap(int &num_a,int &num_b)
    {
        int temp=num_a;
        num_a=num_b;
        num_b=temp;
    }
void reverse(vector<int>& nums,int first,int last){
	   while(first!=last&&first<last)
       {
	         swap(nums[first],nums[last]);
             first++;
             last--;
       }
    }

void p_V(vector<int> v)
{
	for(int i=0;i<v.size();i++)
	  cout<<v[i]<<" ";
	cout<<endl;
} 
