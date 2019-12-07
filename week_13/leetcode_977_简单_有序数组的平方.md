# 有序数组的平方

给定一个按非递减顺序排序的整数数组 A，返回每个数字的平方组成的新数组，要求也按非递减顺序排序。

 ## 示例：
 ```chameleon
输入：[-4,-1,0,3,10]
输出：[0,1,9,16,100]
输入：[-7,-3,2,3,11]
输出：[4,9,9,49,121]
```

>提示：  
1、1 <= A.length <= 10000  
2、-10000 <= A[i] <= 10000  
3、A 已按非递减顺序排序。

>题解：  
1、先把数组中的每个数值平方之后，再排序。  
2、找出正负数的分割处，并标记下来。然后比较大小并储存在新的数组中。

### 代码一（快速排序）：
```chameleon
//超出时间限制
int* sortedSquares(int* A, int ASize, int* returnSize){
    *returnSize = ASize;
	if(ASize == 0)   
        return A;
    int i,j,t;
    for(i=0; i<ASize; i++)
    {
        A[i] = (A[i] * A[i]);
    }
    for(i=0; i<ASize-1; i++)
    {
        for(j=i+1; j<ASize; j++)
        {
            if(A[i] > A[j])
            {
                t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
        }
    }
    return A;
}
```

### 代码二(双指针法)：
```chameleon
int* sortedSquares(int* a, int n, int* returnSize){
	*returnSize=n;
	if(n==0) return a;
	int p=0,q=-1;
	for(int i=0;i<n;i++){
		if(a[i]>=0) {
			p=i;
			q=i-1;
			break;
		}
	} 
	int k=0;
	int *res=(int *)malloc(sizeof(int)*n);
	while(p<n&&q>=0){
		if(a[p]*a[p]<a[q]*a[q]){
			res[k++]=a[p]*a[p];
			p++;
		}
		else{
			res[k++]=a[q]*a[q];
			q--;
		} 
	} 
    //接下来的代码是用来储存最两边的数值
	while(p<n) {
		res[k++]=a[p]*a[p];
		p++;
	}
	while(q>=0){
		res[k++]=a[q]*a[q];
		q--;
	}
	return res;
}
```

时间 ~~2019年12月6日 20点56分~~。