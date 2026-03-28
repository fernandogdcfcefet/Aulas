#include <stdio.h>
#include <stdlib.h>
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoItem;

typedef  struct  TipoCelula  *TipoApontador;

typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
    int Tamanho; // Tamanho da Lista
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->Tamanho = 0;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    Lista->Tamanho++;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
}
    q =  p->Prox;  *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
    Lista->Tamanho--;
}

void ListasIguais(TipoLista *L1, TipoLista *L2){
    TipoApontador A1, A2;
    int Errado = 0;

    if(L1->Tamanho != L2->Tamanho){
        printf("Listas Diferentes!!!!");
        return;
    }

    A1 = L1->Primeiro->Prox;
    A2 = L2->Primeiro->Prox;

    while(A1 != NULL){
        while(A2 != NULL){
            if(A1->Item.Chave != A2->Item.Chave){
                Errado++;
            }

            A2 = A2->Prox;
            break;
        }
        A1 = A1->Prox;
    }

    if(Errado > 0){
        printf("Lista diferentes!!!!");
    }
    else{
        printf("Listas Iguais!!!!");
    }
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d ", aux->Item.Chave);
        aux=aux->Prox;
    }
}

int main()
{

    TipoLista ML;
    TipoLista M2;
    TipoItem Item;

    FLVazia(&ML);
    Item.Chave = 1;
    Insere(Item,&ML);
    Item.Chave = 2;
    Insere(Item,&ML);
    Item.Chave = 3;
    Insere(Item,&ML);
    Item.Chave = 4;
    Insere(Item,&ML);
    Item.Chave = 5;
    Insere(Item,&ML);
    Item.Chave = 6;
    Insere(Item,&ML);
    imprime(ML);
    printf("\n\n");
    FLVazia(&M2);
    Item.Chave = 1;
    Insere(Item,&M2);
    Item.Chave = 2;
    Insere(Item,&M2);
    Item.Chave = 3;
    Insere(Item,&M2);
    Item.Chave = 4;
    Insere(Item,&M2);
    Item.Chave = 5;
//    Insere(Item,&M2);
    Item.Chave = 6;
    Insere(Item,&M2);
    Item.Chave = 7;
//    Insere(Item,&M2);
    imprime(M2);
    printf("\n\n");
    ListasIguais(&ML,&M2);


    return 0;
}
