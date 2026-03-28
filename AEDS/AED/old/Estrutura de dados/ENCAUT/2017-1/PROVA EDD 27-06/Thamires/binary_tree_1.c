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



void caminhamentocentral(Tree *t)

{
	if(!treeIsEmpty(t))
	{
		caminhamentocentral(t->sad);
		printf("%d ", t->num);
		caminhamentocentral(t->sae);	
	}
}


void arvorebusca(Tree *t)
{
	if(!treeIsEmpty(t))
	{
		if(t->sad > t->sae)
		{
			return 1;
		}
		
		else 
		return 0;
	
	}
	
}

void estritamentebinaria(Tree *t)
{
	
	if(!treeIsEmpty(t))
	{
		if(t->sad!=NULL && t->sae!=NULL)
		{
			return 1;
		}
		else
		return 0;
	
	}
	
}

void espelha(Tree *t)
{
	int aux;
	
	aux=t->sad;
	t->sad=t->sae;
	t->sae=aux;

}



int main()
{
	Tree *t = createTree();
	insertTree(&t,12);
	insertTree(&t,15);
	insertTree(&t,8);
	
	caminhamentocentral(t);
	
	arvorebusca(t);
	estritamentebinaria(t);
	
    return 0;
}
