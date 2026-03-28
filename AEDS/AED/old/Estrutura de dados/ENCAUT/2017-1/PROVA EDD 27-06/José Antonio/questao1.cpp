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

void caminha(Tree *t){
	
	if(t->sae!= NULL){
		caminha(t->sae);
	}
	if(t->sad!=NULL){
		caminha(t->sad);
	}
}
//Letra (a)
/////////////////////////////////
int  verificaSeEhBusca(Tree *t){  
	
	treeIsEmpty(t);
	
	caminha(t);
	
	if((t->sae)<(t->sad)){ //retorna 1, caso seja de busca e, retorna 2 caso não seja.
		return 1;
	}
	else return 2;

}
/////////////////////////////////

//Letra (c)
////////////////////////////////
int estritamenteBinaria(Tree *t){
	
	verificaSeEhBusca(t);
	caminha(t);
	
	
	
}
//////////////////////////////

int main()
{
    return 0;
}
