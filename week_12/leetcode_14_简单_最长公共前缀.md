
# 最长公共前缀

编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

## 示例如下：
```chameleon
输入: ["flower","flow","flight"]
输出: "fl"
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
```
>说明：
所有输入只包含小写字母 a-z 。

## 代码如下（水平扫描）：
```chameleon
char * longestCommonPrefix(char ** strs, int strsSize){
    if (strsSize == 0) {
        char *ret = (char *)malloc(1);
        ret[0] = '\0';
        return ret;
    }
    if (strsSize == 1) 
        return strs[0];
    int i = 0, j, m = 1, tmp;
    for (; m; ++i) {
        tmp = strs[0][i];
        for (j = 0; j  < strsSize; ++j) 
            if ((!strs[j][i]) || (strs[j][i] != tmp))//!strs[j][i])意思是每个单词比对完后此判断
                {   
                    m = 0;     
                    break;
                }
    }
    strs[0][i-1] = '\0';
    return strs[0];
}
```
