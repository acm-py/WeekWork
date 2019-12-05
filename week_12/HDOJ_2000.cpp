// c解法
#include<stdio.h>
int main(){
	// 这里多出一个d是行数。md 我错了几次才发现必须要有这个d
	char a, b, c, d, x, z, y;
	while(scanf("%c%c%c%c",&a,&b,&c,&d) != EOF)
	{
		// x是三者最小的，z是三者最大的
		x = a>b?b:a;
		x = x>c?c:x;
		z = a>b?a:b;
		z = z>c?z:c;
		y = a+b+c-x-z;
		printf("%c %c %c\n",&x,&y,&z);
	}
	return 0;
}
//C++解法2
#include <iostream>
// 这个库可以调用 swap 函数
#include <algorithm>
using namespace std;

int main(void)
{
	char n[4];

	while (cin >> n)
	{
		if (n[0] > n[1]) swap(n[0], n[1]);
		if (n[1] > n[2]) swap(n[1], n[2]);
		if (n[0] > n[1]) swap(n[0], n[1]);
		cout << n[0] << ' ' << n[1] << ' ' << n[2] << endl;
	}

	return 0;
}

			
