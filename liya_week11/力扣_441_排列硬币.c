//等差数列求和公式为x=na1+(n(n-1)/2)*d    
//等差为d=1,首项为a1=1,项数为n
//则可得n=sqrt(2x+1/4)-1/2
int arrangeCoins(int x)
{
return (sqrt(2) * sqrt(x + 0.125) - 0.5);
}
/*
x为常数，解一元二次方程得
2x=n*n+n
n*n+n-2x=0
n=sqrt(2n+1/4)-1/2
*/
//数学对于编程还是有点用的 
