#include <stdio.h>
#include <stdlib.h>

typedef  int  TipoChave;
typedef  struct  {
char  Chave;
/*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;
typedef  struct  {
    TipoApontador  Fundo,  Topo;
    int  Tamanho;
}  TipoPilha ;

void  FPVazia( TipoPilha  *Pilha)
{
    Pilha->Topo =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Fundo =  Pilha->Topo;
    Pilha->Topo->Prox  = NULL;
    Pilha->Tamanho =  0;
}
int  Vazia( TipoPilha  Pilha)
{
    return  ( Pilha .Topo == Pilha .Fundo) ;
}

void  Empilha(TipoItem  x ,	TipoPilha  *Pilha)
{
    TipoApontador  Aux;
    Aux =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Pilha->Topo->Item  =  x;
    Aux->Prox  =  Pilha->Topo;
    Pilha->Topo = Aux; Pilha->Tamanho++;
}

void  Desempilha( TipoPilha  *Pilha ,  TipoItem  *Item)
{
    TipoApontador  q;
    if	( Vazia(*Pilha ) )  {
            printf ( "Erro :lista vazia\n");
            return ;
    }
    q =  Pilha->Topo;
    Pilha->Topo =  q->Prox ;
    *Item  =  q->Prox->Item ;
    free (q) ;
    Pilha->Tamanho--;
}

int  Tamanho( TipoPilha  Pilha)
{
    return  ( Pilha .Tamanho) ;
}

void  Imprime( TipoPilha  Lista )
{
    TipoApontador  Aux;
    Aux =  Lista.Topo->Prox ;
    while  (Aux  !=  NULL){
        printf ( "%d\n" ,  Aux->Item .Chave) ;
        Aux = Aux->Prox ;
    }
}
void palindromo (TipoPilha *P1){
	int cont = 0;
	TipoItem x;
	TipoApontador i,j,k;
	TipoPilha P2,P3;
	FPVazia(&P2);
	FPVazia(&P3);
	i=P1->Topo->Prox;
	while(i!=NULL){ // desempilha p1 e empilha em p2 e p3
		Desempilha(P1,&x);
		Empilha (x,&P2);
		Empilha(x,&P3);
		i=i->Prox;
	}
	j=P2.Topo->Prox;
	while(j!=NULL){ // desempilha p2 e empilha em p1
		Desempilha(&P2,&x);
		Empilha (x,P1);
		j=j->Prox;
	}
	i=P1->Topo->Prox;
	k=P3.Topo->Prox;
	while(i!=NULL && k!=NULL){ //compara se p1 e p3 sao iguais
		if(i->Item.Chave != k->Item.Chave){
			cont++;
		}
		i=i->Prox;
		k=k->Prox;
	}
	if(cont==0) printf("palindromo");
	if(cont!=0) printf("nao e palindromo");
}

int main()
{
	TipoItem x,y,z;
	TipoPilha P;
	FPVazia(&P);
	x.Chave='a';
	y.Chave='d';
	z.Chave='a';
	Empilha(x,&P);
	Empilha(y,&P);
	Empilha(z,&P);
	palindromo(&P);
    return 0;
}
