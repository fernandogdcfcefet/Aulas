#include <stdio.h>
#include <stdlib.h>

typedef long TipoChave;

typedef struct TipoRegistro
{
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoRegistro;

typedef struct TipoNo *TipoApontador;

typedef struct TipoNo
{
    TipoRegistro Reg;
    TipoApontador Esq, Dir;
}TipoNo;

void  Inicializa(TipoApontador *Dicionario)
{
    *Dicionario = NULL;
}

void Insere(TipoRegistro x, TipoApontador *p)
{
    if(*p== NULL)
    {
        *p = (TipoApontador)malloc( sizeof (TipoNo));
        (*p)->Reg =  x;
        ( *p)->Esq =  NULL;
        ( *p)->Dir = NULL;
        return;
    }
    if(x.Chave<(*p)->Reg.Chave)
    {
        Insere(x, &(*p)->Esq) ;
        return ;
    }
    if(x.Chave>(*p)->Reg.Chave)
        Insere(x, &(*p)->Dir) ;
    else
        printf ("Erro: Registro  ja	existe  na  arvore\n");
}

void Pesquisa(TipoRegistro *x,  TipoApontador *p)
{
    if(*p == NULL)
    {
        printf("Erro: Registro  nao  esta  presente  na  arvore\n");
        return ;
    }
    if(x->Chave < (*p)->Reg.Chave)
    {
        Pesquisa(x, &(*p)->Esq) ;
        return ;
    }
    if(x->Chave >  (*p)->Reg.Chave)
        Pesquisa(x, &(*p)->Dir ) ;
    else  
		*x  =  (*p)->Reg;
}

void Antecessor(TipoApontador q, TipoApontador *r)
{
    if((* r)->Dir != NULL)
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

int numeroFolhas(TipoApontador p){ //Questão 1-C
	int dir, esq;
	
	if(p==NULL)
		return 0;
	if(p->Dir==NULL && p->Esq==NULL)
		return 1;
	dir = numeroFolhas(p->Dir);
	esq = numeroFolhas(p->Esq);
	return dir+esq;
}

int comparaArvores(TipoApontador p, TipoApontador q){
	int dir=0, esq=0;
	
	if(p==NULL && q==NULL)
		return 0;
	if(p->Dir==NULL && p->Esq== NULL && q->Dir==NULL && q->Esq==NULL){
		if(p->Reg.Chave==q->Reg.Chave)
			return 1;
		else
			return 0;
	}
	else{
		dir = comparaArvores(p->Dir, q->Dir);
		esq = comparaArvores(p->Esq, q->Esq);
		//printf("%d\t%d\n", dir, esq);
	}
	return dir+esq;
}

int main()
{
	TipoApontador raiz, raiz2;
	TipoRegistro x;
	int y;
	
	Inicializa(&raiz);
	x.Chave = 8;
	Insere(x,&raiz);
	x.Chave = 7;
	Insere(x,&raiz);
	x.Chave = 12;
	Insere(x,&raiz);
	x.Chave = 5;
	Insere(x,&raiz);
	x.Chave = 6;
	Insere(x,&raiz);
	x.Chave = 10;
	Insere(x,&raiz);
	x.Chave = 11;
	Insere(x,&raiz);
	x.Chave = 13;
	Insere(x,&raiz);
	x.Chave = 4;
	Insere(x,&raiz);
	Central(raiz);
	printf("O numero de folhas na arvore eh: %d\n", numeroFolhas(raiz)); //Chamada da questão 1-C
	
	//Questão 1-A
	
	Inicializa(&raiz2);
	x.Chave = 8;
	Insere(x,&raiz2);
	x.Chave = 7;
	Insere(x,&raiz2);
	x.Chave = 12;
	Insere(x,&raiz2);
	x.Chave = 5;
	Insere(x,&raiz2);
	x.Chave = 6;
	Insere(x,&raiz2);
	x.Chave = 10;
	Insere(x,&raiz2);
	x.Chave = 11;
	Insere(x,&raiz2);
	x.Chave = 13;
	Insere(x,&raiz2);
	x.Chave = 4;
	Insere(x,&raiz2);
	y = comparaArvores(raiz,raiz2);
	if(y%2 == 0)
		printf("As arvores sao iguais\n");
	else
		printf("As arvores sao diferentes\n");
	return 0;
}
