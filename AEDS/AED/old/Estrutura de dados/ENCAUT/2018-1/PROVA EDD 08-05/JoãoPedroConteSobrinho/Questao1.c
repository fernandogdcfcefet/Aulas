#include <stdio.h>
#include <stdlib.h>
typedef  int  TipoChave;
typedef  struct  {
    TipoChave x, y; //Criei os vertices x e y
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


/*Ate esse ponto o programa se mantem o mesmo*/


void  Insere(TipoItem  Item ,	TipoLista  * Lista )
{  	if(Lista->Ultimo->Item.x == Item.x && Lista->Ultimo->Item.y == Item.y){ //Verifico se os pontos sao os mesmos dos anteriores, pois se for os mesmo nao formaram um poligono
        printf("Erro, pontos iguais os anteriores\n");
        return;
    }else{ // Se nao for insere normalmente
        Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
        Lista->Ultimo  =  Lista->Ultimo->Prox ;
        Lista->Ultimo->Item  =  Item;
        Lista->Ultimo->Prox  =  NULL;
    }
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
        printf("x: %d \t y: %d\n", aux->Item.x, aux->Item.y); // Imprime os dois vertices
        aux=aux->Prox;
    }
}

int main()
{
    TipoLista Poligono; // Cria a lista
    FLVazia(&Poligono);// Faz ela vazia
    TipoItem Item; //Cria os itens

    //Insere itens
    Item.x = 1;
    Item.y = 2;
    Insere(Item, &Poligono);
    Item.x = 3;
    Item.y = 2;
    Insere(Item, &Poligono);
    Item.x = 4;
    Item.y = 2;
    Insere(Item, &Poligono);
    Item.x = 10;
    Item.y = 3;
    Insere(Item, &Poligono);
    Item.x = 3;
    Item.y = 7;
    Insere(Item, &Poligono);
    //Imprime lista
    imprime(Poligono);

    return 0;
}
