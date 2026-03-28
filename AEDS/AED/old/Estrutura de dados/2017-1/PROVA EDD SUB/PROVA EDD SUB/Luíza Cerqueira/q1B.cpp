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


Tree espelho (Tree* t){
	int aux=NULL;
	if (!treeIsEmpty(t)){
		aux = t->sad->num;
		t->sad->num = t->sae->num;
		t->sae->num = aux;
		return *t;
		espelho(t->sae);
		espelho(t->sad);
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
    insertTree(&t, 13);

    imprime(t);
    printf("\n");
    espelho(t);
    imprime(t);



    return 0;
}
