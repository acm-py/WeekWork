#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector> 
/* 
 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点(i,ai)。
 在坐标内画n条垂直线，垂直线i的两个端点分别为(i,ai) 和 (i, 0)。
 找出其中的两条线，使得它们与?x?轴共同构成的容器可以容纳最多的水。

说明：你不能倾斜容器，且n的值至少为 2。

示例:
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
*/ 
 
using namespace std;
int maxArea(vector<int>& height);
int main()
{
	int a;
	vector<int> height;
	while(cin>>a)//直到输入为EOF(数值为-1)时跳出循环，CMD命令行下该输入为crtl+Z。 
	  height.push_back(a);
	cout<<maxArea(height)<<endl;
	return 0;
}
/*思路分析: 设所选两端点分别为i,j(j>i),第i个端点处的高度为height[i], 
 则所求容器最大盛水面积S=min(height[i],height[j])*(j-i)。
 同时再做分析,假如i,j初始分别为0,height.size-1(即离的最远的两端点)，
 并规定端点只能从两侧向内移动，则若移动较高的板子，
 则S一定会变小((j-i)减小而min(height[i],height[j])不变或减小)，
 同理，若移动较低的板子S可能增大可能减小。
 故在遍历中每次只需移动当前最小的板子，记录其中可能出现的最大值。
 遍历通过双指针代表两端点的方式即可，时间复杂度为O(N); 
 */int maxArea(vector<int>& height) {
        int max_S=0;//记录最大值 
        int i=0,j=height.size()-1;
        int S;
        while(i<j)//双指针遍历 
        {
            S=min(height[i],height[j])*(j-i);
            if(S>max_S) max_S=S;
            if(height[i]>height[j])//移动短板容器才可能增大 
            {  
                j--;
            }else
            {
                i++;
            }
            
        }
        return max_S;
    }
