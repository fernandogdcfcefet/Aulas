#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#define TAM 6
void troca(int *a,int*b){
    int aux=*a;
    *a=*b;
    *b=aux;
}
void bubbleSort(int vet[]){
int i,j;
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM;j++){
            if(vet[i]<vet[j]){
                troca(&vet[i],&vet[j]);
            }
        }
    }
}
//devolve a posicao do maior elemento do vetor
int achaMaior(int vet[], int tamanho){
    int i, resultado = 0;
    for(i=1;i<tamanho;i++){
        if(vet[i]>vet[resultado]){
            resultado=i;
        }
    }
    return resultado;
}

void selectionSor(int vet[]){
    int i,aux;
    for(i=TAM;i>0;i--){
        aux = achaMaior(vet,i);
        troca(&vet[aux],&vet[i-1]);
    }
}

void imprime(int vet[]){
    int i;
    for(i=0;i<TAM;i++){
        printf("%d ",vet[i]);
    }
}
int main()
{
    int vet[TAM]={3,1,5,9,2,4};
    selectionSor(vet);
    imprime(vet);

    return 0;
}
