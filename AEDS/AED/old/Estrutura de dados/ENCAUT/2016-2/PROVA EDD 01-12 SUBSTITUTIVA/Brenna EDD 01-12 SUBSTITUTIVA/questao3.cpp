#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define tam 10
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    char nome[];
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

typedef  struct  {
    char nome;
} Hash;

int hash(char *nome)
{
	int i,q;
	for(i=0;nome[i]!='\0';i++){
		q=+nome[i];
	}
	return q%10;
	
	
}
int inicializahash(hash){
	int i;
	for(i=0;i<=tam;i++){
		FLVazia(nome(i));
	}
}

void InsereHash(Hash){
	
	TipoItem item;
	strcpy(nome.item,nome);
	int h=hash(i);
	Insere(h,Lista);
}
void verifica(TipoLista lista, int x){
	int i=0;
	
	TipoApontador aux=Lista.Primeiro->Prox;
	for(i=0;i<=tam;i++){
		if(aux.Item.Chave==x){
			return (1);
		}
		
	}
	return -1;
}
		
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%c\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void ImprimeHash(Hash){
	int i;
	for(i=0;i<=tam;i++){
		printf("Hash %d",i)
		imprime(hash(i));
		
	}
}

int main()
{
    TipoLista ML;
    TipoItem item;
    FLVazia(&ML);
    item.Chave='aca';
	Insere(item,&ML);
    item.Chave='caa';
	Insere(item,&ML);
    item.Chave='aac';
	Insere(item,&ML);
  
    imprime(ML);
   
   
    
    return 0;
}
