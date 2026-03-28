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

int BuscaMenor(Tree *t,int num){
	if(t==NULL){
		return 1;
	}
	if(t->num>num){
		return 0;
	}
	else if((BuscaMenor(t->sae,num)==0 || BuscaMenor(t->sad,num)==0)){
		return 0;
	}
	else{
		return 1;
	}
}

int BuscaMaior(Tree *t, int num){
	if(t==NULL){
		return 1;
	}
	if(t->num<num){
		return 0;
	}
	else if((BuscaMaior(t->sad,num)==0 || BuscaMaior(t->sae,num)==0)){
		return 0;
	}
	else{
		return 1;
	}
}

int Busca(Tree *t){
	if(t==NULL){
		return 1;
	}
	if((BuscaMenor(t->sae,t->num)==0 || BuscaMaior(t->sad,t->num)==0)){
		return 0;
	}
	else if((Ebusca(t->sae)==0 || EBusca(t->sad)==0)){
		return 0;
	}
	else{
		return 1;
	}
}


int main()
{
    Tree* t = createTree();
    insertTree(&t, 12);
    //Busca(t,12);
    return 0;
}
