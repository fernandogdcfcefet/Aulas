#include <stdio.h>
#include <stdlib.h>

//PROGRAMA FEITO PARA TESTAR A PALAVRA ARARA


typedef  int  TipoChave;

typedef  struct  {

    //int  Chave;
    char letra;



}Item;

typedef  struct  Celula  *Apontador;

typedef  struct Celula  {

    Item  Item;
    Apontador  Prox;

}Celula;

typedef  struct  {

    Apontador  Fundo,  Topo;
    int  Tamanho;

} Pilha ;

void  FPVazia( Pilha  *Pilha)
{
    Pilha->Topo =  (Apontador)  malloc( sizeof ( Celula ) ) ;
    Pilha->Fundo =  Pilha->Topo;
    Pilha->Topo->Prox  = NULL;
    Pilha->Tamanho =  0;
}

int  Vazia( Pilha  Pilha)
{
    return  ( Pilha .Topo == Pilha .Fundo) ;
}

void  Empilha(Item  x ,	Pilha  *Pilha)
{
    Apontador  Aux;
    Aux =  (Apontador)  malloc( sizeof ( Celula ) ) ;
    Pilha->Topo->Item  =  x;
    Aux->Prox  =  Pilha->Topo;
    Pilha->Topo = Aux; Pilha->Tamanho++;
}

void  Desempilha( Pilha  *Pilha , Item  *Item)
{
    Apontador  q;

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

int  Tamanho( Pilha  Pilha)
{
    return  ( Pilha .Tamanho) ;
}

void  Imprime( Pilha  Pilha )
{
    Apontador  Aux;
    Aux =  Pilha.Topo->Prox ;

    while  (Aux  !=  NULL){

        printf ( "%c\n" ,  Aux->Item.letra) ;

        Aux = Aux->Prox ;

    }
}

void palindromo(Pilha *Pilha1 , Pilha *Pilha2){

Apontador posicao;
posicao = Pilha1.Topo->Prox;

while(posicao != NULL){

    Desempilha(&Pilha1, &Item);
    Empilha(Item , &Pilha2);
    posicao = posicao->prox;

}

Apontador confere1;
Apontador confere2;
confere1 = Pilha1.Topo.Item.letra;
confere2 = Pilha2.Topo.Item.letra;

while(confere1->prox != NULL){

    if(confere1 == confere2){

    printf("e um palindromo");

    confere1 = confere1->prox;
    confere2 = confere2->prox;
    }

}

}

int main()
{

Pilha Pilha1,Pilha2;

FPVazia(&Pilha1);
Vazia(Pilha1);

FPVazia(&Pilha2);
Vazia(Pilha2);

Pilha Pilha1 = {"arara"};


    return 0;
}
