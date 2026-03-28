#include <stdio.h>
#include <stdlib.h>

# define N  2
# define X  2
typedef  int  TipoChave;

typedef struct{
	char nome[50];
	int matricula;
	float nota[X];
	
} Aluno;
void Cadastro(Aluno aluno){


for(int i=0; i<N;i++){
	printf("digite o nome do aluno");
	scanf("%s",&aluno.nome[i);
	printf("digite a matricula do aluno");
	scanf("%d",&aluno.matricula[i]);
}
}

float Media(Aluno aluno, Aluno aluno2){
	int i=0;
	int j=0;
	for(i=0;i<N;i++){
		printf(" digite a nota do primeiro aluno");
		scanf("%f",&aluno.nota[i]);
			float media1= (aluno.nota[i] + aluno.nota[i+1])/X;
	          return media1;
	}
	
		for(j=0;j<N;j++){
			printf(" digite a nota do segundo aluno");
			scanf("%f",&aluno2.nota[j]);
			
				float media2=(aluno2.nota[j]+aluno2.nota[j+1])/x;
		         return media2;
		}
		
		if(media1>media2){
			printf(" %s",aluno.nome);
		}
		
		else{
			printf("%s",aluno2.nome);
		}
	
}


typedef  struct  {
    TipoChave Chave;
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {
    TipoApontador  Primeiro ,  Ultimo;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
}

void  Retira(TipoApontador  p,	TipoLista  *Lista ,  TipoItem  *Item)
{	/*--O item  a  ser  retirado  e  o  seguinte  ao  apontado  por  p--*/
    TipoApontador  q;
    if ( Vazia(*Lista )	||	p == NULL	||	p->Prox == NULL){
        printf ( "  Erro : Lista  vazia  ou  posicao  nao  existe \n" ) ;
    return ;
}
    q =  p->Prox;  *Item  =  q->Item ;
    p->Prox  =  q->Prox ;
    if ( p->Prox == NULL )  Lista->Ultimo  = p;
    free (q);
}

void imprime(TipoLista ML){
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL){
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

int main()
{

    return 0;
}
