#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

#define n 3

int norma(int m[n][n])
{
	int  soma[n]={0},i,j, norma=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(m[i][j]<0) soma[i]+=m[i][j]*(-1);
			else soma[i]+=m[i][j];
		}
	}
	for(i=0;i<n;i++)
	{
		if(soma[i]>norma) norma=soma[i];
	}
	return norma;
}
int main()
{
	int m[n][n],i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("a%d%d ",i+1,j+1);
			scanf("%d",&m[i][j]);
		}
	}
	printf("Norma: %d", norma(m));
	
	getch();
	return 0;
}
