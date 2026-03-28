#include<stdio.h>
#define TAM 2

typedef struct{
    int dia, mes, ano;
}data;
typedef struct{
    data d;
    char descricao[60];
}compromisso;

void leitura(compromisso n[])
{
    for(int i=0;i<TAM;i++)
    {
        printf("Descricao:");
        scanf("%s",&n[i].descricao);
        printf("Dia:");
        scanf("%d", &n[i].d.dia);
        printf("Mes:");
        scanf("%d", &n[i].d.mes);
        printf("Ano:");
        scanf("%d", &n[i].d.ano);
    }
}

/*compromisso proximoCompromisso(data d, compromisso n[])
{
    int data1[TAM],data2, data3;
    for(int i=0;i<TAM;i++)
    {
        data1[i]= n[i].d.dia+(30*(n[i].d.mes-1))+(360*(n[i].d.ano-1));
    }
        data2=d.dia+(30*(d.mes-1))+(360*(d.ano-1));
    for(int j=0;j<TAM;j++)
    {
        if(data1[j]>data2[j])
        {
        }
    }
}
*/

int main()
{
   compromisso n[TAM];
   data d;
   leitura(n);

   printf("Digite a data do compromisso:\n");
   printf("Dia:");
   scanf("%d", &d.dia);
   printf("Mes:");
   scanf("%d", &d.mes);
   printf("Ano:");
   scanf("%d", &d.ano);
   //proximoCompromisso(d, n, );

}
