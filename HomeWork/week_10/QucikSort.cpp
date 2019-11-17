#include<cstdio>
#include<iostream>
using namespace std;

//¿ìËÙÅÅĞò 
void quickSort(int a[],int,int);
int partition(int a[],int,int);
int main()
{

}
void QuickSort(int a[],int p,int r)
{
	 if(p<r)
	 {
	 	q=partition(a,p,r);
	 	QuickSort(A,p,q-1);
	 	QuickSort(A,q+1,r);
	 }
}
int partition(int a[],int,int)
{
	
}
