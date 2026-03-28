#include <stdio.h>
#include <stdlib.h>

typedef  char  TipoChave;
typedef  struct  {
    int  Chave;
/*  outros  componentes  */
}  TipoItem;

typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    char letra;
    TipoApontador  Prox;
}  TipoCelula;
typedef  struct  {
    TipoApontador  Fundo,  Topo;
    int  Tamanho;
}  TipoPilha ;

void  FPVazia( TipoPilha  *Pilha)
{
    Pilha->Topo =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Fundo =  Pilha->Topo;
    Pilha->Topo->Prox  = NULL;
    Pilha->Tamanho =  0;
}
int  Vazia( TipoPilha  Pilha)
{
    return  ( Pilha .Topo == Pilha .Fundo) ;
}

void  Empilha(TipoItem  x ,	TipoPilha  *Pilha)
{
    TipoApontador  Aux;
    Aux =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Topo->Item  =  x;
    Aux->Prox  =  Pilha->Topo;
    Pilha->Topo = Aux; Pilha->Tamanho++;
}

void  Desempilha( TipoPilha  *Pilha ,  TipoItem  *Item)
{
    TipoApontador  q;
    if	( Vazia(*Pilha ) )  {
            printf ( "Erro :lista vazia\n");
            return ;
    }
    q =  Pilha->Topo;
    Pilha->Topo =  q->Prox ;
    *Item  =  q->Prox->Item ;
    free (q) ;
    Pilha->Tamanho--;
}

int  Tamanho( TipoPilha  Pilha)
{
    return  ( Pilha .Tamanho) ;
}

void  Imprime( TipoPilha  Lista )
{
    TipoApontador  Aux;
    Aux =  Lista.Topo->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%c\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}

int palindromo(TipoPilha pilha){
    TipoPilha PilhaAux1, PilhaAux2;
    TipoItem a1, a2;
    int x=0;

    FPVazia(&PilhaAux1);
    FPVazia(&PilhaAux2);

    PilhaAux1 = pilha;

    while(!Vazia(PilhaAux1)){
        Desempilha(&PilhaAux1, &a1);
        Empilha(a1, &PilhaAux2);
    }

    while(!Vazia(PilhaAux1)){
        Desempilha(&PilhaAux1, &a1);
        Desempilha(&pilha, &a2);

        if (a1.Chave == a2.Chave){
            x=1;
        }else{
            x=0;
        }
    }
    return x;
}

int main()
{
    TipoPilha pilha;
    FPVazia(&pilha);
    char palavra[10]="arara";
    int i;
    TipoItem item;
    for (i=0; i<5; i++){
        item.Chave=palavra[i];
        Empilha(item, &pilha);
    }
    //Imprime(pilha);
    printf ("%d", palindromo(pilha));
    return 0;
}
