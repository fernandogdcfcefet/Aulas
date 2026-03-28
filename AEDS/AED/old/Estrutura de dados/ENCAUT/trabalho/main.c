#include <stdio.h>
#include <stdlib.h>
#define tam 10
void imprime(int vet[],int j, int k){
    int i;
    system("color 00");
    for(i=0;i<tam;i++){
        if(i==j)system("color 02");else system("color 00");
        if(i==k)system("color 01");else system("color 00");
        printf("%d ",vet[i]);
    }
    printf("\n");
}

void troca(int *a, int *b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bubbleSort(int vet[]){
    int i,j;
    for(i=0;i<tam;i++){
        for(j=i;j<tam;j++){
            if(vet[i]>vet[j]){
                imprime(vet,i,j);
                troca(&vet[i],&vet[j]);
            }
        }
    }
}

int main()
{
    int vet[tam]={3,7,5,9,0,1,2,6,8,4};
//    int vet[tam]={0,1,2,3,4,5,6,7,8,9};
//    int vet[tam]={9,8,7,6,5,4,3,2,1,0};
//    imprime(vet);
    bubbleSort(vet);
//    imprime(vet);
    return 0;
}
