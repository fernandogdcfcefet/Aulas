#include <stdio.h>
#include <stdlib.h>

typedef int TipoChave;

typedef struct{
    TipoChave Chave;
    /*  outros  componentes  */
}TipoItem;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
}TipoCelula;

typedef struct{
    TipoApontador Primeiro, Ultimo;
}TipoLista;

void FLVazia(TipoLista *Lista)
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{
	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
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
    q =  p->Prox;
	*Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )
		Lista->Ultimo  = p;
    free (q);
}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
	if(Vazia(*Lista))
		printf("Lista esta vazia\n");
	else{
		TipoApontador p;
		p = Lista->Primeiro->Prox;
		while(p!=NULL){
			TipoApontador q;
			if(p->Item.Chave == Item.Chave){
				q = p;
				p = q->Prox;
			}
			//free(q);
			if(p==NULL)
				return;
			p = p->Prox;
		}
	}
}

void InsereOrdenado(TipoItem x, TipoLista *Lista){
	int aux;
	if(Vazia(*Lista)){
		Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    	Lista->Ultimo  =  Lista->Ultimo->Prox ;
    	Lista->Ultimo->Item  =  x;
    	Lista->Ultimo->Prox  =  NULL;
	}
	else{
		TipoApontador p = Lista->Primeiro->Prox;
		while(p!=NULL){
			aux = x.Chave;
			if(aux < p->Item.Chave){
				x.Chave = p->Item.Chave;
				p->Item.Chave = aux;
			}
			p->Prox = (TipoApontador)malloc(sizeof(TipoCelula ));
			p->Item.Chave = aux;
			p->Prox = NULL;
			p = p->Prox;
		}
	}
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

int main()
{
	TipoLista ML;
	TipoApontador p;
	TipoItem coisa, coisa2;

	FLVazia(&ML);
	coisa.Chave = 2;
	/*Insere(coisa, &ML);
	coisa.Chave = 3;
	Insere(coisa, &ML);
	coisa.Chave = 4;
	Insere(coisa, &ML);
	coisa.Chave = 5;
	Insere(coisa, &ML);
	imprime(ML);
	coisa2.Chave = 3;
	RetiraTodos(&ML, coisa2);
	//printf("O item removido foi %d\n", coisa2.Chave);
	imprime(ML);*/
	InsereOrdenado(coisa,&ML);
	imprime(ML);
	coisa.Chave = 8;
	InsereOrdenado(coisa,&ML);
	imprime(ML);
	coisa.Chave = 4;
	InsereOrdenado(coisa,&ML);
	imprime(ML);



    return 0;
}
