#include <stdio.h>
#include <stdlib.h>

typedef  long  TipoChave;

typedef  struct  TipoRegistro
{
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoRegistro;
typedef  struct  TipoNo  * TipoApontador;

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
        printf ( "Erro : Registro  nao  esta  presente  na  arvore\n" ) ;
        return ;
    }
    if	( x->Chave <  (*p)->Reg.Chave)
    {
        Pesquisa(x, &(*p)->Esq) ;
        return ;
    }
    if	( x->Chave >  (*p)->Reg.Chave)
        Pesquisa(x, &(*p)->Dir ) ;
    else *x  =  (*p)->Reg;
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
    Central (p->Esq);
    printf ( "%ld \n", p->Reg.Chave) ;
    Central (p->Dir );
}

int QtdFolha(TipoApontador p){ // Questao 1, letra C.

    if(p != NULL){

        if((p->Dir != NULL)||(p->Esq != NULL)){
            return(QtdFolha(p->Dir) + QtdFolha(p->Esq));
        }
        if((p->Dir == NULL)&&(p->Esq == NULL)){
            return 1;
        }
    }
}

int ArvIguais(TipoApontador p1, TipoApontador p2){ //Questao 1, letra a.

    if((p1 != NULL)&&(p2 != NULL)){
        if(p1->Reg.Chave == p2->Reg.Chave){
            return(ArvIguais(p1->Esq, p2->Esq) + ArvIguais(p1->Dir, p2->Dir));//Teria que testar se é um no folha, dai, nao chamaria a dir.
        }else{
            return 1; //Se nao forem iguais, retorna 1.
        }
    }
}

void CalcMed(TipoApontador p){ //Questao 1, letra b.
//Passar a arvore para um vetor, ver qual seria o elemento do meio e retornar a chave desse elemento. Dai,com a chave, retira o elemento de uma arvore e insere na outra.

    if(p != NULL){

    }
}

int main(){

    TipoApontador raiz;
    Inicializa(&raiz);
    TipoRegistro reg;

    reg.Chave = 6;
    Insere(reg,&raiz);
    reg.Chave = 9;
    Insere(reg,&raiz);
    reg.Chave = 3;
    Insere(reg,&raiz);
    reg.Chave = 7;
    Insere(reg,&raiz);
    reg.Chave = 4;
    Insere(reg,&raiz);
    reg.Chave = 2;
    Insere(reg,&raiz);

    TipoApontador raiz1;
    Inicializa(&raiz1);
    TipoRegistro reg1;

    reg1.Chave = 6;
    Insere(reg1,&raiz1);
    reg1.Chave = 9;
    Insere(reg1,&raiz1);
    reg1.Chave = 10;
    Insere(reg1,&raiz1);
    reg1.Chave = 7;
    Insere(reg1,&raiz1);
    reg1.Chave = 4;
    Insere(reg1,&raiz1);
    reg1.Chave = 2;
    Insere(reg1,&raiz1);

    printf("\nQuantidade de no folha: %d\n",QtdFolha(raiz));

    if(ArvIguais(raiz, raiz1) == 1){
        printf("\nAs arvores nao sao iguais\n");
    }else{
        printf("\nAs arvores sao iguais\n");
    }
}
