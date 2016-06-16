/************************************************
          算法导论 中文版p40
************************************************/
#include<stdio.h>
#include<malloc.h>
typedef int data_type;


#define MIN (-2147483647 - 1)
int* find_max_side(data_type a[],int low,int high);     //用分治的方法寻找最大数组



int* find_max_crossing(data_type a[],int low,int middle,int high)
{
	int left_max=middle,          ///从middle开始
		right_max=middle,
		i,j;
	data_type left_sum_max=MIN,
		      right_sum_max=MIN,
			  sum_max,
	          sum=0;                          
	int *p=(int *)malloc(sizeof(int)*3);
           
	
	sum=0;
	for(i=middle;i>=low;i--)
	{
		sum+=a[i];
		if(sum>=left_sum_max)
		{
			left_sum_max=sum;
			left_max=i;
		}
	}
	sum=0;
	for(j=middle+1;j<=high;j++)
	{
		sum+=a[j];
		if(sum>=right_sum_max)
		{
			right_sum_max=sum;
			right_max=j;
		}
	}
	sum_max=left_sum_max+right_sum_max;
	p[0]=left_max;
	p[1]=right_max;
	p[2]=sum_max;  
	return p;
}

int *find_max_side(data_type a[],int low,int high)
{
	int *p=(int *)malloc(sizeof(int )*3);
	int middle;
	//p[0]=(int *)&left_max;
	//p[1]=(int *)&right_max;
	//p[2]=(int *)&sum_max;   
	if(high==low)
	{
		p[0]=low;
		p[1]=high;
		p[2]=a[low];   
		return p;
	}
	else
	{
		int *getp,left_low,left_high,right_low,right_high,cross_low,cross_high;
		data_type  left_sum,right_sum,cross_sum;
		middle=(low+high)/2;
		getp=find_max_side(a,low,middle);
		left_low=getp[0];
		left_high=getp[1];
		left_sum=getp[2];  
		
		free(getp);

		getp=find_max_side(a,middle+1,high);
		right_low=getp[0];
		right_high=getp[1];
		right_sum=getp[2];
		free(getp);

		getp=find_max_crossing(a,low,middle,high);
		cross_low=getp[0];
		cross_high=getp[1];
		cross_sum=getp[2];
		free(getp);
		if(left_sum>=right_sum&&left_sum>=cross_sum)
		{
			p[0]=left_low;
			p[1]=left_high;
			p[2]=left_sum;   
			return p;
		}
		else if(right_sum>=left_sum&&right_sum>=cross_sum)
		{
			p[0]=right_low;
			p[1]=right_high;
			p[2]=right_sum;   
			return p;
		}
		else
		{
			p[0]=cross_low;
			p[1]=cross_high;
			p[2]=cross_sum;   
			return p;
		}
	}

}