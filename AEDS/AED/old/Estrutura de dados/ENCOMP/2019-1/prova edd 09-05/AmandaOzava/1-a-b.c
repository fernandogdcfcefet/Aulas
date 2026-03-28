#include <stdio.h>
#include <stdlib.h>
#define TAM 4
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
//questao 1 a)
void RetiraTodos(TipoLista *lista, TipoItem item)
{
    if(Vazia(*lista))
    {
        printf("Lista Vazia");
        return;
    }
    TipoApontador aux;
    TipoItem item2;
    aux=lista->Primeiro;
    while(aux->Prox!=NULL)
    {
        if(aux->Prox->Item.Chave==item.Chave)
            Retira(aux, lista, &item2);
        else
        aux=aux->Prox;
    }
}
//questao 1 b)
void InsereOrdenado(TipoLista *lista, TipoItem item)
{
    TipoApontador aux, aux2;
    aux=lista->Primeiro;
    while(aux->Prox!=NULL)
    {
        if(aux->Prox->Item.Chave>item.Chave)//crio uma nova celula que recebe o item, ela aponta para o proximo e o anterior a ela aponta para ela.
        {
            aux2=(TipoApontador)  malloc( sizeof (TipoCelula));
            aux2->Item=item;
            aux2->Prox=aux->Prox;
            aux->Prox=aux2;
            return;
        }
        aux=aux->Prox;
    }
    // essa parte do código é para caso a chave seja maior que todos os numeros da lista, ou caso a lista esteja vazia.
    Insere(item, lista);
}
int main()
{
    TipoLista lista;
    TipoItem item;
    FLVazia(&lista);
    for(int i=0;i<TAM;i++)
    {
        scanf("%d", &item.Chave);
        Insere(item, &lista);
    }

    //questao 1 a)
    printf("Qual chave deseja remover?");
    scanf("%d", &item.Chave);
    printf("Lista:\n");
    RetiraTodos(&lista, item);
    imprime(lista);


    //questao 1 b)
    printf("Qual chave deseja inserir?");
    scanf("%d", &item.Chave);
    InsereOrdenado(&lista, item);
    printf("Lista:\n");
    imprime(lista);
    return 0;
}
