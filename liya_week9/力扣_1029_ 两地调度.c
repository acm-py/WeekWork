//�Ƚ������˷���B�У��������۸�Ȼ���������N���ˣ������ٷ���A�С��۸�
//�۸���б䶯num-i1+i0=i0-i1+num
//���i0-i1��С��N���ˣ�ȥA��
int cmp(const void *a,const void *b)
{
   return *(int *)a-*(int *)b;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize)
{
    int num=0;
    int arr[costsSize];
    //�������B�м۸�
    for(int i=0;i<costsSize;i++)
    {      
            num+=costs[i][1];
            arr[i]=costs[i][0]-costs[i][1];
    }
    //���i0-i1��С��N����
    qsort(arr,costsSize,sizeof(arr[0]),cmp);
    for(int i=0;i<costsSize/2;i++)
    {
        num+=arr[i];
    }
    
    return num;
}
