/*若num<9,直接返回num
若num>9
假设一个三位数整数n=100*a+10*b+c,变化后new=a+b+c；
两者的差值n-new=99a+9b，差值可以被9整除，说明每次缩小9的倍数
那么我们可以对res=num%9，若不为0则返回res，为0则返回9
*/
int addDigits(int num)
{
    return (num - 1) % 9 + 1;
}
