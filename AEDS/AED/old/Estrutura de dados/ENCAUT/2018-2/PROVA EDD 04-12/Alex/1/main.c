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

int altura(TipoApontador p){
    int dir,esq;
    if (p == NULL)
        return 1;
    esq = altura (p->Esq) ;
    dir = altura (p->Dir) ;
    if(dir>esq) return dir+1;
    else return esq+1;
}

int contaFolhas(TipoApontador p){
    int dir,esq;
    if (p == NULL)
        return 1;
    esq = contaFolhas (p->Esq) ;
    dir = contaFolhas (p->Dir) ;
    return dir+esq;
}

int iguais(TipoApontador p, TipoApontador q){
    int ap,aq; //altura de p e q;
    ap=altura(p);
    aq=altura(q);
    if(ap!=aq){
        return 0;
    }
    if (p == NULL)
        return 1;
    iguais (p->Esq,q->Esq);
    iguais (p->Dir,q->Dir);
}

int contaNOS (TipoApontador p){
    int dir,esq,nos=0;
    if (p == NULL)
        return;
    esq = contaNOS (p->Esq) ;
    nos++;
    dir = contaNOS (p->Dir) ;
}

TipoChave mediana(TipoApontador p){

}

TipoApontador contruirABB (TipoApontador p){

}

int main(){
    TipoApontador p,q;
    Inicializa(&p);
    Inicializa(&q);
    TipoRegistro R;
    R.Chave=6;
    Insere(R,&p);
    Insere(R,&q);
    R.Chave=4;
    Insere(R,&p);
    Insere(R,&q);
    /*R.Chave=2;
    Insere(R,&p);
    Insere(R,&q);
    R.Chave=7;
    Insere(R,&p);
    Insere(R,&q);
    R.Chave=5;
    Insere(R,&p);
    Insere(R,&q);
    R.Chave=1;
    Insere(R,&q);
    Central(p);*/
    printf("\n\n");
    Central(p);

    if(iguais(p,q)==1) printf("Arvores sao iguais\n\n");
    else printf("Arvores nao sao iguais\n\n");

    printf("\nFolhas na arvore: %d\n",contaFolhas(p));
}
