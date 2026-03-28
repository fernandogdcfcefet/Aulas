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
    int Tamanho;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->Tamanho = 0;
}

int  Vazia( TipoLista  Lista )
{  return  (Lista.Tamanho == 0) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    Lista->Tamanho++;
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
    Lista->Tamanho--;
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

void RetiraTodos( TipoLista  *Lista ,  TipoItem  Item){
    TipoApontador aux = Lista->Primeiro->Prox;
    while(aux!=NULL){
        if(aux->Item.Chave == Item.Chave){
            Retira(aux,Lista,&aux->Item);
        }
        else aux=aux->Prox;
    }
}

void  InsereOrdenado(TipoItem  x , TipoLista  *Lista ){
    TipoApontador aux = Lista->Primeiro->Prox;
    int t = Lista->Tamanho+1;
    TipoItem vet[t], aux1;
    //vetor de itens recebe todos os itens da lista passada.
    for(int i=0;i<Lista->Tamanho;i++){
        vet[i] = aux->Item;
        aux = aux->Prox;
    }
    //vetor recebe o item passado por parâmetro.
    vet[t-1] = x;
    //ordenação do vetor de itens.
    for(int i=0;i<t;i++){
        for(int j=(i+1);j<t;j++){
            if(vet[j].Chave<vet[i].Chave){
                aux1 = vet[i];
                vet[i] = vet[j];
                vet[j] = aux1;
            }
        }
    }
    FLVazia(Lista);
    for(int i=0;i<t;i++){
        Insere(vet[i],Lista);
    }

}

int main()
{
    TipoLista ML;
    TipoItem Item,a,b;
    FLVazia(&ML);
    Item.Chave = 10;
    InsereOrdenado(Item,&ML);
    Item.Chave = 5;
    InsereOrdenado(Item,&ML);
    Item.Chave = 5;
    InsereOrdenado(Item,&ML);
    imprime(ML);
    printf("\n\n");
    a.Chave = 5;
    RetiraTodos(&ML,a);
    imprime(ML);
    printf("\n\n");
    b.Chave = 11;
    InsereOrdenado(b,&ML);
    imprime(ML);
    return 0;
}
