# 出圈

## 题目描述

设有n个人围坐一圈并按顺时针方向从1到n编号，从第1个人开始进行1到m的报数，报数到第个m人，
此人出圈，再从他的下一个人重新开始1到m的报数，如此进行下去直到所剩下一人为止。

## 输入
```chameleon
输入多行，每行２个数，分别表示n和m.
```

## 输出
```chameleon
计算每一行中最后剩下这个人的编号．
```

## 样例
```chameleon
输入：
10 3

输出：
4
```

>题解：
用单循环链表去做。

### 代码如下（单循环链表）：
```chameleon
#include <stdio.h>
#include <malloc.h>

typedef struct student{
	int number;
	struct student* next;
}*PNODE,NODE;

//函数声明
PNODE creat( int n );  //创建链表 
void function(PNODE l1, int len);  //对链表进行相关操作 

int main()
{
	int n, len; //n 是所有学生的人数，len 从第几个删除 
	PNODE pHead;  //创建链表的头指针 
	while(scanf("%d %d",&n,&len) != EOF)
	{
		pHead = creat( n );   //创建链表 
		function( pHead, len);
	} 
	
	return 0;
}

//创建一个循环单链表 
PNODE creat( int n )
{
	int i;
	
	PNODE pHead = (PNODE)malloc(sizeof(NODE)); //创建一个不存放有效数据的头节点 
	PNODE pTail = pHead;  //定义一个一直指向尾节点的节点 
	pTail->next = NULL;
	
	for(i=1; i<=n; i++)   //创建 n 个节点 
	{
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		pNew->number = i;  //存入编号 
		pTail->next = pNew;
		pTail = pNew;
	}
	pTail->next = pHead->next;
	
	return pHead;
} 

void function(PNODE l1, int len)
{
	int i;
	PNODE pTail = l1->next;
	free(l1);  //释放头节点 
	PNODE pNew = NULL;
	
	while(pTail->next != pTail)
	{
		for(i=0; i<len-2;i++)  //移动到离开的人的节点的前一个，只需要移动 len-2 次 
			pTail = pTail->next;
		pNew = pTail->next; //记录要删除的节点 
		pTail->next = pNew->next;//把节点移动到要删除节点的下一位开始报数的人 
		pTail = pTail->next;
		free(pNew); //释放节点 
	}
	printf("%d\n",pTail->number); //输出最后一个人的编号 
	free(pTail);//释放最后一个节点 
} 
 
```

时间~~2019年12月5日 18：00~~