# **leetcode_5_最长回文子串**

## leetcode 官方给出了四种方法

### **1.反转字符串，与原字符串求最大公共子串。但是这种方法有错误**

- 当S = "abacdfgdcaba"  S' = "abacdgfdcaba";
- S及S'的最长公共子串为"abacd", 显然这不是回文。
- **为了纠正这一点，每当我们找到最长的公共子串的候选项时，都需要检查子串的索引是否与反向子串的原始索引相同。如果相同，那么我们尝试更新目前为止找到的最长回文子串；如果不是，我们就跳过这个候选项并继续寻找下一个候选。**
- 复杂度分析：
	-  时间复杂度O($$n^2$$)
	- 空间复杂度O($$n^2$$)

### **2.暴力法**

- 检索出所有字符串可能的开始和结束为止，并检验它是不是回文。

### **3.动态规划**

- ![image-20191026145236269](F:\hmb_work\image-20191026145236269.png)
- 复杂度分析
	- 时间复杂度: O($$n^2$$)
	- 空间复杂度:O($$n^2$$)

### **4.中心扩展算法**

- 事实上，只需要使用恒定的空间，我们就可以在O($$n^2$$)的时间内解决这个问题。我们观察到回文中心的两侧互为镜像。因此，回文可以从它的中心展开，并且只有2n-1个这样的中心。

- 你可能会问，为什么是2n-1个，而不是n个中心？原因在于所含字母为偶数的回文的中心可以在两个字母之间（例如：“abba”的中心在两个‘b’之间） 因为回文的中心要区分`单双` 

- 假如回文的中心为 双数，例如 abba，那么可以划分为 ab bb ba，对于n长度的字符串，这样的划分有 n-1 种。

- 假为回文的中心为 单数，例如 abcd, 那么可以划分为 a b c d， 对于n长度的字符串，这样的划分有 n 种。

- 对于 n 长度的字符串，我们其实不知道它的回文串中心倒底是单数还是双数，所以我们要对这两种情况都做遍历，也就是 n+(n-1) = 2n - 1，所以时间复杂度为 O(n)。

- 当中心确定后，我们要围绕这个中心来扩展回文，那么最长的回文可能是整个字符串，所以时间复杂度为 O(n)。

	所以总时间复杂度为 O($$n^2$$)====

	

	



### **5.Manacher算法**

### **思想类似kmp算法，也是尽量利用既有条件，不做重复性工作。添加了一个辅助数组 p**

```python
class Solution:
    # Manacher 算法
    def longestPalindrome(self, s: str) -> str:
        # 特判
        size = len(s)
        if size < 2:
            return s

        # 得到预处理字符串
        t = "#"
        for i in range(size):
            t += s[i]
            t += "#"
        # 新字符串的长度
        t_len = 2 * size + 1
        # 当前遍历的中心最大扩散步数，其值等于原始字符串的最长回文子串的长度
        max_len = 1
        # 原始字符串的最长回文子串的起始位置，与 max_len 必须同时更新
        start = 0

        for i in range(t_len):
            cur_len = self.__center_spread(t, i)
            if cur_len > max_len:
                max_len = cur_len
                start = (i - max_len) // 2
        return s[start: start + max_len]

    def __center_spread(self, s, center):
        """
        left = right 的时候，此时回文中心是一条线，回文串的长度是奇数
        right = left + 1 的时候，此时回文中心是任意一个字符，回文串的长度是偶数
        """
        size = len(s)
        i = center - 1
        j = center + 1
        step = 0
        while i >= 0 and j < size and s[i] == s[j]:
            i -= 1
            j += 1
            step += 1
        return step
```



```c
// c++语言描述 
string longestPalindrome(string s)
{
    if (s.length() < 1)
    {
        return " ";
    }
    int start = 0, end = 0;
    for(int i = 0; i < s.length(); i++)
    {
        int len1 = expandAroundCenter(s, i, i);// 一个元素为中心
        int len2 = expandAroundCenter(s, i, i+1);// 两个元素为中心
        int len = max(len1, len2);
        if(len > end - start)
        {
            start = i - (len - 1) / 2;
            end = i + len / 2; 
        }
    }
    return s.substr(start, end - start + 1);
}
/* c++中参数是按值传递，如果不使用引用或者指针，则这个地方每一次函数调用，string就会被复制一次，效率很低，使用引用的话函数传递的是string的引用，不会导致复制。
   传参改为 sring &s
*/
int expandAroundCenter(string s, int left, int right)
{
    int L = left, R = right;
    while(L >= 0 && R < s.length() && s[L] == s[R])
    {
        // 计算以left 和 right 为中心的回文串长度
        L --;
        R ++;
    }
    return R - L - 1;
}
```

```python
# python3 语言描述
class Solution:
    def longestPalindrome(self, s: str) -> str:
        size = len(s)
        if size < 2:
            return s

        # 至少是 1
        max_len = 1
        res = s[0]

        for i in range(size):
            palindrome_odd, odd_len = self.__center_spread(s, size, i, i)
            palindrome_even, even_len = self.__center_spread(s, size, i, i + 1)

            # 当前找到的最长回文子串
            cur_max_sub = palindrome_odd if odd_len >= even_len else palindrome_even
            if len(cur_max_sub) > max_len:
                max_len = len(cur_max_sub)
                res = cur_max_sub

        return res

    def __center_spread(self, s, size, left, right):
        """
        left = right 的时候，此时回文中心是一条线，回文串的长度是奇数
        right = left + 1 的时候，此时回文中心是任意一个字符，回文串的长度是偶数
        """
        i = left
        j = right

        while i >= 0 and j < size and s[i] == s[j]:
            i -= 1
            j += 1
        return s[i + 1:j], j - i - 1
```

## 5.Manacher算法



## mathjax引擎

<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js?config=default"></script>  