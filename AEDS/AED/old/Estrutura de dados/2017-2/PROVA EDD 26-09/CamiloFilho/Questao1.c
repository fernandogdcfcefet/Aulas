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

void InsereOrdenado(TipoItem x, TipoLista *Lista){
    TipoApontador aux=*Lista.Primeiro;
    TipoApontador  q;
    while(aux->Prox!=NULL){
        if(aux->Prox->Item.Chave > x.Chave){ //verifico a posição onde devo inserir o novo elemento
            q = aux->Prox;      //guardo posição do proximo termo, referente ao que vou adicionar
            aux->Prox = (TipoApontador)  malloc(sizeof (TipoCelula ));
            aux->Prox->Item = x;    //crio o espaço de memoria e anexo ao novo elemento
            aux->Prox->Prox = q;    //faço o novo elemento ter o proximo como o proximo da lista
            return;
        }
        else
            aux=aux->Prox; //caso nao ache a posiçao
    }
    Insere(x, Lista); //se o novo elemento for o ultimo

}

void RetiraTodos(TipoLista *Lista, TipoItem Item){
    TipoApontador aux= Lista->Primeiro; //aux para percorrer lista
    TipoItem aux1; //item para guardar o valor retirado
    while(aux->Prox!=NULL){     // percorre a lista
        if(aux->Prox->Item.Chave==Item.Chave){ //busca elementos com o mesmo valor na lista
            Retira(aux->Prox,Lista, &aux1);
        }
        else{
            aux=aux->Prox;  //avança para proximo elemento
        }
    }
}

int main()
{
    TipoLista ML;
    FLVazia(&ML);

    TipoItem obj;

    obj.Chave = 1;
    Insere(obj,&ML);

    obj.Chave = 2;
    Insere(obj,&ML);

    obj.Chave = 1;
    Insere(obj,&ML);

    obj.Chave = 4;
    Insere(obj,&ML);

    obj.Chave = 5;
    Insere(obj,&ML);

    obj.Chave = 1;
    Insere(obj,&ML);

    obj.Chave = 1;

    RetiraTodos(&ML, obj);

    imprime(ML);

    return 0;
}
