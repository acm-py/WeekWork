#include<stdio.h>
#include<malloc.h>

typedef struct linknode   // ������Ͷ���
{
    char data;            // ��������������Ϊ�ַ���
    struct linknode *next;    // nextΪָ���� 
}linknode;

linknode *head;        // ���� head Ϊ�ṹ����ָ����� 
int n;        //nΪ���Ա�ĳ���


//β�巨����
// ��ͷ����β�巨����������
void createlist()
{
    char x;    
    int z=1;
    linknode *p,*s;
    n=0;         //���Ա�ĳ��ȸտ�ʼΪ0
                    
    head=(linknode *)malloc(sizeof(linknode));  // ����ͷ���
    head->next = NULL;
    p=head;         //βָ���ֵָ��ͷ���
      
    printf("\n\t\t����������㡣��xλ�������!\n");
    while(z)
    {
        printf("\n\t\t������һ���ַ����ݣ������س���\n");
        scanf("\n%c",&x);
            
        if(x!='x')   // 'x'Ϊ���������
        {
            s=(linknode *)malloc(sizeof(linknode));  // �����½�� 
            n++;                  //����1
            s->data=x;  
            p->next=s;         // �½������β 
            s->next=NULL;
            p=s;               // βָ�� p ָ���µı�β
        }
            
        else
        {
            z=0;       //��x��������ѭ��
        }

    }
}


//�������㷨
void insertList(int i, char x)  //i �ĺϷ�λ��Ϊ��1<=i<=n 
{ 
   linknode *s,*p;
   int j=0;   //j��������
   p=head;

   printf("\t\t������Ҫ���λ�ú���ֵ<i x>�������س���\n");
   scanf("\n%d %c",&i,&x);
   if(i>0)
   {
       while(p!=NULL && j<i-1)   //�ڽ�㷶Χ�ڲ��ҵ�j<i-1ʱѭ��ִ��
       {
            j++;
            p=p->next;   //����ָ��
       }   //��j==iʱѭ������

       if(p!=NULL)  //p���ڽ�㷶Χ�ڣ��϶�j==i,˵���ҵ���
       {
            s=(linknode*)malloc(sizeof(linknode));  //�����½��
            s->data=x;
            s->next=p->next;
            p->next=s;  //���½�����λ��Ϊi�Ľ��p�ĺ���
            n++;    //��ĳ��ȼ�1
            printf("\n\t\t����ɹ�");
       }
	   else
       {
            printf("\n\t\t���Ա�Ϊ�ջ����λ�ó���");
       }
   }
   else
   {
        printf("\n\t\t��Ǹ!����λ�ô��������²���!");
   }
}






//ɾ��������Ϊx�Ľ��Ԫ��
void deleteList(char x)  
{
    linknode *p,*q;
    q=head;
    p=head->next;   //qָ���һ��Ԫ��
    printf("\n\t\t������Ҫɾ��������Ԫ��:");
    scanf("\t\t%c",&x);

   while(p!=NULL && p->data!=x)
   {
        q=p;
        p=p->next;
   }            //˳�����ң�ֱ��p->data==xѭ����ֹ
   if (p!=NULL) 
   {          
        q->next=p->next;        // ���p���ڷ�Χ�ڣ��϶�p->data==x
        free(p);
        n--;   //��ĳ��ȼ�1
        printf("\n\t\tɾ���ɹ�,���%c�Ѿ���ɾ��!",x);
   }
   else 
        printf("\n\t\t��Ǹ!û���ҵ���Ҫɾ���Ľ��\n");

}

//��ʾ���Ա�
void showlist()
{
    linknode *p=head;
    printf("\n\t\t��ʾ���Ա������Ԫ��:\n\t\t");

    while(p->next!=NULL)    //����Ϊ��
    {
        printf("%5c",p->next->data);
        p=p->next;      //����ָ��
    }

    if(head->next==NULL)
        printf("\n\t\t����Ϊ��");
}


//����Ų���
linknode *queryList1(linknode *head, int i)  
    //  head�����Ѵ��ڵ������ͷָ��
    //  i ����Ҫ���ҵĽ���λ��
    //��ͷ��㿪ʼ˳��ɨ��
{ 
    linknode *p;   //��ָ�� p ָ��ǰɨ�赽�Ľ�㡣
    int j=1;       //�� j ��ͳ����ɨ�������ļ�������j �ĳ�ֵΪ 1 ��
    p=head->next;        //p �ĳ�ֵָ�����еĵ�һ��Ԫ��.
    
    printf("\n\t\t������Ҫ���ҵĽ���λ�ã������س���\n");
    scanf("\n%d",&i);

    while( p->next!=NULL && j<i )
    {
        p=p->next;
        j++;           //�� p ɨ����һ�����ʱ��j �Զ��� 1 
    }
    if(j==i)          //�� j=iʱ��ָ�� p ��ָ�Ľ����ǵ� i �����
    {
        printf("\n\t\t���ҵĴ˽������λ�õ�ֵΪ��%c",p->data);
    }

    else
    {
        printf("\n\t\tδ�ҵ��˽ڵ㣬��ȷ�������Ƿ���ȷ!!");    
    }
    
                   
}

//���ĳ��� 
void lengthList()
{
    linknode *p;
    n=0;
    p=head;
    while(p->next!=NULL && p!=NULL)
    {
        n++;     //��ĳ��ȼ�1
        p=p->next;    //����ָ��
     
    }
    if(p->next==NULL)      //�������β
    {
        printf("\n\t\t���Ա�ĳ���Ϊ:%d",n);    
    }else
    {
        printf("\n\t\t��������");
    }


}


int main()
{
    int choose,i,j=1;
    char x;
    head = NULL;
    while(j)
    {
    	printf("\n\t\t\t\t ���Ա���ϵͳ");
        printf("\n\t\t*************************************************");
        printf("\n\t\t* \t         1------�� �� \t\t\t* ");
        printf("\n\t\t* \t         2------�� �� \t\t\t* ");
        printf("\n\t\t* \t         3------ɾ �� \t\t\t* ");
        printf("\n\t\t* \t         4------�� ʾ \t\t\t* "); 
        printf("\n\t\t* \t         5------�� �� \t\t\t* ");
        printf("\n\t\t* \t         6------�� �� �� \t\t* ");
        printf("\n\t\t* \t         0------�� �� \t\t\t* ");
        printf("\n\t\t*************************************************");
        printf("\n\t\t��ѡ��˵����루0-6����");
        scanf("%d",&choose);
        printf("\n");
        if(choose==1)
        {
            createlist();
            printf("\n\t\t\t\t ����ɹ�!!!\n");
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
                printf("\n\t\t��Ǹ!���Ա�Ϊ�գ����Ƚ���!");
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
            printf("�����������������!");
        }
    }
}

