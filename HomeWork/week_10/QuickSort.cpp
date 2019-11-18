#include<cstdio>
#include<iostream>
using namespace std;

//¿ìËÙÅÅĞò 
void QuickSort(int a[],int,int);
int partition(int a[],int,int);
void exchange(int &a,int &b);
void p_array(int a[],int len); 
int main()
{

   int arr[]={1,4,5,9,2,5,3,8,6,7};
   QuickSort(arr,0,sizeof(arr)/sizeof(arr[0])-1);
   p_array(arr,sizeof(arr)/sizeof(arr[0]));
   return 0;
}
void p_array(int a[],int len)
{
	for(int i=0;i<len;i++)
	  printf("%d ",a[i]);
	printf("\n");
}
void QuickSort(int a[],int p,int r)
{
	 if(p<r)
	 {
	 	int q=partition(a,p,r);
	 	QuickSort(a,p,q-1);
	 	QuickSort(a,q+1,r);
	 }
}
int partition(int a[],int p,int r)
{
	int x=a[r];
	int i=p-1;
	for(int j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			exchange(a[i],a[j]);
		}
	}
	exchange(a[i+1],a[r]);
	return i+1;
}
void exchange(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
