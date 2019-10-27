/*
leetcode_7_整数反转
 
给出一个 32 位的有符号整数，你需要将这个整数中每位上的数字进行反转。

分析：
   反转：就是把整数倒置一下 有最小位变成最大位 
*/ 

#include <stdio.h>
#include <math.h>

int reverse(int x)
{	
	long int r = 0;
	//将整数倒置 
	while(x != 0)
	{
		r = 10*r + x%10;
		x = x/10;	
	} 
	//判断 整数是否超出范围
	if(r > pow(2,31)-1 || r < -pow(2,31))
		return 0;   //如果超出范围直接返回
	return r;   // 返回  倒置后的数 
} 

int main(void)
{
	long int i;
	printf("请输入一个整数:");
	scanf("%d",&i);
	printf("反转前的数的值是:%d\n",i);
	
	printf("反转之后的数的值是：%d\n",reverse(i));
	
	return 0;
}
