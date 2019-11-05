# 							杨辉三角II

给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。



在杨辉三角中，每个数是它左上方和右上方的数的和。

示例:

输入: 3
输出: [1,3,3,1]



### 思路

定义一个一维数组保存结果

杨辉三角第n行有n+1个数，

从第一行开始计算杨辉三角的值，保存在一维数组中，后续行的值根据上一行的结果，并将结果覆盖到一维数组。

```c
int* getRow(int rowIndex, int* returnSize){
    *returnSize = rowIndex + 1;
    int* num = (int*) malloc ((rowIndex + 1) * sizeof(int));
    for(int i = 0;i <= rowIndex;i++)
    {
        for(int j = i;j >= 0;j--)
        {
            if(j == 0 || j == i) num[j] = 1;
           else num[j] = num[j] + num[j-1];
        }
    }
        
    return num;
}
```

