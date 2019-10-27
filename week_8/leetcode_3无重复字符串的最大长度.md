# **leetcode_3无重复字符串的最大长度**

## **方法一：滑动窗口法**

```c
// c语言代码
int lengthOflongestSubstring(char* s)
{
   int len = 0,i,j,k,temp;
    // i 为前标
   for(i = 0;s[i] != '\0'; i++)
   {
       // j 为后标
       for(j = i + 1;s[j] != '\0'; j++)
       {
           // 游标
           for(k = i; k < j; K++)
               // 上一个字符等于下一个字符
               if(s[k] == s[j]) break;
  			// 结束本层循环，j不变。
           if(k != j) break;
       }
       temp = j - i;
       if(len < temp)
           len = temp;
   }
    return len;
}
```

```python
# python 代码
lass Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 如果字符串s为空，返回0
        if not s:return 0
        # 保存窗口内字符串
        lookup = list()
        n = len(s)
        max_len = 0
        # 当前窗口长度
        cur_len = 0
        for i in range(n):
            val = s[i]
            # 如果该值不在窗口中
            if not val in lookup:
                # 添加到窗口内
                lookup.append(val)
                # 当前长度+1
                cur_len+=1
            # 如果该值在窗口中已存在
            else:
                # 获取其在窗口中的位置
                index = lookup.index(val)
                lookup = lookup[index+1:]
                lookup.append(val)
                # 当前长度更新为窗口长度
                cur_len = len(lookup)
            # 如果当前长度大于最大长度，更新最大长度值
            if cur_len > max_len:max_len = cur_len
        return max_len
```

## **方法二:哈希算法**

```c
int lengthOfLongestSubstring(char * s){
    int start = 0, end = 0, maxlen = 0;
    char map[256] = {0};
    map[(int)*(s+start)] = 1;
    
    while( *(s+end) != 0 )
    {
        // 取无重复中最长的字符
        maxlen = maxlen>(end-start+1)?maxlen:(end-start+1);
        ++end;
        while( 0 != map[ (int)*(s+end) ] )//将要加入的新元素与map内元素冲突
        {
            map[ (int)*(s+start) ] = 0;
               ++start;
        }
        map[(int)*(s+end)] = 1;
    }
    
    return maxlen;
}
// 这个方法很巧妙
// 把无重复的字符串都存入map
// 取无重复中最长的字符
```

## **方法三：效率低下的遍历**

```python
'''
遍历整个字符串，把正在遍历的元素添加到一个列表，下一次遍历的时候，若这边元素不在列表，则继续添加。若在的话，则求出当前列表的长度，添加到一个新的列表（由长度组成的列表）。清空列表，然后循环判断方法，遍历完毕，返回长度列表的最大值。
'''
# 代码如下
def string(str):
    str_list=[]
    str_len=[]
    for i in str:
        if i not in str_list:
            str_list.append(i)
        else:
            str_len.append(len(str_list))
            str_list = []
            str_list.append(i)
    return max(str_len)
```

