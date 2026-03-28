#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define tam 10
#define pos 10
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
   char nome[tam];
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
        printf("%s\n\n\n", aux->Item.nome);
        aux=aux->Prox;
    }
}
int Hash(char *nome){
	int q=0,i=0;
	for(i=0;nome[i]!='\0';i++){
		q+=nome[i];

	}
	return q%10;
}

void FHVazia(TipoLista hash[]){
	int i;
	for(i=0;i<pos;i++){
		FLVazia(&hash[i]);

	}
}
void InsereHash(TipoLista hash[],char *nome){
	TipoItem it;
	strcpy(it.nome,nome);
	int h;
	h=Hash(nome);
	Insere(it,&hash[h]);
}
void ImprimeHash(TipoLista hash[]){
	int i;
	for(i=0;i<pos;i++){
		printf("hash %d:\n ",i);
		imprime(hash[i]);

	}
}



int main()
{
	TipoLista hash[tam];
	FHVazia(hash);
	InsereHash(hash,"brenna");
	InsereHash(hash,"brenna");
	InsereHash(hash,"branne");
	ImprimeHash(hash);


    return 0;
}
