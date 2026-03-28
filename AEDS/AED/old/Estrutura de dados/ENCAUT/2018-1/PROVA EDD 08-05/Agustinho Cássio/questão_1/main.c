#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define MAXTAM 1000

typedef int tipo_apontador;

typedef struct
{
    int x;
    int y;
}tipo_ponto;

typedef struct
{
    tipo_ponto ponto[MAXTAM];
    int lados;
    tipo_apontador primeiro, ultimo;
} tipo_poligono;

void construtor (tipo_poligono *pol)
{
    pol->primeiro=0;
    pol->primeiro=pol->ultimo;
    pol->lados=-1;
}

void add_aresta (tipo_poligono *pol, tipo_ponto ponto)
{
    if (pol->lados>=MAXTAM-2)
    {
        printf("\n\a Erro: não é possível adicionar mais arestas");
        return ;
    }
    else
        {
            if(pol->ponto[pol->ultimo-1].x==ponto.x && pol->ponto[pol->ultimo-1].y==ponto.y)
            {
                printf("\n\a Erro: não é possível inserir esta aresta");

            }   else
                {
                    pol->ponto[pol->ultimo].x=ponto.x;
                    pol->ponto[pol->ultimo].y=ponto.y;
                    pol->ultimo++;
                    pol->lados++;
                }
        }
}

void retira_aresta (tipo_poligono *pol)
{
    if (pol->lados==-1)
    {
        printf("\n\a Erro: não é possível retirar esta aresta");
        return ;
    }
    else
    {
        pol->ultimo--;
        pol->lados--;
    }
}


void imprima(tipo_poligono pol)
{
    if (pol.lados<1)
    {
        printf("\n\a Erro: não é possível imprimir um polígono sem lados");
        return ;
    }
    else
    {
        for(tipo_apontador i=0; i<pol.ultimo; i++)
        {
            printf("\n (%d , %d)", pol.ponto[i].x, pol.ponto[i].y);
        }
    }
}

int main()
{

    setlocale(LC_ALL,"");
    getch();
    return 0;
}
