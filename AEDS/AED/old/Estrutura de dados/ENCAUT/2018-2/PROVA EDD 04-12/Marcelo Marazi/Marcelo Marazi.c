#include <stdio.h>
#include <stdlib.h>

typedef  long  TipoChave;

typedef  struct  TipoRegistro
{
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoRegistro;
typedef  struct  TipoNo  *  TipoApontador;

typedef  struct  TipoNo
{
    TipoRegistro  Reg;
    TipoApontador  Esq,	Dir ;
}  TipoNo;

void  Inicializa (TipoApontador *raiz)
{
    * raiz  =  NULL ;
}

void  Insere( TipoRegistro  x,  TipoApontador *p)
{
    if  ( *p == NULL)
    {
        *p  =  (TipoApontador)malloc( sizeof (TipoNo) ) ;
        (*p)->Reg =  x;
        ( *p)->Esq =  NULL;
        ( *p)->Dir  =  NULL;
        return ;
    }
    if	( x.Chave <  (*p)->Reg.Chave)
    {
        Insere(x, &(*p)->Esq) ;
        return ;
    }
    if	( x.Chave >  (*p)->Reg.Chave)
        Insere(x, &(*p)->Dir ) ;
    else
        printf ( "Erro	:	Registro  ja	existe  na  arvore\n" ) ;
}

void  Pesquisa( TipoRegistro  *x,  TipoApontador *p)
{
    if  ( *p == NULL)
    {
        printf ( "Erro :	Registro  nao  esta  presente  na  arvore\n" ) ;
        return ;
    }
    if	( x->Chave <  (*p)->Reg.Chave)
    {
        Pesquisa(x, &(*p)->Esq) ;
        return ;
    }
    if	( x->Chave >  (*p)->Reg.Chave)
        Pesquisa(x, &(*p)->Dir ) ;
    else  *x  =  (*p)->Reg;
}

void  Antecessor(TipoApontador  q,  TipoApontador * r )
{
    if	(( * r)->Dir  !=  NULL)
    {
        Antecessor(q, &(* r)->Dir ) ;
        return ;
    }
    q->Reg =  (*r)->Reg;
    q = * r ;
    *r  =  (*r)->Esq;
    free (q);
}
void Retira(TipoRegistro x, TipoApontador *p)
{
    TipoApontador Aux;
    if (*p == NULL )
    {
        printf ( "Erro : Registro nao esta na arvore\n" ) ;
        return;
    }
    if (x.Chave < (*p)->Reg.Chave)
    {
        Retira(x, &(*p)->Esq) ;
        return;
    }
    if (x.Chave > (*p)->Reg.Chave)
    {
        Retira(x, &(*p)->Dir ) ;
        return;
    }
    if ( (*p)->Dir == NULL)
    {
        Aux = *p;
        *p = (*p)->Esq;
        free(Aux) ;
        return;
    }
    if ( (*p)->Esq != NULL )
    {
        Antecessor(*p, &(*p)->Esq) ;
        return;
    }
    Aux = *p;
    *p = (*p)->Dir ;
    free(Aux) ;
}

void Central (TipoApontador p)
{
    if (p == NULL)
        return;
    Central (p->Esq) ;
    printf ( "%ld \n", p->Reg.Chave) ;
    Central (p->Dir ) ;
}

int contafolha(TipoApontador p){

    if(p == NULL){
        return 0;
    }
    if(p->Dir == NULL && p->Esq == NULL){
        return 1;
    }

    return contafolha(p->Esq) + contafolha(p->Dir);

}

int arvoresiguais(TipoApontador p, TipoApontador q){

    if(p == NULL || q == NULL){
        return 0;
    }
    if(p->Reg.Chave == q->Reg.Chave){
        arvoresiguais(p->Dir,q->Dir);
        arvoresiguais(p->Esq,q->Esq);
        return 1;
    } //Se a função retornar 1 significa que todos os elementos da arvore binaria de busca p são iguais aos elementos da arvore binaria de busca q. Sendo assim, as arvores sao iguais;
    else {
        return 0;
    }   //Se a função retornar 0 significa que algum dos elementos das arvores binarias de buscas p e q são diferentes. Sendo assim, as arvores sao diferentes;

}


int main(){

        //Troquei os parâmetros com nome 'Dicionario' por 'raiz'
        TipoApontador raiz1;
        TipoApontador raiz2;
        TipoRegistro item;
        TipoRegistro item2;
        Inicializa(&raiz1);
        Inicializa(&raiz2);

        item.Chave=10;
        Insere(item,&raiz1);

        item.Chave=8;
        Insere(item,&raiz1);

        item.Chave=13;
        Insere(item,&raiz1);

        item.Chave=12;
        Insere(item,&raiz1);

        item2.Chave=10;
        Insere(item2,&raiz2);

        item2.Chave=8;
        Insere(item2,&raiz2);

        item2.Chave=13;
        Insere(item2,&raiz2);

        item2.Chave=12;
        Insere(item2,&raiz2);


        Central(raiz1);
        printf("Numero de nos folha: %d", contafolha(raiz1));
        printf("\n\n");
        Central(raiz2);
        printf("Numero de nos folha: %d", contafolha(raiz2));
        printf("\n\n%d",arvoresiguais(raiz1,raiz2));



}
