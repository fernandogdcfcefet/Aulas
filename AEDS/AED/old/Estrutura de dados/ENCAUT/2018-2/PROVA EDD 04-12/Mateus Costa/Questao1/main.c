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

void  Inicializa (TipoApontador *Dicionario)
{
    * Dicionario  =  NULL ;
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
int quantFolhas(TipoApontador p)
{
    int dir=0,esq=0;

    if (p == NULL)
        return 0;


    if (p->Dir == NULL)
        dir=quantFolhas(p->Dir);

   quantFolhas(p->Esq);
    if (p->Esq == NULL)
        esq=quantFolhas(p->Esq);

return dir+esq+4;

}

int main()
{
    TipoApontador raiz;
    Inicializa(&raiz);
    TipoRegistro item;

    item.Chave=4;
    Insere(item,&raiz);
    item.Chave=6;
    Insere(item,&raiz);
    item.Chave=2;
    Insere(item,&raiz);
    item.Chave=3;
    Insere(item,&raiz);
    item.Chave=1;
    Insere(item,&raiz);
    item.Chave=7;
    Insere(item,&raiz);
    item.Chave=5;
    Insere(item,&raiz);
    Central(raiz);


    printf("o numero de folhas sao: \n%d",quantFolhas(raiz));
}
