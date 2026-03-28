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

// QUESTÃO 1 - LETRA A
int verificaIguais(TipoNo* a, TipoNo* b)
{
    /* O algorítimo percorre todas as posições da árvore. Se alguma posição do nó estiver diferente da outra, a função irá retonar o 0, mostrando que as árvores
    não são iguais. Caso contrário, quando não houver mais posições para se percorrer na árvore, a função irá retornar o 1. */
    if(a->Reg.Chave == NULL && b->Reg.Chave == NULL)
    {
        return 1; // RETORNAR O 1 = SÃO IGUAIS
    } else if(a->Reg.Chave == b->Reg.Chave) {
        printf("%d",verificaIguais(a->Esq,b->Esq));
        return verificaIguais(a->Dir,b->Dir);

    } else {
        return 0; // RETORNAR O 0 = NÃO SÃO IGUAIS
    }
}

// QUESTÃO 1 - LETRA A
void  quantFolhas( TipoRegistro  *x,  TipoApontador *p,quantidade)
{
    /* Pro algorímo funcionar perfeitamente, é necessário que no main, o parâmetro quantidade seja inicializado como 0*/
    int quantidade;

    if  ( *p == NULL)
    {
        printf ( "Erro :	Registro  nao  esta  presente  na  arvore\n" ) ;
        return ;
    }
    if	( x->Chave <  (*p)->Reg.Chave)
    {
        Pesquisa(x, &(*p)->Esq,quantidade +1) ;
        return ;
    }
    if	( x->Chave >  (*p)->Reg.Chave)
        Pesquisa(x, &(*p)->Dir ,quantidade +1) ;
    else  *x  =  (*p)->Reg;

    printf("QUANTIDADE DE FOLHAS: %i", &quantidade);
}

int main()
{
}
