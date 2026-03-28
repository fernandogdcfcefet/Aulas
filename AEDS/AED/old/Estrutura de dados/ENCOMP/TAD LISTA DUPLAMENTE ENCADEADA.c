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
    TipoApontador  Prox,Ant;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
    int tamanho;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->Primeiro->Ant =NULL;
    Lista->tamanho=0;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista.tamanho==0) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{
    if(Vazia(*Lista)){
        Lista->Primeiro->Item=x;
    }else{
        TipoApontador aux = Lista->Ultimo;
        Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
        Lista->Ultimo  =  Lista->Ultimo->Prox ;
        Lista->Ultimo->Item  =  x;
        Lista->Ultimo->Prox  =  NULL;
        Lista->Ultimo->Ant=aux;
    }
    Lista->tamanho++;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{

    TipoApontador  ant,prox;
    if ( Vazia(*Lista )	||	p == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;

    }else if(Lista->tamanho>1){
        ant=p->Ant;
        prox=p->Prox;
        *Item  =  p->Item ;
        if(ant!=NULL)ant->Prox=prox;
        if(prox!=NULL)prox->Ant=ant;
        if ( p->Prox == NULL )  Lista->Ultimo  = p->Ant;
        if(p->Ant==NULL) Lista->Primeiro=prox;
        free (p);
        Lista->tamanho--;
    }else{
        Lista->tamanho=0;
    }
}

void imprime(TipoLista ML){
    if(!Vazia(ML)){
        TipoApontador aux=ML.Primeiro;
        while(aux!=NULL){
            printf("%d ", aux->Item.Chave);
            aux=aux->Prox;
        }
    }
    printf("\nTamanho:%d\n",ML.tamanho);
}

void retiraTodos(TipoChave ch,TipoLista *lista,TipoItem *item){
    TipoApontador aux=lista->Primeiro;
    while(aux!=NULL){
        if(aux->Prox!=NULL && aux->Prox->Item.Chave==ch){
            Retira(aux,lista,item);
        }else{
            aux=aux->Prox;
        }
    }
    printf("\n");
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
    for(i=0;i<7;i++){
        Retira(ML.Primeiro,&ML,&coisa);
    }
//    retiraTodos(2,&ML,&coisa);

    imprime(ML);


    return 0;
}


















