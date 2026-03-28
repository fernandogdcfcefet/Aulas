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
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

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

void VerificaIguais(TipoLista Lista1, TipoLista Lista2){
    TipoApontador Aux1 = Lista1.Primeiro->Prox, //Apontador para a lista 1
                  Aux2 = Lista2.Primeiro->Prox; //Apontador para a lista 2

    if(Lista1.Tamanho != Lista2.Tamanho) //Verifica o Tamanho das listas (criado la em cima)
        printf("O tamanho das listas e diferente, logo elas se tornam diferentes\n");
    else{ //Se os tamanhos forem iguais ha uma chance de elas serem iguais, dai
        while(Aux1 != NULL || Aux2 != NULL){ // Se achar valor difernte, temos
            if(Aux1->Item.Chave != Aux2->Item.Chave){ //Achou diferente
                printf("As listas sao diferentes!!!\n");
                return; //Para funcao
            }
            Aux1=Aux1->Prox;
            Aux2=Aux2->Prox;
        }//se os valores nao forem diferentes
        printf("As listas sao iguais!!!\n");
    }
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
    printf("\n");
}

int main()
{
    TipoLista ML1, ML2; // Cria as listas 1 e 2
    FLVazia(&ML1); // Faz a lista 1 vazia
    FLVazia(&ML2); // Faz a lista 2 vazia
    TipoItem Item; // Cria o item


    //Insere os elementos na lista 1
    Item.Chave = 1;
    Insere(Item, &ML1);
    Item.Chave = 2;
    Insere(Item, &ML1);
    Item.Chave = 3;
    Insere(Item, &ML1);
    Item.Chave = 4;
    Insere(Item, &ML1);
    //Imprime a lista 1
    imprime(ML1);

    //Insere os elementos na lista 2
    Item.Chave = 1;
    Insere(Item, &ML2);
    Item.Chave = 2;
    Insere(Item, &ML2);
    Item.Chave = 3;
    Insere(Item, &ML2);
    Item.Chave = 4;
    Insere(Item, &ML2);
    //Imprime a lista 2
    imprime(ML2);

    //Chama a funcao que verifica que sao iguais
    VerificaIguais(ML1, ML2);

    return 0;
}
