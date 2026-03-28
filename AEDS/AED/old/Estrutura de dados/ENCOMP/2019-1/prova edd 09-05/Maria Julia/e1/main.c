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
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
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
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
    printf("\n");
}
void troca (TipoItem *i1,TipoItem *i2){
    TipoItem aux;
    aux=*i1;
    *i1=*i2;
    *i2=aux;
}
void ordena (TipoLista *lista){
    TipoApontador aux,aux1;
    aux=lista->Primeiro;

    while (aux!=NULL){
        aux1=lista->Primeiro->Prox;
        while(aux1!=NULL){
            if (aux1->Item.Chave>=aux->Item.Chave){
                troca(&aux1->Item,&aux->Item);
            }
            aux1=aux1->Prox;
        }
        aux=aux->Prox;
    }
}
void insereOrdenado (TipoItem x, TipoLista *lista){
    Insere(x,lista);
    ordena(lista);

}
void RetiraTodos(TipoLista *lista, TipoItem Item){
    TipoApontador aux;
    aux=lista->Primeiro;
    while(aux!=NULL){
        if ((aux->Prox!=NULL) && (aux->Prox->Item.Chave==Item.Chave)){
            Retira(aux,lista,&Item);
        }
        aux=aux->Prox;
    }
}

int main()
{
    TipoLista lista;
    FLVazia(&lista);
    TipoItem obj;
    for (int i=0;i<5;i++){
        scanf("%d",&obj.Chave);
        Insere(obj,&lista);

    }
    //imprime(lista);
    //teste do remover todos
//    printf("Chave do item a remover: ");
//    scanf("%d",&obj.Chave);
//    RetiraTodos(&lista, obj);
//    imprime(lista);

    //teste do troca
//    TipoItem i1,i2;
//    i1.Chave=2;
//    i2.Chave=3;
//    troca(&i1,&i2);
//    printf("%d",i2.Chave);

    //teste do odena
    //ordena(&lista);
    //imprime(lista);


    TipoItem it;
    printf("\nchave do novo item a ser inserido\n");
    scanf("%d",&it.Chave);
    insereOrdenado(it,&lista);
    imprime(lista);


    return 0;
}

