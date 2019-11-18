#include <stdio.h>

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) 
{
	//��ʼ����ͷ
	struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
	head->next =NULL;
	struct ListNode* tail;
	tail = head;
	struct ListNode* p1 = l1;
	struct ListNode* p2 = l2;

	int carry = 0; //��λ

	//ѭ����ֱ��������������
	//����������һ����ʱֻ����һ�δ������ǵ���һ����ʱ��ֻ�ܴ���һ�����Ĵ�С
	while (p1 != NULL && p2 != NULL)
	{
		//��ǰ���ĺͣ�ע����Ͻ�λ
		int sum = p1->val + p2->val + carry;
		//��ǰ���ʹ��ڵ���10ʱ
		if (sum >= 10)
		{
			sum -= 10;   //��ǰ����ֵ-10����Ϊ��λ
			carry = 1;     //����10����λ1
		}
		else
		{
			carry = 0;
		}

		//��ʼ�����,β���, �����Ƚ�βָ���ƶ����µ�β������ٸ�ֵ����Ϊ����ô���Ļ�����һ������޷���ȷ��ֵ(��Ϊ��ʱ��βָ�뻹û�������Ƶ���һ������ϣ���ʱָ��Ļ���ͷ���)
		tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		tail = tail->next;
		tail->val = sum;
		

		p1 = p1->next;
		p2 = p2->next;
	}

	//����������һ����ʱ������һ��ΪNULL�ˣ���һ�߻�û�꣬��ʱ����p1ָ��û�����һ��������������
	if (p1 == NULL)
	{
		p1 = p2;
	}
	else if (p2 = NULL)
	{
		p1 = p1;
	}

	//����ʣ�ಿ��
	while (p1 != NULL)
	{
		int sum = p1->val + carry; //���Ͻ��Ƽ��㵱ǰ����

		if (sum >= 10)
		{
			sum -= 10;
			carry = 1;
		}
		else
		{
			carry = 0;
		}
		//�������ϲ�����������ӽ��
		tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		tail = tail->next;
		tail->val = sum;
		

		p1 = p1->next;

	}

	//������һλ���н��ƣ�������һ������1
	if (carry == 1)
	{
		tail->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		tail = tail->next;
		tail->val = 1;
		
	}
	
	tail->next = NULL; //βָ�븳�գ���β

	//��Ϊ���ǲ��ܷ���ͷ��㣬����Ҫ��ͷ����ͷ��ˣ�����Ҫͷָ���Ƶ���һ�����
	struct ListNode* pTemp = head;
	head = head->next;
	free(pTemp);

	return head;
}

int mian()
{
	struct ListNode 
	{
    	int val;
    	struct ListNode *next;
	}
	
	return 0;
}

