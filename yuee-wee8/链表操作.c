#include<stdio.h>
#include<malloc.h>

typedef struct linknode   // 结点类型定义
{
    char data;            // 数据域，数据类型为字符型
    struct linknode *next;    // next为指针域 
}linknode;

linknode *head;        // 定义 head 为结构类型指针变量 
int n;        //n为线性表的长度


//尾插法建表
// 带头结点的尾插法建立单链表
void createlist()
{
    char x;    
    int z=1;
    linknode *p,*s;
    n=0;         //线性表的长度刚开始为0
                    
    head=(linknode *)malloc(sizeof(linknode));  // 生成头结点
    head->next = NULL;
    p=head;         //尾指针初值指向头结点
      
    printf("\n\t\t请逐个输入结点。以x位结束标记!\n");
    while(z)
    {
        printf("\n\t\t请输入一个字符数据，并按回车：\n");
        scanf("\n%c",&x);
            
        if(x!='x')   // 'x'为输入结束符
        {
            s=(linknode *)malloc(sizeof(linknode));  // 生成新结点 
            n++;                  //表长加1
            s->data=x;  
            p->next=s;         // 新结点插入表尾 
            s->next=NULL;
            p=s;               // 尾指针 p 指向新的表尾
        }
            
        else
        {
            z=0;       //遇x结束链表循环
        }

    }
}


//插入结点算法
void insertList(int i, char x)  //i 的合法位置为：1<=i<=n 
{ 
   linknode *s,*p;
   int j=0;   //j用来计数
   p=head;

   printf("\t\t请输入要插的位置和数值<i x>，并按回车：\n");
   scanf("\n%d %c",&i,&x);
   if(i>0)
   {
       while(p!=NULL && j<i-1)   //在结点范围内并且当j<i-1时循环执行
       {
            j++;
            p=p->next;   //后移指针
       }   //当j==i时循环结束

       if(p!=NULL)  //p还在结点范围内，肯定j==i,说明找到了
       {
            s=(linknode*)malloc(sizeof(linknode));  //生成新结点
            s->data=x;
            s->next=p->next;
            p->next=s;  //将新结点插在位置为i的结点p的后面
            n++;    //表的长度加1
            printf("\n\t\t插入成功");
       }
	   else
       {
            printf("\n\t\t线性表为空或插入位置超界");
       }
   }
   else
   {
        printf("\n\t\t抱歉!插入位置错误，请重新插入!");
   }
}






//删除数据域为x的结点元素
void deleteList(char x)  
{
    linknode *p,*q;
    q=head;
    p=head->next;   //q指向第一个元素
    printf("\n\t\t请输入要删除的数据元素:");
    scanf("\t\t%c",&x);

   while(p!=NULL && p->data!=x)
   {
        q=p;
        p=p->next;
   }            //顺链查找，直到p->data==x循环终止
   if (p!=NULL) 
   {          
        q->next=p->next;        // 如果p还在范围内，肯定p->data==x
        free(p);
        n--;   //表的长度减1
        printf("\n\t\t删除成功,结点%c已经被删除!",x);
   }
   else 
        printf("\n\t\t抱歉!没有找到您要删除的结点\n");

}

//显示线性表
void showlist()
{
    linknode *p=head;
    printf("\n\t\t显示线性表的所有元素:\n\t\t");

    while(p->next!=NULL)    //链表不为空
    {
        printf("%5c",p->next->data);
        p=p->next;      //后移指针
    }

    if(head->next==NULL)
        printf("\n\t\t链表为空");
}


//按序号查找
linknode *queryList1(linknode *head, int i)  
    //  head接收已存在的链表的头指针
    //  i 接收要查找的结点的位置
    //从头结点开始顺链扫描
{ 
    linknode *p;   //用指针 p 指向当前扫描到的结点。
    int j=1;       //用 j 作统计已扫描结点数的计数器，j 的初值为 1 。
    p=head->next;        //p 的初值指链表中的第一个元素.
    
    printf("\n\t\t请输入要查找的结点的位置，并按回车：\n");
    scanf("\n%d",&i);

    while( p->next!=NULL && j<i )
    {
        p=p->next;
        j++;           //当 p 扫描下一个结点时，j 自动加 1 
    }
    if(j==i)          //当 j=i时，指针 p 所指的结点就是第 i 个结点
    {
        printf("\n\t\t查找的此结点所在位置的值为：%c",p->data);
    }

    else
    {
        printf("\n\t\t未找到此节点，请确认输入是否正确!!");    
    }
    
                   
}

//求表的长度 
void lengthList()
{
    linknode *p;
    n=0;
    p=head;
    while(p->next!=NULL && p!=NULL)
    {
        n++;     //表的长度加1
        p=p->next;    //后移指针
     
    }
    if(p->next==NULL)      //如果到表尾
    {
        printf("\n\t\t线性表的长度为:%d",n);    
    }else
    {
        printf("\n\t\t链表不存在");
    }


}


int main()
{
    int choose,i,j=1;
    char x;
    head = NULL;
    while(j)
    {
    	printf("\n\t\t\t\t 线性表子系统");
        printf("\n\t\t*************************************************");
        printf("\n\t\t* \t         1------建 表 \t\t\t* ");
        printf("\n\t\t* \t         2------插 入 \t\t\t* ");
        printf("\n\t\t* \t         3------删 除 \t\t\t* ");
        printf("\n\t\t* \t         4------显 示 \t\t\t* "); 
        printf("\n\t\t* \t         5------查 找 \t\t\t* ");
        printf("\n\t\t* \t         6------求 表 长 \t\t* ");
        printf("\n\t\t* \t         0------返 回 \t\t\t* ");
        printf("\n\t\t*************************************************");
        printf("\n\t\t请选择菜单号码（0-6）：");
        scanf("%d",&choose);
        printf("\n");
        if(choose==1)
        {
            createlist();
            printf("\n\t\t\t\t 建表成功!!!\n");
        }
		else if(choose==5)
        {
            queryList1(head, i);
            //queryList2(head, x);
        }
		else if(choose==2)
        {
            insertList(i, x);
        }
		else if(choose==3)
        {
            //deleteList(i);
            deleteList(x);
        }
		else if(choose==4)
        { 
            if(head==NULL)
            {
                printf("\n\t\t抱歉!线性表为空，请先建表!");
            }
			else
            {
                showlist();
            }
        }
		else if(choose==6)
        {
            lengthList();
        }
		else if(choose==0)
        {
            j=0;
        }
		else
        {
            printf("输入错误，请重新输入!");
        }
    }
}

