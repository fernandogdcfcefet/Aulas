#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#define MAXTAM 1000

typedef int TipoApontador;
typedef int TipoChave;

typedef struct{
    TipoChave Chave;
}TipoItem;


typedef struct{
    TipoItem Item[MAXTAM];
    TipoApontador Frente, Tras;
}TipoFila;

void FFVazia(TipoFila *Fila){
    Fila->Frente = 1;
    Fila->Tras = Fila->Frente;

}

int Vazia(TipoFila Fila){
    return (Fila.Frente == Fila.Tras);
}

void Enfileira(TipoItem x, TipoFila *Fila){
    if(Fila->Tras%MAXTAM + 1 == Fila->Frente)
        printf("Erro: Fila esta cheia");
    else{
        Fila->Item[Fila->Tras-1] = x;
        Fila->Tras = Fila->Tras%MAXTAM + 1;
    }
}


void Desenfileira(TipoFila *Fila, TipoItem *Item){
    if(Vazia(*Fila))
        printf("Erro: Fila esta vazia");
    else{
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = Fila->Frente%MAXTAM+1;
    }
}

void ImprimeFila(TipoFila Fila){
    int i;

    for(i=Fila.Frente-1;i!=Fila.Tras-1; i=(i+1)%MAXTAM){
        printf("%d ", Fila.Item[i].Chave);
    }
}

int main(){
    TipoFila MF;
    TipoItem x, y, z, w, k;

    FFVazia(&MF);
    x.Chave = 1;
    y.Chave = 2;
    z.Chave = 3;
    w.Chave = 4;
    k.Chave = 5;

    Enfileira(x, &MF);
    Enfileira(y, &MF);
    Enfileira(z, &MF);
    Enfileira(w, &MF);
    Enfileira(k, &MF);

    ImprimeFila(MF);

    getch();
    return 0;
}
