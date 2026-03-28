#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void desenha(char a[], int n)
{
 int i;
 printf("\n");
 for(i=0;i<n;i++) {
            printf("%c\t",a[i]);
 }
}

void particao(int esq, int dir, int *i, int *j,char a[])
{
    int x, y,w;   /*x = pivô, w = auxiliar para troca*/
    *i = esq;
    *j = dir;
    x = a[(*i + *j)/2]; /*define o pivô como a média dos extremos*/
    if (esq==0)
    {
        printf("\n");
        for(y=esq; (y<=dir); y++)
        printf("%c\t",a[y]);
    }
    if (esq==1)
    {
        printf("\n\t");
        for(y=esq; (y<=dir); y++)
        printf("%c\t",a[y]);
    }
    if (esq==2)
    {
        printf("\n\t\t");
        for(y=esq; (y<=dir); y++)
        printf("%c\t",a[y]);
    }
    if (esq==3)
    {
        printf("\n\t\t\t");
        for(y=esq; (y<=dir); y++)
        printf("%c\t",a[y]);
    }
    if (esq==4)
    {
        printf("\n\t\t\t\t");
        for(y=esq; (y<=dir); y++)
        printf("%c\t",a[y]);
    }
    if (esq==5)
    {
        printf("\n\t\t\t\t\t");
        for(y=esq; (y<=dir); y++)
        printf("%c\t",a[y]);
    }
    if (esq==6)
    {
        printf("\n\t\t\t\t\t\t");
        for(y=esq; (y<=dir); y++)
        printf("%c\t",a[y]);
    }
    getchar();
    do
    {
        while(x > a[*i])
            (*i)++; /*vai para direita*/
        while(x < a[*j])
            (*j)--; /*vai para esquerda*/

        if(*i <= *j)/* esquerda e direita se cruzaram?*/
        {
            w = a[*i];      /*faz  a troca de a[*i] por a[*j] */
            a[*i] = a[*j];
            a[*j] = w;
            (*i)++;
            (*j)--;
         }
    }while(*i <= *j);
}


void ordena(int esq, int dir, char a[]) //método recursivo para ordenação do vetor
{
    int i,j;
    particao(esq,dir,&i,&j,a);
    if(esq < j)
    {
            ordena(esq,j,a);
    }
    if(i < dir)
    {
            ordena(i,dir,a);
    }
}

void quicksort(char a[],int n)  /* n é o número de elementos do vetor*/
{
        ordena(0,(n-1),a);
}

int main()
{
 char vet[6] ={'O', 'R', 'D', 'E', 'N', 'A'};
 printf("-----------------------------------------------\n");
 printf("\tM%cTODO DE ORDENA%c%cO QUICKSORT\n", 144,128,199);
 printf("-----------------------------------------------\n\n");
 printf("\t        --------\n");
 printf("\t        EXECU%c%cO", 128,199);
 printf("\n\t        --------\n\n");
 quicksort(vet, 6);
 desenha(vet, 6);
 return 0;
}
