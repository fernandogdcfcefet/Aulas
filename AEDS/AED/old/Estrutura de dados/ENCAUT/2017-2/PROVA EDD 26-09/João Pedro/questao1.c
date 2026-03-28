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

}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    TipoApontador Aux = Lista->Primeiro->Prox, p;
    TipoItem ItemAux;

    do{
        if(Aux->Item.Chave == Item.Chave){
            p = Aux;
            Retira(Aux, Lista, &ItemAux);
        }
        Aux=Aux->Prox;
    }while(Aux != NULL);
}

void InsereOrdenado(TipoItem Item, TipoLista *Lista){
    TipoApontador Aux = Lista->Primeiro->Prox, p;
    TipoLista ListaAux;
    FLVazia(&ListaAux);
    int i, cont = 0;
    TipoItem ItemAux;
    aqui:
    while(Aux != NULL){
        if(Aux->Item.Chave > Item.Chave){
            p = Aux;
            while(p!= NULL){
                p = p->Prox;
                Retira(p, Lista, &ItemAux);
                Insere(ItemAux, &ListaAux);
            }
            Insere(Item, Lista);
            p = Aux;
            for(i=0; i<cont; i++){
                Retira(p, &ListaAux, &ItemAux);
                Insere(ItemAux, Lista);
            }
            return;
        }else if(Aux->Item.Chave == Item.Chave){
            p = Aux;
            while(p!= NULL){
                Retira(p, Lista, &ItemAux);
                Insere(ItemAux, &ListaAux);
                p = p->Prox;
            }
            Insere(Item, Lista);
            p = Aux;
            for(i=0; i<cont; i++){
                Retira(p, &ListaAux, &ItemAux);
                Insere(ItemAux, Lista);
            }
            return;
        }else{
            Aux = Aux->Prox;
        }
        cont++;
    }
    Insere(Item, Lista);
}

/*
**Pelo comentário da linha 35 temos que o programa retira um elemento depois do ponteiro passado p,
**logo devemos pensar em uma maneira de voltar um ponteiro anterios.
**Por falta de tempo a implementação não foi concluida com sucesso.
*/

int main()
{
    TipoLista Lista;
    FLVazia(&Lista);
    TipoItem Item;

    Item.Chave=4;
    InsereOrdenado(Item,&Lista);
    Item.Chave=5;
    InsereOrdenado(Item,&Lista);
    Item.Chave=7;
    InsereOrdenado(Item,&Lista);
    Item.Chave=8;
    InsereOrdenado(Item,&Lista);
    Item.Chave=5;
    InsereOrdenado(Item,&Lista);

    imprime(Lista);

    Item.Chave=5;
    RetiraTodos(&Lista, Item);

    printf("\n\n");
    imprime(Lista);

    return 0;
}
