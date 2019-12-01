# 盛最多水的容器
给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。  
在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。  
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。  
 **说明**：你不能倾斜容器，且 n 的值至少为2。  
![](images\question_11.jpg)
图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
## 示例：
```c
输入: [1,8,6,2,5,4,8,3,7]
输出: 49
```
>个人所想：就是找到每个容器的值，~~并储存起来（这是完全没有必要的，因为所需解题的结果是最大值。并且储存起来的话会遇到储存个数的问题）~~
解题步骤就是找到容器的两个边中的最小值 乘以 两边之间的距离。

### 方法一：暴力解法
``` c
#define MAX(a,b) (a>b)?a:b  
#define MIN(a,b) (a<b)?a:b
int maxArea(int* height, int heightSize){
    //int i, j, m = 0;
    //int len = (heightSize * heightSize - heightSize) / 2;  // 所有容器的个数
    //int n[len] = {0}; // 用来存放所有容器的值
    //int n[1000000] = {0};
    int i, j;
    int max = 0;   //最大容器的值
/*
    //找出所有容器的值， 并存放在n[]中
    for(i=0; i<heightSize-1; i++)
    {
        for(j=i+1; j<heightSize; j++,m++)
        {
            if(height[i] >= height[j])
            {
                n[m] = height[j] * (j-i);
            }
            else
            {
                n[m] = height[i] * (j-i);
            }
        }
    }
*/
    //找出所有容器的值，并与max 比较
    for(i=0; i<heightSize-1; i++)
    {
        for(j=i+1; j<heightSize; j++)
        {
            int n = j-i;
            int m = MIN(height[i],height[j]);
            max = MAX(max, n*m);
        } 
    }
/*   
    //找到最大容器的值
    max = n[0];
    for (i=0; i<1000000 ; i++)
    {
        if(max <= n[i])
        {
            max = n[i];
        }
    }
*/
    return max;
}
```

#### 方法二：双指针
>思路：通过四边形的面积公式我们可以知道，面积受到四边形宽度以及高度所影响；  
假设1：移动两个指针高度较高的，下一个指针高度高于四边形高度，宽度减小，四边形高度不变，面积值减小  
假设2：移动两个指针高度较高的，下一个指针高度低于四边形高度，宽度减小，高度减小，面积值依旧减小  
假设3：移动两个指针高度较低的，下一个指针高度高于四边形高度，宽度减小，高度增加，面积值可能增加  
假设4：移动两个指针高度较低的，下一个指针高度低于四边形高度，宽度减小，高度减小，面积值减小  
首先通过假设，在移动较小指针的过程中可以寻找较大值。
``` c
#define MAX(a,b) (a>b)?a:b  
#define MIN(a,b) (a<b)?a:b
int maxArea(int* height, int heightSize)
{
    int max = 0, l = 0, r = heightSize - 1;
    while(l < r)
    {
        int n = MIN(height[l],height[r]);
    	int m = r-l;
        max = MAX(n*m,max);
        if(height[l] < height[r])
            l++;
        else
            r--;
    }
    return max;
}
```