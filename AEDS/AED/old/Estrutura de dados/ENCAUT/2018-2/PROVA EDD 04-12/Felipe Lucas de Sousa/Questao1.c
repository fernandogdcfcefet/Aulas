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

/*	Funções referentes ao número 1 letra a

	Com a função NumeroElementos() eu verifico se as arvores em o mesmo número de elementos, caso não elas já não são iguais
	então eu retorno 1, caso elas tenham o mesmo número de elemntos eu entro na recursividade para percorrer cada nó da árvore
	caso em algum nó o valor da chave não seja igual, vai retornar 1.
	Ou seja, para arvores iguais retorna 0, e para árvores diferentes retorna 1;
*/
int NumeroElementos(TipoApontador p){
	if(p!=NULL){
		return(NumeroElementos(p->Esq) + 1 +NumeroElementos(p->Dir));
	}else{
		return 0;
	}
}
int ComparaArvores(TipoApontador a, TipoApontador b){
	if(NumeroElementos(a)!=NumeroElementos(b)){
		return 1;
	}else{
		if((a!=NULL)&&(b!=NULL)){
		ComparaArvores(a->Esq, b->Esq);
		if(a->Reg.Chave != b->Reg.Chave){
			return 1;
		}
		ComparaArvores(a->Dir, b->Dir);
		}else{
			return 0;
		}	
	}
}

/*	Função referente ao número 1 letra c

	Nessa função conforme a arvore vai sendo percorrida, é feito um teste "if((p->Dir==NULL)&&(p->Esq==NULL))", aqui 
	é testado se os filhos desse nó são nulos retornando, conforme a recursão evoluindo é somado +1 cada vez um nó folha 
	é encontrado.
*/
int NumeroFolhas (TipoApontador p){
	if(p!=NULL){
		if((p->Dir==NULL)&&(p->Esq==NULL)){
			return 1;
		}else{
			return (NumeroFolhas(p->Esq) + NumeroFolhas(p->Dir));
		}
	}else{
		return 0;
	}
}

/* Funções referentes ao número 1 letra b

	A ideia era a seguinte, na função balanceia iria ser formada uma árvore do mesmo tamanho devido ao for, e cada
	volta desse for, iria inserir um novo valor da mediana na arvore, e retirar o mesmo da arvore original para não 
	interferir nos próximos cálculos de mediana.
	
	Não consegui implementar a função mediana para Arvore
	
*/

int Mediana(TipoApontador p){
	
}

void Balanceia(TipoApontador a, TipoApontador b){
	int i;
	TipoRegistro aux;
	
	for(i=0; i<NumeroElementos(a); i++){
		aux.Chave = Mediana(a);
		Insere(aux, &b);
		Retira(aux, &a);	
	}
}

void main(){
	TipoApontador raiz, raiz2;
	Inicializa(&raiz);
	Inicializa(&raiz2);
	TipoRegistro registro;
	
	registro.Chave = 3;
	Insere(registro,&raiz);
	registro.Chave = 4;
	Insere(registro,&raiz);
	registro.Chave = 5;
	Insere(registro,&raiz);
	registro.Chave = 2;
	Insere(registro,&raiz);
	registro.Chave = 1;
	Insere(registro,&raiz);
	registro.Chave = 7;
	Insere(registro,&raiz);
	registro.Chave = 6;
	Insere(registro,&raiz);
	registro.Chave = 9;
	Insere(registro,&raiz);
	registro.Chave = 8;
	Insere(registro,&raiz);
	registro.Chave =10;
	Insere(registro,&raiz);
	
	registro.Chave = 3;
	Insere(registro,&raiz2);
	registro.Chave = 4;
	Insere(registro,&raiz2);
	registro.Chave = 5;
	Insere(registro,&raiz2);
	registro.Chave = 2;
	Insere(registro,&raiz2);
	registro.Chave = 1;
	Insere(registro,&raiz2);
	registro.Chave = 7;
	Insere(registro,&raiz2);
	registro.Chave = 6;
	Insere(registro,&raiz2);
	registro.Chave = 9;
	Insere(registro,&raiz2);
	registro.Chave = 8;
	Insere(registro,&raiz2);
	registro.Chave =10;
	Insere(registro,&raiz2);
	
	//Central(raiz);
	
	//Letra A
	ComparaArvores(raiz,raiz2)==0 ? printf("Letra A: As árvores são iguais.\n") : printf("Letra A: As árvores não são iguais.\n");
	
	//Letra B
	/* Implementação acima*/
	
	//Letra C
	printf("Letra C: Número de folhas: %d \n",NumeroFolhas(raiz));
	
	

	
	
}
