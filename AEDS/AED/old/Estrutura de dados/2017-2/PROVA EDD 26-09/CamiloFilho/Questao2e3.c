#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  5

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
  int tamanho;
} TipoFila;

void FFVazia(TipoFila *Fila)
{
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;
    Fila->tamanho = 0;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{
    if (Fila->tamanho == MAXTAM)
        printf(" Erro: fila esta cheia\n");
    else {
        Fila->Item[Fila->Tras - 1] = x;
        Fila->Tras = Fila->Tras % MAXTAM + 1;
        Fila->tamanho++;
        }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{
    if (Vazia(*Fila))
        printf("Erro fila esta vazia\n");
    else {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente % MAXTAM + 1;
        Fila->tamanho--;
        }
}

void Imprime(TipoFila *Fila){      //deu certo
    int i;
    if(Fila->tamanho == 0){
        printf("Fila Vazia\n");
    }
    else{
        if(Fila->Frente < Fila->Tras){
            for(i = Fila->Frente-1; i < Fila->Tras-1; i++){
                printf("%d ", Fila->Item[i].Chave);
            }
        }
        else{
            for(i = Fila->Tras-1; i < MAXTAM; i++){
                printf("%d ", Fila->Item[i].Chave);
            }
            for(i = 0; i < Fila->Frente-1; i++){
                printf("%d ", Fila->Item[i].Chave);
            }
        }
    }
}

//Pilha Primeiro que entra eh o ultimo que sai (Questao 3)
/*void Empilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){
    int i=0, vet[Fila1->tamanho], c = 0;
    for(i=Fila->Frente-1; i<Fila1->Fila->Tras-1, c++, i++){
        vet[c] = Fila1->Item[i].Chave;
    }
    i=0;
    while(c>=0){
        Fila2->Item[i].Chave = vet[c];
        c--;
    }
}
void Desempilha(TipoItem x, TipoFila *Fila1, TipoFila *Fila2){


}
*/

int main(int argc, char *argv[])
{
    TipoFila MF;
    FFVazia(&MF);
    TipoItem obj;

    obj.Chave = 5;
    Enfileira(obj,&MF);
    obj.Chave = 2;
    Enfileira(obj,&MF);
    obj.Chave = 3;
    Enfileira(obj,&MF);
    obj.Chave = 4;
    Enfileira(obj,&MF);

    /*Desenfileira(&MF,&obj);
    Desenfileira(&MF,&obj);
    Desenfileira(&MF,&obj);
    Desenfileira(&MF,&obj);

    Enfileira(obj,&MF);
    obj.Chave = 5;
    Enfileira(obj,&MF);
    obj.Chave = 5;
    Enfileira(obj,&MF);
    obj.Chave = 5;
    Enfileira(obj,&MF);*/

    Imprime(&MF);
    return 0;
}
