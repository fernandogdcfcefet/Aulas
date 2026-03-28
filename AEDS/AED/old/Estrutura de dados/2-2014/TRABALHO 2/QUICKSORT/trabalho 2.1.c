#include <stdio.h>
#include <stdlib.h>
#define tam 10

void desenha(int vet[]) //método para desenhar as barras
{
 int i,j;
 printf("\n");
 for(i=0;i<tam;i++) {
            printf("%02d\t",vet[i]);
    for(j=0;j<vet[i];j++)
                printf("%c",220);
    printf("\n");
 }
 printf("\n----------------------------------\n");
}

void particao(int esq, int dir, int *i, int *j,int a[]) //particiona o vetor
{
    int x,w,cont = 1;   /*x = pivô, w = auxiliar para troca*/
    *i = esq;
    *j = dir;
    x = a[(*i + *j)/2]; /*define o pivô como a média dos extremos*/
    printf ("PIVO:\t\t%d\nESQUERDA:\t%d\nDIREITA:\t%d\n\n\n\n", x, a[*i], a[*j]);
    desenha(a);
    getchar();
    do
    {
        while(x > a[*i])
            (*i)++; /*vai para direita*/
        while(x < a[*j])
            (*j)--; /*vai para esquerda*/

        if(*i <= *j)/* esquerda e direita se cruzaram?*/
        {
            printf ("PIVO:\t\t%d\nESQUERDA:\t%d\nDIREITA:\t%d\n\n", x, a[*i], a[*j]);
            printf("\nNA TROCA: %d %c %c %d\n", a[*i],174, 175, a[*j]);
            w = a[*i];      /*faz  a troca de a[*i] por a[*j] */
            a[*i] = a[*j];
            a[*j] = w;
            desenha(a);
            getchar();
            (*i)++;
            (*j)--;
         }
    }while(*i <= *j);
}


void ordena(int esq, int dir, int a[]) //método recursivo para ordenação do vetor
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

void quicksort(int a[],int n)  /* n é o número de elementos do vetor*/
{
        ordena(0,(n-1),a);
}

int main()
{
 int vet[] ={7, 10, 9, 6, 3, 1, 4, 0, 8, 5};
 printf("-----------------------------------------------\n");
 printf("\tM%cTODO DE ORDENA%c%cO QUICKSORT\n", 144,128,199);
 printf("-----------------------------------------------\n\n");
 printf("VETOR ANTES DA ORDENA%c%cO:\n", 128,199);
 desenha(vet);
 getchar();
 system("cls");
 printf("-------------------------------------------\n");
 printf("\t\tEXECU%c%cO", 128,199);
 printf("\n-------------------------------------------\n\n");
 quicksort(vet, tam);
 return 0;
}
