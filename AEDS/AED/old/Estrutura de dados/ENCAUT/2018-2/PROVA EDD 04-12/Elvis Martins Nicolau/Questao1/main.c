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
int Conta(TipoApontador p)
{
    if(p == NULL)
        return 0;
    else return 1;
}

int ComparaEstrutura(TipoApontador p1,TipoApontador p2) // aletra a consiste em três funcções: Conta, ComparaEstrutura e ComparaArvore. Porque duas arvorês de busca são iguais quando suas estruturas são iaguais
{                                                       //entaõ a cada no que se passa e estivesse ocupado, vai retorna o vlaor de um, se o valor que retorna tanto da arvore um e dois forem iguais significa que a estrutura até ali é igual
    int aux1,aux2;                                      // fazendo o código prosseguir

    if(Conta(p1) == Conta(p2))
    {
        aux1 = ComparaEstrutura(p1->Esq,p2->Esq);
        aux2 = ComparaEstrutura(p1->Dir,p2->Dir);
        if(aux1 == aux2) return 1;
        else  return 0;
    }
    else return 0;
}

void ComparaArvore(TipoApontador p1,TipoApontador p2)
{
    if(ComparaEstrutura(p1,p2) == 0) printf("Nao sao iguais!\n");
    else printf("Sao iguais!\n");
}


int ContaFolha(TipoApontador p) // letra c. Duas variáveis irão acumular os valores da folhas, sabendo que a cararcterísticas das folhas é estar apontando para duas casas nulas, toda ve que tiver essa característica acrescentará um nas variáveis
{
    int esq,dir;
    if (p == NULL)
        return 0;
    if(p->Esq == NULL && p->Dir == NULL)
        return 1;
     esq = ContaFolha(p->Esq) ;
     dir = ContaFolha(p->Dir) ;
     return esq+dir;
}

int main()
{
    TipoApontador raiz;
    TipoRegistro item;
    int contador;

    Inicializa(&raiz);

    item.Chave = 20; Insere(item,&raiz);
    item.Chave = 10; Insere(item,&raiz);
    item.Chave = 30; Insere(item,&raiz);

    Central(raiz);
    printf("\n\n");
    contador = ContaFolha(raiz);
    printf("%d\n",contador);

    return 0;
}
