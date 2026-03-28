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


bool estritamenteBinaria (Tree* t){
	if (!treeIsEmpty(t)){
	estritamenteBinaria (t->sae);
	if ((t->sad == NULL) && (t->sae != NULL)){
			return false;
	}
	if ((t->sae == NULL) && (t->sad != NULL)) {
			return false;
	}
	if (((t->sae == NULL) && (t->sad == NULL)) || ((t->sae != NULL) && (t->sad != NULL))){
		return true;
	}
	estritamenteBinaria(t->sad);
	}
}


void imprime (Tree* t){
	if (!treeIsEmpty(t)){
		imprime (t->sae);
		printf(" %d ", t->num);
		imprime (t->sad);
	}
}

int main()
{
    Tree* t = createTree();
    insertTree(&t, 12);
    insertTree(&t, 15);
    insertTree(&t, 10);


    imprime(t);

	if (estritamenteBinaria(t) == true) printf ("\n e uma arvore estritamente binaria\n");
    else printf ("\n n e uma arvore estritamente binaria \n");

    return 0;
}
