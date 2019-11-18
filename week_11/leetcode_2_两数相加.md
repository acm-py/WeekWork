# 两数相加
给出两个非空的链表用来表示两个非负的整数。  
其中，它们各自的位数是按照逆序的方式存储的，  
并且它们的每个节点只能存储一位数字。  
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。  
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。  

## 示例：
``` c
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
```
***
完整代码实现：
``` c
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h> 

//定义数据类型 
typedef struct Node
{
	int date; //数据域
	struct Node* pNext;  //指针域	
} NODE, *PNODE;

//函数声明 
PNODE create_list(void); //创建链表
void traverse_list(PNODE pHead);  //输出链表
PNODE addTwoNumbers(PNODE l1, PNODE l2);  //两个数求和
void del(PNODE l);  //释放节点

int main(void)
{
	PNODE l1 = NULL, l2 = NULL, l3 = NULL;
	
	l1 = create_list();  // create_list()功能: 创建一个非循环单链表 ，
	l2 = create_list();       //并将该链表的头节点的地址付给l1,l2。 
	traverse_list(l1);   //遍历链表 
	traverse_list(l2);
	
	l3 = addTwoNumbers(l1, l2);
	traverse_list(l3);
	
	del(l1);
	del(l2);
	del(l3);	
	
	return 0;
} 

void del(PNODE l)
{
	while(l != NULL)
	{
		PNODE tail = l;
		l = l->pNext;
		free(l);
	}
}

PNODE create_list(void)
{
	int len;  //用来存放有效节点的个数 
	int i;
	int val;  //用来临时存放用户输入的节点的值 
	
	//分配了一个不存放有效数据的头节点 
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if(NULL == pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	
	printf("请输入您需要生成的链表节点的个数：len = ");
	scanf("%d", &len);
	
	PNODE pTail = pHead;  //定义一个一直指向尾节点的节点 
	pTail->pNext = NULL;    
	
	for (i=0; i<len; i++)
	{
		printf("请输入第%d个节点的值：", i+1);
		scanf("%d", &val);
		
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if(NULL == pNew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->date = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;  
	}
	
	return pHead;	
} 

void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while(p != NULL)
	{
		printf("%d\n", p->date);
		p = p->pNext;
	}
	printf("\n");
} 

PNODE addTwoNumbers(PNODE l1, PNODE l2) 
{
	//初始化空头
	PNODE head = (PNODE)malloc(sizeof(NODE));
	head->pNext = NULL;
	PNODE tail;
	tail = head;
	tail->pNext = NULL;
	PNODE p1 = l1->pNext;
	PNODE p2 = l2->pNext;

	int carry = 0; //进位

	//循环，直到跳出两个链表
	//当两条链表一样长时只需这一次处理，但是当不一样长时，只能处理一样长的大小
	while (p1 != NULL && p2 != NULL)
	{
		//当前结点的和，注意加上进位
		int sum = p1->date + p2->date + carry;
	//	printf("p1->date=%d p2->date=%d carry=%d\n",p1->pNext->date,p2->pNext->date,carry);
		//当前结点和大于等于10时
		if (sum >= 10)
		{
			sum -= 10;   //当前结点的值-10，变为个位
			carry = 1;     //大于10，进位1
		}
		else
		{
			carry = 0;
		}

		//初始化结点,尾添加, 必须先将尾指针移动到新的尾结点上再赋值，因为不这么做的话，第一个结点无法正确赋值(因为这时候尾指针还没有真正移到第一个结点上，此时指向的还是头结点)
		tail->pNext = (PNODE)malloc(sizeof(NODE));
		tail = tail->pNext;
		tail->date = sum;
		

		p1 = p1->pNext;
		p2 = p2->pNext;
	}

	//当两条链表不一样长时，其中一者为NULL了，另一者还没完，这时候用p1指向没完的那一条链表，继续遍历
	if (p1 == NULL)
	{
		p1 = p2;
	}
	else if (p2 = NULL)
	{
		p1 = p1;
	}

	//遍历剩余部分
	while (p1 != NULL)
	{
		int sum = p1->date + carry; //带上进制计算当前结点和

		if (sum >= 10)
		{
			sum -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		//继续朝合并的链表中添加结点
		tail->pNext = (PNODE)malloc(sizeof(NODE));
		tail = tail->pNext;
		tail->date = sum;
		p1 = p1->pNext;
	}

	//如果最后一位还有进制，再申请一个结点存1
	if (carry == 1)
	{
		tail->pNext = (PNODE)malloc(sizeof(NODE));
		tail = tail->pNext;
		tail->date = 1;
		
	}
	
	tail->pNext = NULL; //尾指针赋空，结尾

	//printf("%d",head->pNext->date); //调试用的
	return head;
}
```
