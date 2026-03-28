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

int comparaArvore(TipoApontador av1, TipoApontador av2) {
    // retorna 1 igual, 0 diferente

    int esq, dir;

    if (av1 == NULL || av2 == NULL)
        return 0;


    esq = comparaArvore(av1->Esq, av2->Esq);
    if(av1->Reg.Chave != av2->Reg.Chave) {
        return 0;
    } else {
        return 1;
    }
    dir = comparaArvore(av1->Dir, av2->Dir);


    return dir+esq;

}


int qtdFolhas (TipoApontador p) {
    int esq, dir;

    if (p == NULL) {
        return 0;
    }

    esq = qtdFolhas(p->Esq);

    // confere se nao tem filhos
    if (p->Esq == NULL && p->Dir == NULL) {
        return 1;
    }

    dir = qtdFolhas(p->Dir);

    // retorna quantidade de folhas da esquerda + da direita
    return esq + dir;

}

int main()
{

    TipoApontador raiz, raiz2;
    TipoRegistro item;
    Inicializa(&raiz);
    Inicializa(&raiz2);

    // Inserção Arvore 1 -> 3, 4, 5, 2, 1, 7, 6
    item.Chave = 3;
    Insere(item, &raiz);
    item.Chave = 4;
    Insere(item, &raiz);
    item.Chave = 5;
    Insere(item, &raiz);
    item.Chave = 2;
    Insere(item, &raiz);

    // Inserção Arvore 2
    item.Chave = 2;
    Insere(item, &raiz2);
    item.Chave = 4;
    Insere(item, &raiz2);
    item.Chave = 5;
    Insere(item, &raiz2);
    item.Chave = 6;
    Insere(item, &raiz2);


    printf("Arovres sao iguais: %d", comparaArvore(raiz, raiz2)); // 1 verdadeiro, 0 falso
    printf("\nFolhas: %d", qtdFolhas(raiz));

}
