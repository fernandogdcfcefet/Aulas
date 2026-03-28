#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef  int  TipoChave;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoNota *TipoApontadorNotas;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
    double valor;
    TipoApontadorNotas prox;
}  TipoNota ;

typedef  struct  {
    TipoChave matricula;
    char nome[100];
    TipoApontadorNotas notas;
    /*  outros  componentes  */
}  Aluno;

typedef struct {
    double valor;
    TipoApontadorNotas prox;
} Notas;



typedef  struct  TipoCelula  {
    Aluno  Item;
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

void  FNVazia( TipoNota  * TipoNota )
{ 	TipoNota->Primeiro  =  (TipoApontadorNotas)  malloc( sizeof ( TipoNota ) ) ;
    TipoNota->Ultimo  =  TipoNota->Primeiro ;
    TipoNota->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(Aluno  x ,	TipoLista  * Lista )
{
    FNVazia(Lista->Ultimo->Item.notas);
    Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  Aluno  *Item)
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
        printf("Matricula: %d\n", aux->Item.matricula);
        printf("Nome: %s\n\n", aux->Item.nome);
        aux=aux->Prox;
    }
}


void InsereNota(TipoLista *ML, int nota, TipoChave matricula){
    TipoApontador aux = ML->Primeiro->Prox;
    while(aux!=NULL){
        if(matricula == aux->Item.matricula){
            aux->Prox =  (TipoApontadorNotas)  malloc( sizeof ( TipoNota ) ) ;


        }
    }

}


int main()
{

    TipoLista ML;
    FLVazia(&ML);

    Aluno a;
    a.matricula = 98595;
    gets(a.nome);

    Insere(a,&ML);

    imprime(ML);

    Aluno b;
    b.matricula = 49894;
    gets(b.nome);

    Insere(b,&ML);

    imprime(ML);

    return 0;
}
