#include <stdio.h>
#include <stdlib.h>
#include<conio.h>

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

int EstritamenteBinaria(Tree* t) // 1 ou mais de 1 para sim e 0 para nao
{
	
	//if(treeIsEmpty(t)) return 1;
	
	if(t->sad == NULL && t->sae == NULL)  return 0;
	
	if((t->sad == NULL && t->sae != NULL) || (t->sae == NULL && t->sad != NULL)) return 1;
	
	else return EstritamenteBinaria(t->sad) + EstritamenteBinaria(t->sae);
			
}

int main()
{
	Tree* t;
	createTree;
	treeIsEmpty(t);
	
	int a=6;
	insertTree(&t,6);
	insertTree(&t,4);
	printf("%d",EstritamenteBinaria(t));
	insertTree(&t,8);
	printf("%d",EstritamenteBinaria(t));
	getch();
    return 0;
}
