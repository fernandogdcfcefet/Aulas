#include <stdio.h>
#include <stdlib.h>

typedef  long  TipoChave;

typedef  struct  TipoRegistro
{
    TipoChave Chave;
    int Tamanho;
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
    (*p)->Reg.Tamanho++;
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

void Central(TipoApontador p)
{
    if (p == NULL)
        return;
    Central (p->Esq) ;
    printf ( "%ld \n", p->Reg.Chave) ;
    Central (p->Dir ) ;
}

int ContaFolha(TipoApontador p)
{
    if (p == NULL)
        return 0;
    if(p->Dir==NULL && p->Esq==NULL) //condicao para ser no folha
        return 1;
    return ContaFolha(p->Dir) + ContaFolha(p->Esq);
}

int RetornaChave(TipoApontador p)
{
    //Funcao criada para retornar a chave do registro solicitado
    if (p == NULL)
        return 0;
    else return p->Reg.Chave;
}

int Compara(TipoApontador p, TipoApontador q)
{
    if (p == NULL)
        return 0;
    if(RetornaChave(p->Dir) == RetornaChave(q->Dir)){ //chamando a funcao RetornaChave para poder comparar cada chave
        return 1; //retorna 1,caso for verdadeiro. No main, se for maior que 0, são iguais.
    }
    else return 0;
    if(RetornaChave(p->Esq) == RetornaChave(q->Esq)){
        return 1; //Retorna 1,caso for verdadeiro. No main, se for maior que 0, são iguais.
    }
    else return 0;
}

/*int Soma(TipoApontador p)
{
    int i=0,cont=0;
    TipoRegistro item[p->Reg.Tamanho];
    if (p == NULL)
        return 0;
    Soma(p->Esq);
    Soma(p->Dir);
    item[i].Chave = RetornaChave(p);
    cont += item[i].Chave;
    i++;
    return cont;
}*/

/*void ConstruirArvore(TipoApontador p)
{
    if (p == NULL)
        return 0;
    ConstruirArvore(p->Esq);
    ConstruirArvore(p->Dir);
}*/


int main()
{
    TipoApontador raiz1, raiz2;
    TipoRegistro Item;
    Inicializa(&raiz1);
    Item.Chave = 20; Insere(Item,&raiz1);
    Item.Chave = 25; Insere(Item,&raiz1);
    Item.Chave = 19; Insere(Item,&raiz1);
    Inicializa(&raiz2);
    Item.Chave = 20; Insere(Item,&raiz2);
    Item.Chave = 24; Insere(Item,&raiz2);
    Item.Chave = 18; Insere(Item,&raiz2);
    printf("A arvore possui %d nos folhas\n\n", ContaFolha(raiz1));
    if(Compara(raiz1,raiz2)!=0)
        printf("As arvores sao iguais.");
    else
        printf("As arvores nao sao iguais.");
    return 0;
}
