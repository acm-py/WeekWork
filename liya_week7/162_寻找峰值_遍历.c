#include<stdio.h>
int findPeakElement(int* nums, int numsSize){
    int i=0;
    if(numsSize<2)
    {
        printf("0");
		return 0;
    }
        
    for(i=1;i<numsSize-1;i++)
    {
        if(nums[i]>nums[i-1]&&nums[i]>nums[i+1])
        {
            printf("%d",i);
			return i;
            break;
        }
    }
    if(nums[numsSize-2]<nums[numsSize-1])
         { 
         printf("%d",numsSize-1);
        return numsSize-1;
         }
    else
    {
    	printf("0");
        return 0;
    }
    printf("%d",i);
    return i;
}
int main()
{
    int* a;
    int n,i=0,k=0;
    printf("���������鳤��,����Ϊ0\n"); 
    scanf("%d",&n);
    //  printf("Ԥ��������������и���ճ��\n");
    // printf("1 2 1 3 5 6 4\n");
    // printf("1 2 3 1 5 6 4 9 3 2 4 5\n");
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
    printf("��һ��ֵ����Ϊ");
    findPeakElement( a, n);
}
