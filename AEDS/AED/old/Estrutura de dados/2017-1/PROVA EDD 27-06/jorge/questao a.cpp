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

int busca(Tree* t,int num){
	while((t)->num!=NULL){
	 if(num==(t)->num){
		return 1; // retorna 1 se o elemento estiver na arvore
	}
	else if(num > (t)->num){
	      busca((t)->sad,num);
	}
	else if(num<(t)->num){
	       busca((t)->sae,num);
	}
	 
}
return 0; // retorna 0 se o elemento nao estiver na arvore
}

int main()
{
    return 0;
}
