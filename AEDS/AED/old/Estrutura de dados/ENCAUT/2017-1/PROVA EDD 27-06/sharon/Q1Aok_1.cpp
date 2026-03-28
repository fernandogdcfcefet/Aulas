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



int ArvoreDeBusca(Tree* t) // 0 para sim e 1 ou mais de 1 para nao
{
	//if(treeIsEmpty(t)) return 1;
	
	if(t->sad == NULL && t->sae == NULL)  return 0;
	
	if(t->sad->num < t->num || t->sae->num > t->num) return 1;
	
	else return  ArvoreDeBusca(t->sad) + ArvoreDeBusca(t->sae);
	
}

int main()
{
	Tree* t;
	createTree;
	treeIsEmpty(t);
	

	insertTree(&t,6);
	insertTree(&t,4);
	printf("%d",ArvoreDeBusca(t));
	insertTree(&t,8);
	printf("%d",ArvoreDeBusca(t));
	
	getch();
    return 0;
}
