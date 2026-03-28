#include <stdio.h>
#include <stdlib.h>
#define TAM 10
void imprime(int vet[]){
    int i;
    printf("[");
    for(i=0;i<TAM;i++)
        printf("%d ",vet[i]);
    printf("]\n");
}

void troca(int *A,int *B){
    int aux=*A;
    *A=*B;
    *B=aux;
}

void bubbleSort(int vet[]){
    int i,j;
    for(i=0;i<TAM;i++){
        for(j=0;j<TAM-1;j++){
            if(vet[j]>vet[j+1]){
                troca(&vet[j],&vet[j+1]);
                imprime(vet);
                _sleep(500);
            }
        }
    }
}

int pesquisaSequencial(int vet[],int chave){
    int i;
    for(i=0;i<TAM;i++){
        if(vet[i]==chave){
            return i;
        }
    }
    return -1;
}

int pesquisa(int vet[],int chave,int esq,int dir){
    int pivo = (dir+esq)/2;
    if(chave==vet[pivo]){
        return pivo;
    }else if((dir==esq)||(dir<esq)){
        return -1;
    }else if(chave>vet[pivo]){
        return pesquisa(vet,chave,pivo+1,dir);
    }else if(chave<vet[pivo]){
        return pesquisa(vet,chave,esq,pivo-1);
    }
}

int main()
{
//    int vet[]={3,5,7,1,2,0,9,4,8,6};
    int vet1[]={0,10,20,30,40,50,60,70,80,90};
//    int vet2[]={9,8,7,6,5,4,3,2,1,0};
    printf("O elemento %d esta na posicao %d do vetor\n",70,pesquisa(vet1,70,0,9));
    return 0;
}
