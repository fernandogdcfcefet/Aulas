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
    int Tamanho;
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
    q =  p->Prox;
    *Item  =  q->Item;
    p->Prox  =  q->Prox;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
    Lista->Tamanho--;
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    int count=0,j;
    TipoApontador aux=Lista->Primeiro->Prox, anterior=Lista->Primeiro->Prox;
    TipoItem ItemAux;
    while(aux!=NULL){
        if(Item.Chave == aux->Item.Chave){
            /*Não consegui acessar a memória anterior*/
            Retira(aux, Lista, &ItemAux);

        }
        aux=aux->Prox;
        count++;

    }
}

void InsereOrdenado(TipoItem x, TipoLista *Lista){
    int i=0,j,k, tamanho;
    TipoItem Itens[Lista->Tamanho+1], ItemAux;

    TipoApontador aux=Lista->Primeiro->Prox;
    while(aux!=NULL){
        Itens[i].Chave = aux->Item.Chave;
        aux=aux->Prox;
        i++;
    }
    for(j=0;j<Lista->Tamanho-1;j++){
       for(k=0;k<Lista->Tamanho-1;k++){
            if(Itens[k].Chave > Itens[k+1].Chave){
                ItemAux = Itens[k];
                Itens[k] = Itens[k+1];
                Itens[k+1] = ItemAux;
            }
        }
    }
    tamanho = Lista->Tamanho;
    FLVazia(Lista);
    for(j=0;j<tamanho;j++){
        Insere(Itens[j], Lista);
    }
}

void main(){
    int i;
    TipoLista lista;
    TipoItem aux;
    FLVazia(&lista);

    for(i=0;i<20;i++){
        aux.Chave = i;
        Insere(aux,&lista);
    }
    imprime(lista);
    aux.Chave = 5;
    RetiraTodos(&lista, aux);
    imprime(lista);
    //printf("-------\n");
    //InsereOrdenado(aux,&lista);
    //imprime(lista);
}
