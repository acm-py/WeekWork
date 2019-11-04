//先将所有人飞往B市，算出具体价格，然后从中挑出N个人，让其再飞往A市。价格
//价格进行变动num-i1+i0=i0-i1+num
//算出i0-i1最小的N个人，去A市
int cmp(const void *a,const void *b)
{
   return *(int *)a-*(int *)b;
}

int twoCitySchedCost(int** costs, int costsSize, int* costsColSize)
{
    int num=0;
    int arr[costsSize];
    //算出具体B市价格
    for(int i=0;i<costsSize;i++)
    {      
            num+=costs[i][1];
            arr[i]=costs[i][0]-costs[i][1];
    }
    //算出i0-i1最小的N个人
    qsort(arr,costsSize,sizeof(arr[0]),cmp);
    for(int i=0;i<costsSize/2;i++)
    {
        num+=arr[i];
    }
    
    return num;
}
