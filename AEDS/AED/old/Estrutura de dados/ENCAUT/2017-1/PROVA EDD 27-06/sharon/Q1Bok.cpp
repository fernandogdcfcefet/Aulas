#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

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

void Espelhar(Tree* t)
{
	if(t->num != NULL)
	{	

		if(t->sad != NULL)
		{	
			printf("%d", t->sad->num);
			Espelhar(t->sad);
		}
	 	printf("%d", t->num);
	 	
		if(t->sae != NULL)
		{
			printf("%d", t->sae->num);
			Espelhar(t->sae);
		}
	}
	else printf("-");
}

int main()
{
	Tree* t;
	treeIsEmpty(t);
	
	
	insertTree(&t,2);
	insertTree(&t,1);
	insertTree(&t,3);
	Espelhar(t);
	getch();
    return 0;
}
