#include<stdio.h>

void chess(int a[][8],int i);
void change_sign(int sign[][8],int thisi,int count);
void reset_sign(int sign[][8]);
int queen[8][2]={{0}};
static int num=0;

void chess(int sign[][8],int i)   //八皇后问题       自己捣鼓的  有点笨
{
	int thisi=i;
	int count ;

	int k;
	for(count=0;count<8;count++)
	{
		if(sign[thisi][count]==1)
		{
			queen[thisi][0]=thisi;
			queen[thisi][1]=count;
			change_sign(sign,thisi,count);

			if(i==7)
			{
				for(k=0;k<8;k++)
					printf("%d %d\n",queen[k][0],queen[k][1]);
				printf("\n\n");
				num++;
			}
			if(i<7)
			chess(sign,i+1);

		}
	}
	if(count==8)   //回溯
	{
		int m;
		reset_sign(sign);       
		for(m=0;m<=thisi-2;m++)   
			change_sign(sign,queen[m][0],queen[m][1]);
	}




}

void reset_sign(int sign[][8])
{
	int i,j;
	for(i=0;i<8;i++)
		for(j=0;j<8;j++)
			sign[i][j]=1;
}

void change_sign(int sign[][8],int thisi,int count)
{
	int k;
	int line;
	int row;
	for(k=0;k<8;k++)
	{
		if(k!=count)
			sign[thisi][k]=0;       //横
		if(k!=thisi)
			sign[k][count]=0;        //纵
	}
	for(line=thisi,row=count;line<=7,row>=0;line++,row--)
	{
		if(line!=thisi&&row!=count)
			sign[line][row]=0;        //斜率为1
	}
	for(line=thisi,row=count;line<=7,row<=7;line++,row++)
	{
		if(line!=thisi&&row!=count)
			sign[line][row]=0;       //斜率为-1
	}
}