---
title: Manacher 算法&&力扣 5.最长回文子串
date: 2019-11-09 17:1:53
tags: 算法
categories:
- [算法]
- [题解]
thumbnail: /images/蜗牛.png
---

[单身](https://github.com/Mrliya/acm-py/raw/liya_18/Screenshots/a2.jpg)

Manacher（马拉车） 算法，字符串匹配算法的一种。一般用于求最长回文子串。应用范围较窄。
<!--more-->

## 算法例题

### [力扣 5.最长回文子串](https://leetcode-cn.com/problems/longest-palindromic-substring/)

给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

#### 示例 1

输入： “babad”
输出： “bad”
注意： “aba” 也是一个有效答案。

#### 示例 2

输入： “cbbd”
输出： “bb”
***

## 算法原理及实现

* Manacher 算法第一步：对原字符串 s 进行处理
* Manacher 算法第二步：构造辅助数组
* Manacher 算法第三步：根据辅助数组得出最长回文子串的下标元素长度等各项所需属性

### 第一步

由于字符串 s 元素个数可能为奇数也可能为偶数，所以首先对原字符串 s 进行处理。在原字符串 s 中每两个相邻的之间加入一个间隔字符 “#” 并在字符串开头和结尾加入 “$” 间隔字符。
原数组 |  | b |  | a |  | b |   | a |  | d |   |
---- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
更改之后 | $ | b | # | a | # |  b | # | a | # | d | $ |

1. 由此得出的字符串 s 一点是奇数个元素。
2. 间隔字符无固定要求，只需于字符串元素无关即可。

### 第二步

辅助数组的构造，运用中心扩散法，计算字符串 s 中，回文字符串的长度
既以在数组 i 位置的元素为中心，计算 i+1 位置的元素和 i-1 位置的元素是否相等，若相等则计算 i+2 于 i-2

更改之后的数组 | $ | b | # | a | # |  b | # | a | # | d | $ |
---- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- | --- |
数组下标 | 0 | 1 | 2 | 3 | 4 |  5 | 6 | 7 | 8 | 9 | 10 |
辅助数组的元素 | 0 | 1 | 0 | 3 | 0 |  3 | 0 | 1 | 0 | 1 | 0 |

### 第三步

由辅助数组得出最大的回文子串是下标为3和下标为5的两个元素

## 代码实现

``` c
char * longestPalindrome(char * s)
{
    int i=0,id,maxid,ans=1,pos=0;
    //找到的最长回文串的左端下标
    int left;
    //最长回文串的临时数组
    char * result;
    //字符串长度
    int str_length=strlen(s);

    //初始化新的数组,存放每个元素对应的回文半径
    int p[2*str_length+3];
    //构造新的字符数组，用来计算
    char new_str[2*str_length+3];
    new_str[0]='$';
    new_str[1]='#';
    for (i =0;i< str_length;i++)
    {
        new_str[2*i+2]=s[i];
        new_str[2*i+3]='#';
    }
    new_str[2*str_length+2]='\0';

    int len = 2*str_length+2;

    // 对每个字符求其回文半径，利用前面的数组
    // 最后面的'\0'不用求
    // 第一个字符"$"，p[0]=1
    id = 0;
    maxid = 1;
    p[0] = 1;
    for (i=1;i<len;i++)
    {
        // 判断前一次的回文最右端是不是包含当前判断的字符
        if (maxid > i)
        {
            p[i] = p[2*id-i] > (maxid-i)?(maxid-i):p[2*id-i];
        }
        else
        {
            p[i] = 1;
        }
        while(new_str[i+p[i]] == new_str[i-p[i]])
        {
            p[i]++;
        }
        if(p[i]+i> maxid)
        {
            maxid = p[i]+i;
            id = i;
        }
        if (ans<p[i])
        {
            ans = p[i];
            pos = i;
        }
    }


    left = (pos-ans)/2;
    result = (char*)malloc(sizeof(char)*ans);
    for (i=0;i<ans-1;i++)
    {
        result[i] = s[left+i];
    }
    result[ans-1] = '\0';

    return result;
}
```
