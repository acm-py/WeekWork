//��1234567Ϊ����KΪ3 
//���鷴ת����ת1234Ϊ4321�Լ�567Ϊ765
//��ת4321765Ϊ5671234
#include<stdio.h>
void  swap(int *x, int *y)
{
    int  temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void rotate(int* nums, int numsSize, int k)
{
if(k>numsSize)
    {
        k=k%numsSize;
    }
    if(k==0)
    {
    //    return nums;
    exit(0); 
      
    }
    //��ת1234
    int i=0;
    for( i=0;i<(numsSize-k)/2;i++)
    {
        swap(&nums[i],&nums[numsSize-k-i-1]);
    }
    //�ٻ�567
    for( i=0;i<k/2;i++)
    {
        swap(&nums[numsSize-i-1],&nums[numsSize-k+i]);
    }
    //ȫ�巴ת
    for( i=0;i<numsSize/2;i++)
    {
        swap(&nums[i],&nums[numsSize-i-1]);
    }
    
}
void main()
{
	int* a;
    int n,i=0,k=0;
    printf("���������鳤��,����Ϊ0\n"); 
    scanf("%d",&n);
    
      a = (int*)malloc(sizeof(int)*n);
       printf("�����������ݣ��Կո������Իس�����\n"); 
        while(1) 
    { 
        scanf("%d",&a[i++] );    
        if( getchar() == '\n') 
        { 
            break; 
        } 
    }
	printf("�������뷭ת�����鳤��\n");
	scanf("%d",&k);
	rotate( a, n, k);
	printf("���鷭ת��Ϊ\n");
	int x=0;
	for( x=0;x<n;x++)
	{
		printf("%d,",a[x]);
	}
	
}
