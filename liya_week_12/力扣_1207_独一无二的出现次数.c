int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b; //��С��������
    //return *(int *)b - *(int *)a; �ɴ�С����
}
bool uniqueOccurrences(int* arr, int arrSize)
{
    //�������飬����arr��Ԫ����Ϊtemp������±�
    int *temp;
    temp = (int *)calloc(sizeof(int),2001);
    for(int i=0;i<arrSize;i++)
    {
        temp[arr[i]+1000]++;
    }
    qsort(temp, 2001, sizeof(int), cmp);
    for(int i=0;i<2000;i++)
    {
 
        if(temp[i]==0) 
        {
            continue;
        }
        if(temp[i]==temp[i+1])
        {
            free(temp);
            return false;
        }
    }
    return true;
}
