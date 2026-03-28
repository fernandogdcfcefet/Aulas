#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 30
typedef  int  TipoChave;
typedef  struct  {
    TipoChave Chave;
    /*  outros  componentes  */
    double notas[MAXTAM];
}  TipoItem;
typedef  struct  {
    TipoChave Chave;
    int matricula;
}  Aluno;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	TipoApontador  q;   /*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL)
    {   printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
        return ;
    }

    q =  p->Prox;  *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void imprime(TipoLista ML)
{   TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
void maior_media(const TipoLista *ML, int n, int x)
{   TipoApontador aux = ML->Primeiro->Prox;
    int i, j, medias[n];
    double notas[n], media = 0;
    for(i = 0; i < n; i++) {


        for(j = 0; j < x; j++){
            while(aux!=NULL){
                notas[j] = ML->Primeiro->Item->notas[j];
                media = media + notas[j];
                aux = aux->Prox;
            }

        }

    medias[i] = (media/j);


    }
}
/**-------------------------------------------------------------------------------------------------------------------------------------------------------*/
int main()
{   TipoItem aluno;
    TipoLista lista_de_alunos;
    int n, x;
    maior_media(&lista_de_alunos, n, x);

    return 0;
}
