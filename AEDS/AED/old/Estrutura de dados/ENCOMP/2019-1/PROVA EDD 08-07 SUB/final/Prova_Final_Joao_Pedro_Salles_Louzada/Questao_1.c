#include <stdio.h>
#include <stdlib.h>

#define num_materias 20
#define num_notas 20
#define tam_nome 20

typedef  int  TipoChave;
typedef  struct  { /**inclui nome e notas das materias*/
    TipoChave Chave;
    char nome[tam_nome];
    int notas[num_materias][num_notas];
    /*  outros  componentes  */
}  TipoItem;
typedef  struct  TipoCelula  *TipoApontador;
typedef  struct  TipoCelula  {
    TipoItem  Item;
    TipoApontador  Prox;
}  TipoCelula;

typedef  struct  {  /**inclui contador de tamanho*/
    TipoApontador  Primeiro ,  Ultimo;
    int tam;
}  TipoLista ;

void  FLVazia( TipoLista  * Lista )
{ 	Lista->Primeiro  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Primeiro ;
    Lista->Primeiro->Prox  =  NULL;
    Lista->tam = 0;    /**inclui contador de tamanho*/
}

int  Vazia( TipoLista  Lista )
{  return  ( Lista . Primeiro ==  Lista . Ultimo ) ;  }

void  Insere(TipoItem  x ,	TipoLista  * Lista )
{  	Lista->Ultimo->Prox  =  (TipoApontador)  malloc( sizeof ( TipoCelula ) ) ;
    Lista->Ultimo  =  Lista->Ultimo->Prox ;
    Lista->Ultimo->Item  =  x;
    Lista->Ultimo->Prox  =  NULL;
    Lista->tam++; /**acresce contador de tamanho*/
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

    Lista->tam--; /**decresce contador de tamanho*/
}

void imprime(TipoLista ML) {
    TipoApontador aux=ML.Primeiro->Prox;
    while(aux!=NULL) {
        printf("%d\n", aux->Item.Chave);
        aux=aux->Prox;
    }
}

/**=====================================================================================================================================================================================*/

void le_x_Notas_n_Alunos(TipoLista Alunos, int x, int n) {

    int i, j;
    int media = 0, contador = 0;
    float media_vet[( int) Alunos.tam-1];
    TipoApontador pont_aux = Alunos.Primeiro->Prox;
    while(Alunos.Primeiro->Prox != NULL) {   /** Percorre a lista de aluno calculando a media de cada aluno e guardando ordenadamente em um vetor de medias */

        for (i = 0; i < n-1; i++) {
            for (j = 0; j < x-1; j++) {
                media += Alunos.Primeiro->Item.notas[i][j];
            }
        }

        media_vet[contador] = (media/n);
        contador++;
        Alunos.Primeiro->Prox = Alunos.Primeiro->Prox->Prox;

    }

    int posicao_maior = 0;
    float valor = 0;
    for (i = 0; i < Alunos.tam-1; i++) {    /** Percorre o vetor de medias achando a posicao da maior media */
         if(media >= media_vet[(int) i]){
            valor = media_vet[i];
            posicao_maior = i;
         }
    }

    i = 0;
    int aux = 0;
    char ch = " ";

    while(pont_aux != NULL) {   /** Percorre novamente a lista de alunos, imprime as informações ao chegar na posição do maior e para */

        if(posicao_maior == aux){
            while(ch != "\0") {
                ch = Alunos.Primeiro->Item.nome[i];
                printf("%c", ch); i++;
            }
            puts("\n");
            printf("%d", media_vet[posicao_maior]);
            break;
        }

        pont_aux = pont_aux->Prox;
        aux++;
    }

}

void printarNotas(TipoLista Alunos){
    TipoApontador aux = Alunos.Primeiro.Prox;

    while(aux->Prox != NULL) {
        printf("%d", Alunos.Primeiro.Item.notas);
        aux->Prox = aux->Prox->Prox;
    }

}

/**=====================================================================================================================================================================================*/

int main()
{
    TipoLista Alunos;
    TipoItem al1 = { 1, "Aluno 1" };
    TipoItem al2 = { 2, "Aluno 2" };
    TipoItem al3 = { 3, "Aluno 3" };
    int i, j;
    FLVazia(&Alunos);

    for(i = 0; i < 10; i++) {       /** Inicializa a nota dos alunos, com a soma de i+j (apenas para efeito de demonstração)*/
        for(j = 0; j < 4; j++) {
            al1.notas[i][j] == (i+j);
        }
    }
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 4; j++) {
            al2.notas[i][j] == (i+j);
        }
    }
    for(i = 0; i < 10; i++) {
        for(j = 0; j < 4; j++) {
            al1.notas[i][j] == (i+j);
        }
    }

    Insere(al1, &Alunos);
    Insere(al2, &Alunos);
    Insere(al3, &Alunos);

    le_x_Notas_n_Alunos(Alunos, 4, 3);

    return 0;
}
