# 					strstr函数的实现

### 编写完整的程序。采用顺序存储方式存储串，计算一个子串在字符串中首次出现的位置，输出这个下标。

输入说明：字符串ms 字符串zs

输出说明：zs在ms中首次出现下标

输入样例：baadefaadcb aadc

输出样例：6



### **方法一：**

两层循环，暴力查找，这种算法效率较低，在极端情况下算法的时间复杂度会极高。高效算法请看法二,KMP算法。

```c
#include<stdio.h>

int mystrstr(const char *haystack, const char *needle) {
	const char *p1;
	const char *p2;
	const char *p1_advance = haystack;
	for (p2 = &needle[1]; *p2; ++p2) {
		p1_advance++; // advance p1_advance M-1 times
	}
	for (p1 = haystack; *p1_advance; p1_advance++) {
		char *p1_old = (char*) p1;
		p2 = needle;
		while (*p1 && *p2 && *p1 == *p2) {
			p1++;
			p2++;
		}
		if (!*p2) return p1 - haystack - 1;
		p1 = p1_old + 1;
	}
	return -1;
}

int main()
{
    char S[1000],T[100];
    int i,j;
    printf("请输入主串和子串（请用空格将主串和子串分开）：\n");
    scanf("%s%s",S,T);
    printf("%d",mystrstr(S,T));
}

```



###**方法二**

```c

```

