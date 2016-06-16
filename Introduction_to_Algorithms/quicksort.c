#include<stdio.h>

typedef int elem_type;

void Qsort(elem_type *a,int p,int r);
int partition(elem_type *a,int p,int r);

#define ARRLENGTH(name) sizeof(a)/sizeof(a[0])


void Qsort(elem_type *a,int p,int r)
{
	if(p<r){
		int q=partition(a,p,r);
		Qsort(a,p,q-1);
		Qsort(a,q+1,r);
	}
}

int partition(elem_type *a,int p,int r)
{
	int i=p-1;                  //中心数位置标记
	int x=a[r];                 //基准数标记
	int j;
	int sign=0;                
	int temp;
	for(j=p;j<=r-1;j++)
	{
		if(a[j]<x)          
		{
			i++;
			temp=a[j];
			a[j]=a[i];
			a[i]=temp;
			sign=0;
		}
		else 
		{
			sign=1;
		}

	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;
	return i+1;
}
