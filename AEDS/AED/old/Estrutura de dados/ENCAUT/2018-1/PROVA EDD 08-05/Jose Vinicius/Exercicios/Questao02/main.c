#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//Escrever uma função para verificar se duas lista são iguais.
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
//Função implementada
void Iguais(TipoLista l1, TipoLista l2){
    int i;
    TipoApontador Aux1, Aux2;
    TipoItem item1, item2;
    Aux1 = l1.Primeiro; Aux2 = l2.Primeiro;
    //Tratamento de erro para possiveis lista vazias.
    if(Vazia(l1) || Vazia(l2))
        printf("Uma das lista enviadas esta vazia logo elas não são iguais");
    for(i = 0;Aux1 != NULL; i++){
        Retira(Aux1, &l1,  &item1);
        Retira(Aux2, &l2, &item2);
        if(item1.Chave == item2.Chave){
        }
        else{
            printf("Lista não são iguais");
            return;
        }
        Aux1 = Aux1->Prox; Aux2 = Aux2->Prox;
    }
    printf("São iguais");
}
int main()
{
    setlocale(LC_ALL, "Portuguese");
    TipoLista lista1, lista2;
    FLVazia(&lista1);
    FLVazia(&lista2);
    TipoItem it1, it2;
    it1.Chave = 1;
    it2.Chave = 2;
    Insere(it1, &lista1);
    Insere(it2, &lista2);
    Iguais(lista1, lista2);
    return 0;
}
