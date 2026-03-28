#include <stdio.h>
#include <stdlib.h>
# define N 11
# define TAM 50
typedef  int  TipoChave;
//typedef  struct  {
    //TipoChave Chave;
    /*  outros  componentes  */
//}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;


typedef struct{
	char nome[TAM];
} TipoItem;

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

// questao3

int Hash(char nome){
	int i=0;
	int total=0;
	for(i=0;nome[i]!='\0';i++){
		total=total+nome[i];
	}
	return total%10;
}

void FHvazia(TipoLista hash[])

for(int i=0;i<N;i++){
	FLVazia(&hash[i]);
}

void insereHash(TipoLista hash[], char *nome){
	TipoItem x;
	int h=Hash(nome);
	strcpy(x.nome,nome);
	Insere(x,&hash[h]);
}

void buscaHash(Tipolista hash[],char * nome){
	TipoApontador p,q;
	int h= Hash(nome);
	for(q=p.hash[h]->Primeiro,p=lista->Primeiro->Prox;p!=NULL;q=p,p=p->Prox){
		if(strcmp(p->Item,Item)){
			return p;
		}
	}
}




// questao 1 letra A

void troca(TipoLista *Lista, TipoApontador a, TipoApontador b){
	TipoItem aux;
	aux=a->Item;
	a->Item=b->Item;
	b->Item=aux;
}

void sort(TipoLista *Lista){
	TipoApontador i,j;

	for(j=lista->Primeiro->Prox;j!=NULL;j=j->Prox){
		for(i=lista->Primeiro->Prox;i!=lista->Ultimo;i=i->Prox){
			if(i->Item.chave>i->Prox->Item.chave){
				troca(lista,i,i->Prox);
			}
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
    TipoItem item;
    FLVazia(&ML);
    item.Chave=1;Insere(item,&ML);
    item.Chave=7;Insere(item,&ML);
    item.Chave=13;Insere(item,&ML);
    item.Chave=5;Insere(item,&ML);
    item.Chave=9;Insere(item,&ML);
    Retira(ML.Primeiro->Prox,&ML,&item);
    imprime(ML);
    return 0;
}
