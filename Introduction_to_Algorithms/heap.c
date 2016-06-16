#include<stdio.h>
#include<malloc.h>

#define ARR_LEN(NAME) sizeof(NAME)/sizeof(NAME[0])

typedef struct heap{
	int *data;
	int size;
}Heap;


void MAX_HEAPIFY(Heap *a,int id);
void build_heap(Heap *h);
void heap_sort(int *a,int len);

int main()
{

}



void MAX_HEAPIFY(Heap *h,int id)///     从数组下标从0开始
{
	int largest=id;
	int left=(id+1)*2-1;
	int right=(id+1)*2;
	int temp;
	if((h->size>left)&&(h->data[largest]<h->data[left]))
	{
		largest=left;
	}
	if((h->size>right)&&h->data[largest]<h->data[right])
	{
	
		largest=right;
	}
	if(largest!=id)
	{
		temp=h->data[largest];
		h->data[largest]=h->data[id];
		h->data[id]=temp;
		MAX_HEAPIFY(h,largest);
	}
}

void build_heap(Heap *h)
{
	int i;
	int len=h->size;
	for(i=(len-1)/2;i>=0;i--)
		MAX_HEAPIFY(h,i);
}

void heap_sort(int *a,int len)
{
	int i,temp;
	Heap *h=(Heap *)malloc(sizeof(Heap));
	h->data=a;
	h->size=len;
	build_heap(h);
	for(i=(len-1);i>=1;i--)
	{
		temp=h->data[0];
		h->data[0]=h->data[i];
		h->data[i]=temp;
		h->size--;
		MAX_HEAPIFY(h,0);
	}
	free(h);
}
