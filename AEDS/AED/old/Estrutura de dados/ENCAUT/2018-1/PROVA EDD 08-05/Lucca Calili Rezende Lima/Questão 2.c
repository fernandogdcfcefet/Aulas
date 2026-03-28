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

void VerificaListasIguais(TipoLista ML1, TipoLista ML2){
 TipoApontador aux1=ML1.Primeiro->Prox;
 TipoApontador aux2=ML2.Primeiro->Prox;
 int a=0;
    while(aux1!=NULL && aux2!=NULL){

         printf("aux 1:%d  , aux2 %d\n", aux1->Item.Chave,aux2->Item.Chave);

        if(aux1->Item.Chave == aux2->Item.Chave ){
           printf("\n\nchaves iguais\n\n");

            aux1=aux1->Prox;
            aux2=aux2->Prox;

        }else{
                aux1=NULL;
                aux2=NULL;
                printf("\n\nchaves diferentes\n\n");
                a=1;
            }
      }
      if(a==1){
            printf("\n\listas diferentes\n\n");
      }else {  printf("\n\listas iguais\n\n");}


}


int main()
{
    TipoLista ML1;
    TipoLista ML2;

    FLVazia(&ML1);
    FLVazia(&ML2);

    TipoItem a;
    a.Chave = 3;
    Insere(a,&ML1);
    a.Chave = 5;
    Insere(a,&ML1);
    a.Chave = 5;
    Insere(a,&ML1);

    TipoItem b;
    b.Chave = 3;
    Insere(b,&ML2);
    b.Chave = 4;
//    Insere(b,&ML2);
    b.Chave = 5;
    Insere(b,&ML2);

    imprime(ML1);
    printf(" \n");
    imprime(ML2);

  VerificaListasIguais(ML1,ML2);



    return 0;
}
