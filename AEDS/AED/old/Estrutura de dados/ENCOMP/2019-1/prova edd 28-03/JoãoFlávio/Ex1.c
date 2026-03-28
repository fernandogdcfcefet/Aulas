#include<stdio.h>
#define TAM 1
typedef struct
{
	int dia, mes, ano;
	
}Data;
typedef struct
{
	char descricao[60];
	Data data;
}Compromisso;
void ImprimeData(Data d)
{
	printf("%d/%d/%d",d.dia,d.mes,d.ano);
}
void ImprimeCompromisso(Compromisso c)
{
	puts(c.descricao);
	ImprimeData(c.data);
}
void leVetor(Compromisso c[])
{
	int i;
	for(i=0;i<TAM;i++)
	{
		gets(c[i].descricao);
		scanf("%d",&c[i].data.dia);
		scanf("%d",&c[i].data.mes);
		scanf("%d",&c[i].data.ano);
	}
}
void ProximosCompromissos(Data d,Compromisso c[])
{
	int d1,d2;
	d1=(d.ano*360)+(d.mes*30)+(d.dia);
	int i;
	for(i=0;i<TAM;i++)
	{
		d2=(c[i].data.ano*360)+(c[i].data.mes*30)+(c[i].data.dia);
		if(d1 <= d2)
		ImprimeCompromisso(c[i]);
	}
}
int main()
{
	Compromisso compromisso[TAM];
	Data d;
	leVetor(compromisso);
	printf("digite uma data para ver proximos compromissos:\n");
	printf("dia:\n");
	scanf("%d",&d.dia);
	printf("mes:\n");
	scanf("%d",&d.mes);
	printf("ano:\n");
	scanf("%d",&d.ano);
	
	ProximosCompromissos(d, compromisso);
	return 0;
}
