# **四道简单leet_code题**

## **1. leetcode_67_二进制求和**

### **非内置函数解法**

```python
# python语言描述
class Solution:
    def addBinary(self, a: str, b: str) -> str:
        # 题目要求中已经把输出限制为非空字符串且只包含数字0和1
        r, p = '',0
        d = len(b) - len(a)# 长度差
        # 字符串拼接（乘法和加法）,保证长度相同
        # 字符串 * 负数 = ''
        a = '0' * d + a
        b = '0' * -d + b
        for i,j in zip(a[::-1], b[::-1]):
            s = int(i) + int(j) + p
            r = str(s % 2) + r
            p = s // 2 # 前一位是否进位
        return '1' + r if p else r # 最高位是否进位
```

### **内置函数解法**

```python
lass Solution:
    def addBinary(self, a: str, b: str) -> str:
        return bin(int(a, 2) + int(b, 2))[2:]
```

#### **可能是python解释器对内置函数进行了优化，要比普通写法快一些**

## **2.数据结构作业-从键盘读入一个字符串，统计其中单词的个数**

### 算法1：

```c
#include<stdio.h>
int main()
{
    char str[100];
    int i, count;
    count = 0;
    // 读取整个字符串
    gets(str);
    
    // 注意要用单引号'' 双引号表示字符串
    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] == ' '&&str[i+1] != ' ')
            count++
    }
    if(str[0] != ' ')
        count++;
    printf("%d",count);
    return 0;
}
```



### 算法2：

```c
#include<stdio.h> 
#include<string.h>
int main()
{
	char str[1000];
	int i, count, len;
	count = 0;
	gets(str);
	
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] != ' ' && str[i+1] == ' ')
			count++;
	}
	len = strlen(str);
	if(str[len-1] != ' ')
		count++;
	printf("%d\n",count);
	
	return 0;
}

```

### 算法3：

```c
#include<stdio.h>


int main()
{
	char str[1000]; 
	int i, word, count;
	word = 0;
	count = 0;
	gets(str);
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == ' ')
			word = 0;
		if(str[i] != ' '&& word == 0)
			{
				count++;
				word = 1;
			}
	}
	printf("%d\n",count);
	return 0; 
}

```

## **3.leetcode_58_最后一个单词的长度**

### 算法1：巧解

```python
# python 语言描述
'''

给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。

如果不存在最后一个单词，请返回 0 。

说明：一个单词是指由字母组成，但不包含任何空格的字符串。


输入: "Hello World"
输出: 5
'''
# 先去掉字符串-1才是单词的长度 （因为有一个'\0'）结束符
# 将字符串按照空格分组
# 取分组后的最后一项
# 计算长度
class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        return len(s.rstrip().split(" ")[-1])
```

### 算法2：正常思路

```python
# python语言描述
'''
1.将字符串首位的空格去掉
2.字符串有两种可能
	1.空的字符串 return 0
	2.非空 最后一个单词可以切片.



'''
class Solution(object):
    def lengthOfLastWord(self, s):
        s = s.strip()
        if len(s) != 0:
            return len(s.split(' ')[-1])
        else:
            return 0
```

## **4.leetcode_69_x的平方根**

### 二分法：

![image-20191027201914812](F:\hmb_work\week_8\image-20191027201914812.png)

```python
#python 语言描述
'''
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

'''
class Solution:
    def mySqrt(self, x: int) -> int:
        if x == 0:
            return 0

        left = 1
        right = x // 2

        while left < right:
            # 注意：这里一定取右中位数，如果取左中位数，代码可能会进入死循环
            # mid = left + (right - left + 1) // 2
            mid = (left + right + 1) >> 1
            square = mid * mid

            if square > x:
                right = mid - 1
            else:
                left = mid
        # 因为一定存在，因此无需后处理
        return left
```

