#include <stdio.h>
#include <stdlib.h>

typedef  int  Chave;

typedef  struct  {

    Chave Chave;

}Item;

typedef  struct  Celula  *Apontador;

typedef  struct  Celula  {

    Item  Item;
    Apontador  Prox;

}Celula;

typedef  struct  {

    Apontador  Primeiro ,  Ultimo;

}Lista ;

void  FLVazia( Lista *Lista )
{
    Lista->Primeiro  =  (Apontador)  malloc( sizeof ( Celula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( Lista  Lista )
{
    return  ( Lista . Primeiro ==  Lista . Ultimo ) ;
}

void  Insere(Item  x , Lista  * Lista )
{
    Lista->Ultimo->Prox  =  (Apontador)  malloc( sizeof ( Celula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}
void  Retira(Apontador  p, Lista  *Lista ,  Item  *Item)
{
    Apontador  q;

    if	( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){

        printf ( "  Erro :	Lista  vazia  ou  posicao  nao  existe \n" ) ;

        return ;
    }
    q =  p->Prox;  *
    Item  =  q->Item ;
    p->Prox  =  q->Prox ;

    if	( p->Prox == NULL )

        Lista->Ultimo  = p;

    free (q);
}
void  Imprime( Lista  Lista )
{
    Apontador  Aux;
    Aux =  Lista . Primeiro->Prox ;

    while  (Aux  !=  NULL){

        printf ( "%d\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;

    }

}

void Retiratodos(Lista *Lista , Item Item){

    Apontador aux = *Item;
    Apontador procurado;
    procurado = Lista->Primeiro->prox;
    Apontador A = procurado;

    while(procurado != NULL){

        if(procurado == aux){

            Retira(A , &Lista , &Item);

        }
        procurado = procurado->prox;
    }

}

void Insereordenado(Item x , Lista *Lista){

Apontador aux;
aux = *x;
int i;
for(i =  ; i < ){



}



}

int main()
{
    Lista Lista1;
    FLVazia(&Lista1);
    Vazia(Lista1);

    Lista1 L1 = {1};
    Lista1 L2 = {2};
    Lista1 L3 = {3};
    Lista1 L4 = {1};

    Insere(L1, &Lista1);
    Insere(L2, &Lista1);
    Insere(L3, &Lista1);

    Imprime(Lista1);


    return 0;
}
