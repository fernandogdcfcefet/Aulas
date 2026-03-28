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
    TipoApontador  Prox, Ant;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
    int tam;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->Primeiro->Ant  =  NULL;
    Lista->tam=0;
}

int  Vazia( TipoLista  Lista ){
    if (Lista.tam==0)
        return  1;
    else
        return 0;
}

void  Insere(TipoItem  x ,	TipoLista  * Lista ){

    if (Lista->tam==0){
            //printf("aa");
        Lista->Primeiro->Item=x;
    }else{
        Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
        Lista->Ultimo->Prox->Ant  =  Lista->Ultimo;
        Lista->Ultimo  =  Lista->Ultimo->Prox ;
        Lista->Ultimo->Item  =  x;
        Lista->Ultimo->Prox  =  NULL;


    }

    Lista->tam++;
}

//void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
//{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
//    TipoApontador  q;
//    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
//        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
//    return ;
//}
//    q =  p->Prox;  *Item  =  q->Item ;
//    p->Prox  =  q->Prox ;
//    if ( p->Prox == NULL )  Lista->Ultimo  = p;
//    free (q);
//}
void  Retira(TipoApontador  retirado,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    if ( Vazia(*Lista )	||	retirado == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }else if (retirado->Ant==NULL && retirado->Prox!=NULL){
        TipoApontador p=retirado->Prox;
        Lista->Primeiro=p;
        p->Ant=NULL;
    }else if (retirado->Prox==NULL && retirado->Ant!=NULL){
        TipoApontador a=retirado->Ant;
        Lista->Ultimo=a;
        a->Prox=NULL;
    }else if (retirado->Prox!=NULL && retirado->Ant!=NULL){
        TipoApontador p,a;
        p=retirado->Prox;
        a=retirado->Ant;
        a->Prox=p;
        p->Ant=a;
    }
    Lista->tam--; //nao apagaaaaaaaaaaaaaa
    free (retirado); //nao apagaaaaaaa
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
    printf("Tamanho: %d\n",ML.tam);
}

int main()
{
    TipoLista lista;
    TipoItem aux;
    FLVazia(&lista);
    for (int i=0;i<4;i++){
        aux.Chave=i;
        //printf("%d",i);
        Insere(aux,&lista);
    }
    imprime(lista);
    TipoApontador tst;
    tst=lista.Primeiro->Prox;
    Retira(tst,&lista,&aux);
    tst=lista.Ultimo;
    Retira(tst,&lista,&aux);

    imprime(lista);
    return 0;
}
