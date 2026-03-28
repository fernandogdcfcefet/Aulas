#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAXTAM  1000

typedef int TipoApontador;

typedef int TipoChave;
typedef struct {
  TipoChave Chave;
  /* outros componentes */
} TipoItem;
typedef struct {
  TipoItem Item[MAXTAM];
  TipoApontador Frente, Tras;
} TipoFila;

void FFVazia(TipoFila *Fila)
{ Fila->Frente = 1;
  Fila->Tras = Fila->Frente;
}

int Vazia(TipoFila Fila)
{ return (Fila.Frente == Fila.Tras); }

void Enfileira(TipoItem x, TipoFila *Fila)
{ if (Fila->Tras % MAXTAM + 1 == Fila->Frente)
  printf(" Erro   fila est  a  cheia\n");
  else { Fila->Item[Fila->Tras - 1] = x;
         Fila->Tras = Fila->Tras % MAXTAM + 1;
       }
}

void Desenfileira(TipoFila *Fila, TipoItem *Item)
{ if (Vazia(*Fila))
  printf("Erro fila esta vazia\n");
  else { *Item = Fila->Item[Fila->Frente - 1];
         Fila->Frente = Fila->Frente % MAXTAM + 1;
       }
}
//Procedimento para excluir numero negativos.
void excluiNegativo(TipoFila *Fila){
    TipoApontador n;
    n = Fila->Frente;
    while(n != Fila->Tras){
        if(Fila->Item[n - 1].Chave< 0){
          //Para excluir numero negativo: todas as vezes que um numero menor que zero for encontrado colocar zero na sua posição assim não mudo a posição dos demais
            Fila->Item[n - 1].Chave = 0;
        }
        n++;
    }
}
int main()
{
    //PARA TESTES
    /*TipoFila fila;
    TipoItem item;
    FFVazia(&fila);
    int i;
    for(i = 0; i < 3; i++){
        printf("Informe : " );
        scanf("%d", &item.Chave);
        Enfileira(item, &fila);
   }*/
    excluiNegativo(&fila);

}
