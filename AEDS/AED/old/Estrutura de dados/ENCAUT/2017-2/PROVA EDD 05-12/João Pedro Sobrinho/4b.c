#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

Tree* createTree()
{
    return NULL;
}

int treeIsEmpty(Tree* t)
{
    return t == NULL;
}

void insertTree(Tree** t, int num)
{
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
  } else {
    if(num < (*t)->num)
    {
      insertTree(&(*t)->sae, num);
    }
    if(num > (*t)->num)
    {
      insertTree(&(*t)->sad, num);
    }
  }
}

int trocaArvore(Tree** t){
    Central(&(*t)->sae);
    int aux = (*t)->num;
    (*t)->sae = (*t)->sad;
    (*t)->sad = aux;
    Central(&(*t)->sad);

    /*IDEIA PRINCIPAL: Percorre toda a árvore, pela esquerda, trocando os elementos da esquerda pelos da direita.
       Principio parecido com a troca de lugar de vetores no bubble sort. Faz a mesma coisa percorrendo a direita.
    */
}

int main()
{
    Tree* t = createTree();
    insertTree(&t, 4);
    insertTree(&t, 2);
    insertTree(&t, 6);
    insertTree(&t, 1);
    insertTree(&t, 3);
    insertTree(&t, 5);
    insertTree(&t, 10);
    insertTree(&t, 8);

    trocaArvore(&t);
    return 0;
}

