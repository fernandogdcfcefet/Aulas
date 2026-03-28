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

int verificaArvoredeBusca(Tree** t, contVerificador){
    /*IDEIA FUNDAMENTAL: Cálcula o tamanho da árvore. Percorre toda a árvore e verifica seu tamanho, se seu tamanho for
      igual ao lado percorrido, quer dizer que a árvore é uma fila, pois o lado é onde está toda árvore.
    */
}

int main()
{
    int contVerificador = 0;
    Tree* t = createTree();
    insertTree(&t, 4);
    insertTree(&t, 2);
    insertTree(&t, 6);
    insertTree(&t, 1);
    insertTree(&t, 3);
    insertTree(&t, 5);
    insertTree(&t, 10);
    insertTree(&t, 8);

    verificaArvoredeBusca(&t, contVerificador);
    return 0;
}

