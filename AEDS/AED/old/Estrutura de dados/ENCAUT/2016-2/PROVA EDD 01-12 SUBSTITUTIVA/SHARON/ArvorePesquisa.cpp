

/* Implementação de árvore binária */

#include <stdio.h>
#include <stdlib.h>

/* Cada nó armazena três informações:
   nesse caso um número (num),
   ponteiro para subárvore à direita (sad)
   e ponteiro para subárvore à esquerda (sae).*/
typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
Tree* createTree()
{
  /* Uma árvore é representada pelo endereço do nó raiz,
     essa função cria uma árvore com nenhum elemento,
     ou seja, cria uma árvore vazia, por isso retorna NULL. */
  return NULL;
}

/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Tree* t)
{
  /* Retorna 1 se a árvore for vazia e 0 caso contrário */
  return t == NULL;

}

/* Função que mostra a informação da árvore */
void caminhamentoCentral(Tree* t)
{
  /* Essa função imprime os elementos de forma recursiva */

//  printf("<"); /* notação para organizar na hora de mostrar os elementos */
  if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
  {
    /* Mostra os elementos com caminhamento central*/
    caminhamentoCentral(t->sae); /* mostra a sae (subárvore à esquerda) */
    printf("%d ", t->num); /* mostra a raiz */
    caminhamentoCentral(t->sad); /* mostra a sad (subárvore à direita) */
  }
//  printf(">"); /* notação para organizar na hora de mostrar os elementos */
}

/* Função que insere um dado na árvore */
void insertTree(Tree** t, int num)
{
  /* Essa função insere os elementos de forma recursiva */
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree)); /* Aloca memória para a estrutura */
    (*t)->sae = NULL; /* Subárvore à esquerda é NULL */
    (*t)->sad = NULL; /* Subárvore à direita é NULL */
    (*t)->num = num; /* Armazena a informação */
  } else {
    if(num < (*t)->num) /* Se o número for menor então vai pra esquerda */
    {
      /* Percorre pela subárvore à esquerda */
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num) /* Se o número for maior então vai pra direita */
    {
      /* Percorre pela subárvore à direita */
      insertTree(&(*t)->sad, num);
    }
  }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInTree(Tree* t, int num) {

  if(treeIsEmpty(t)) { /* Se a árvore estiver vazia, então retorna 0 */
    return 0;
  }

  /* O operador lógico || interrompe a busca quando o elemento for encontrado */
  return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

/* Função para liberar a memória alocada pela árvore */
Tree* freeTree(Tree** t)
{
  /* Essa função também usa implementação recursiva */
  if(!treeIsEmpty(*t)) /* se a árvore não for vazia... */
  {
    /* Tem que liberar as subárvores primeiro para que o acesso
       não seja perdido. */
    freeTree(&(*t)->sae); /* libera a subárvore à esquerda */
//    t->sae=NULL;
    freeTree(&(*t)->sad); /* libera a subárvore à direita */
//    t->sad=NULL;
    free(*t);
//    (*t)=NULL;
//t->sae=NULL;
//t->sad=NULL;
//printf("%d ",t->num);
//    freeTree(t); /* libera a raiz */
  }

  /* Retorna uma árvore vazia, ou seja, NULL */
  return NULL;
}

void ArvoredePesquisa(Tree *t)
{
  int aux;
  
    while(t->num != NULL)
	{
		ArvoredePesquisa(t->sae);	
		ArvoredePesquisa(t->sad);
		
		if(t->num > t->sad->num && t->num > t->sae->num) aux=0;
		else aux++;
	}
	if(aux==0) printf("BINARIA DE BUSCA");
else printf("nao binaria de busca");
}


	


int main()
{
  Tree* t = createTree(); /* cria uma árvore */

  insertTree(&t, 12); /* insere o elemento 12 na árvore */
  insertTree(&t, 5); /* insere o elemento 15 na árvore */
  insertTree(&t, 10); /* insere o elemento 10 na árvore */
  insertTree(&t, 3); /* insere o elemento 13 na árvore */
  
 ArvoredePesquisa(t);

  system("pause");
  return 0;

}

