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

void Retira_Todos(TipoItem Item, TipoLista *Lista){

    TipoApontador aux=Lista->Primeiro->Prox;

    while(aux!=NULL){
        if(aux->Item.Chave == Item.Chave){
            Retira(aux, &Lista, &Item);
        }
        aux=aux->Prox;
    }
}

void Ordena(TipoLista *Lista){

    TipoApontador aux, aux2, troca;

    for(aux=Lista->Primeiro->Prox; aux!=NULL; aux=aux->Prox){
        for(aux2=Lista->Primeiro->Prox; aux2!=NULL; aux2=aux2->Prox){

                if(aux->Item.Chave < aux2->Item.Chave){
                        troca=aux->Item.Chave;
                        aux->Item.Chave=aux2->Item.Chave;
                        aux2->Item.Chave=troca;
                }
        }
    }
}

void Insere_Ordenado(TipoItem x, TipoLista *Lista){

    TipoApontador aux=Lista->Primeiro->Prox;

        while(aux != NULL){
            if(aux->Item.Chave == x.Chave){
                Insere(x, &Lista);
            }
            aux=aux->Prox;
        }
}

int main(){

    TipoLista ML;
    TipoItem item, coisa;
    int i;

    FLVazia(&ML);

    for(i=0; i<5; i++){
        scanf("%d", &item.Chave);
        Insere(item, &ML);
    }
    printf("\n");
    imprime(ML);
    printf("\n");

    //LETRA A- RETIRA TODOS
    /*printf("Informe o item que deseja retirar:\n");
    scanf("%d", &coisa.Chave);
    Retira_Todos(coisa, &ML);
    printf("\n");
    imprime(ML);*/


    //LETRA B- PRIMEIRA PARTE- FUNÇAO PARA ORDENAR MINHA LISTA
     /*Ordena(&ML);
    imprime(ML);*/

    //LETRA B- SEGUNDA PARTE - FUNCAO PARA INSERIR ORDENADO
    /*printf("Informe o item que deseja inserir:\n");
    scanf("%d", &coisa.Chave);
    Insere_Ordenado(coisa, &ML);
    printf("\n");
    imprime(ML);*/

    return 0;
}
