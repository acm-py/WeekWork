# 合并两个有序数组

给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

>说明：
· 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。  
· 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。

## 示例：
```chameleon
输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
```

>题解：
先合并两个两个数组，然后排序。

### 代码如下：
```chameleon
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){
    int i, j, t;
    //如果nums2中没有数据，直接终止函数
    if(n == 0)
    {
        return;
    }
    //如果 nums2 中有数据。且 nums1 中没有数据，则把 nums2 中的数据放到 nums1 中
    if(m == 0)
    {
        for(i=0; i<n; i++)
        {
            nums1[i] = nums2[i];
        }
        return;
    }
    for (i = m, j = 0; i < (n+m); i++,j++)  //合并两个数组
    {
        nums1[i] = nums2[j];
    }
    // 冒泡排序
    for(i = 0; i < (m+n-1); i++)
    {
        for(j = i+1; j < (m+n); j++)
        {
            if(nums1[i] > nums1[j])
            {
                t = nums1[i];
                nums1[i] = nums1[j];
                nums1[j] = t;
            }
        }
    }
    return;
}
```

时间~~2019年12月5日 20点34分~~