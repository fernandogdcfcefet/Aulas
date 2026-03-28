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
    TipoApontador  Primeiro ;
    int tamanho;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Primeiro->Prox  =  Lista->Primeiro;
    Lista->tamanho=0;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista.tamanho==0 ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{
    if(Lista->tamanho==0){
        Lista->Primeiro->Item=x;
    }else{
        TipoApontador aux= Lista->Primeiro;
        while(aux->Prox!=Lista->Primeiro){
            aux=aux->Prox;
        }
        aux->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
        aux->Prox->Prox=Lista->Primeiro;
        aux->Prox->Item=x;
    }
    Lista->tamanho++;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if ( Vazia(*Lista )){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;

    }else if(Lista->tamanho==1){
        Lista->tamanho=0;
    }else{
        q =  p->Prox;  *Item  =  q->Item ;
        p->Prox  =  q->Prox ;
        if ( q == Lista->Primeiro )  Lista->Primeiro  = Lista->Primeiro->Prox;
        free (q);
        Lista->tamanho--;
    }
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro;
    while(aux->Prox!=ML.Primeiro){
        printf("%d ", aux->Item.Chave);
        aux=aux->Prox;
    }
    printf("%d ", aux->Item.Chave);
    printf("\nTamanho:%d\n",ML.tamanho);
}

int main()
{
    TipoItem coisa;
    TipoLista ML;
    int i;
    FLVazia(&ML);
    coisa.Chave=2;
    Insere(coisa,&ML);
    for(i=0;i<5;i++){
        coisa.Chave=i;
        Insere(coisa,&ML);
    }

    imprime(ML);

    Retira(ML.Primeiro->Prox->Prox->Prox->Prox->Prox,&ML,&coisa);

    imprime(ML);


    return 0;
}


















