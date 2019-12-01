# 有效的括号

给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。

有效字符串需满足：  
  1、 左括号必须用相同类型的右括号闭合。  
  2、 左括号必须以正确的顺序闭合。  
注意空字符串可被认为是有效字符串。

## 示例如下：

```chameleon
输入: "()"
输出: true
输入: "()[]{}"
输出: true
输入: "(]"
输出: false
输入: "([)]"
输出: false
输入: "{[]}"
输出: true
```

>解题思路：
用栈的方式处理数据。

代码如下：
``` c
bool isValid(char* s) 
{
    //函数声明
    bool isLeft(char);
    bool relative(char,char);

    //用栈来装字符
    int len = strlen(s);
    char *stack = (char *)malloc(sizeof(char) * (len+1));
    memset(stack,'\0',len+1);//初始化栈
    char *top = stack;
    char *p = s;
    while(*p)
    {
        if(isLeft(*p))
        {
            *++top = *p;//如果是左括号，括号进栈，
        }else
        {
            if(!relative(*top,*p))
                return false;//如果是右括号但不相对应，则return false;
            else
                *top-- = '\0';//如果是右括号且相对应，则退栈
        }
        p++;//指针+1
    }
    free(stack);
    if(stack == top)
        return true;
    return false;
}

bool isLeft(char a)
{
    if(a == '{' || a == '[' || a== '(')
        return true;
    return false;
}

bool relative(char a,char b){
    if(a=='{' && b=='}')
        return true;
    if(a=='[' && b==']')
        return true;
    if(a=='(' && b==')')
        return true;
    return false;
}
```