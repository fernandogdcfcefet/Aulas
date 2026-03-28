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

int verificaBinaria(Tree** t, contVerificador){
    Central(&(*t)->sae, cont);
    if(&(*t)->sae == NULL)
        cont++;
    Central(&(*t)->sad, cont);
     if(&(*t)->sae == NULL)
        cont--;

    return cont;
        /*IDEIA NA QUESTÃO: Se o filho da esquerda for nulo o contador soma 1, se o da direita
          também for nulo o contador diminui 1, logo o contador, ao final deve ter zero.
          A ideia fundamental é que se, por ventura, existir um filho de um lado não nulo e outro
          nulo do outro lado o contador ira retornar 1 ou -1, ou números maiores. Ideia similar ao
          teste feito para balancear uma AVL
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

    contVerificador = verificaBinaria(&t, contVerificador);
    return 0;
}

