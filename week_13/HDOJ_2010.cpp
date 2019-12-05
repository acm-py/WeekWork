#include <cstdio>

int main ()
{
	int m,n,a,b,c,i,j;
  while (scanf("%d%d",&m,&n)!=EOF)
  {
		j=0;
		for(i=m;i<=n;i++)
		{
			a=i/100;
			b=(i/10)%10;
			c=i%10;
		
			if(i==a*a*a+b*b*b+c*c*c)
			{
				if(j==1)
					printf(" ");
				printf("%d",i);
				j=1;
			}
		} 
		if(j==0)
			printf("no\n");
    else
 	 		printf("\n");
 }

	return 0;
}