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

bool arvoreBusca (Tree* t){
	if (!treeIsEmpty(t)){
		arvoreBusca (t->sae);
		if ((t->sad == NULL) && (t->sae != NULL)){
			if ((t->sae->num) < (t->num)){
				return true;
			}
		}
		if ((t->sae == NULL) && (t->sad != NULL)) {
			if ((t->sad->num) > (t->num)){
				return true;
			}
		}
		if ((t->sae == NULL) && (t->sad == NULL)){
			return true;
		}
		if ((t->sae != NULL) && (t->sad != NULL)){
			if (((t->sad->num) > (t->num)) && ((t->sae->num) < (t->num))){
				return true;
			}
			else return false;
		}
		arvoreBusca(t->sad);

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

    if (arvoreBusca(t) == true) printf ("\n e uma arvore de busca \n");
    else printf ("\n n e uma arvore de busca \n");

    return 0;
}
