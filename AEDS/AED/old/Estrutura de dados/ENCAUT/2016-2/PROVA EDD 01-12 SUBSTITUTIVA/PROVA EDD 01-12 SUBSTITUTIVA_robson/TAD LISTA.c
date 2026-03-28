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
void troca(TipoItem *a,TipoItem *b){
	TipoItem aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void sort(TipoLista *li){
	TipoApontador i,j;
	for(i=li->Primeiro->Prox;i!=NULL;i++){
		for(j=li->Primeiro->Prox;j!=NULL;j++){
			if(i->Item.Chave > j->Item.Chave ) {
				troca(&i->Item, &j->Item);
			}
		}
	}
	TipoApontador aux= li->Primeiro->Prox;
	while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }

}
void retira_todos(TipoLista *ML, int c){
	TipoItem x;
	TipoApontador aux=ML->Primeiro->Prox;
	TipoApontador p;
    while(aux!=NULL){
        if(aux->Item.Chave == c){
        	Retira(ML->Primeiro,&ML,&x);
		}
        aux=aux->Prox;
    }
}

int main()
{
	int x,m;
    TipoLista ML;
    TipoItem item;
    FLVazia(&ML);
    item.Chave=1;Insere(item,&ML);
    item.Chave=7;Insere(item,&ML);
    item.Chave=13;Insere(item,&ML);
    item.Chave=5;Insere(item,&ML);
    item.Chave=9;Insere(item,&ML);
    //Retira(ML.Primeiro->Prox,&ML,&item);
    imprime(ML);
    printf("\n");
    //sort(&ML);
    printf("digite o chave para retirar\n");
    scanf("%d",&m);
    retira_todos(&ML,m);
    imprime(ML);
    return 0;
}
