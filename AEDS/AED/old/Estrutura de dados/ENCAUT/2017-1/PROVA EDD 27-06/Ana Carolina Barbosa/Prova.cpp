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
//questão 1 letra a.
void binaria(Tree* t){
	if(t->sad>t && t->sae<t){
		binaria(t->sad);
		binaria(t->sae);
		printf("e binaria de busca");
    }
    else printf("nao e binaria de busca");
	
	
	
} 

//questão 1 letra b
void IncluirEspelhado (Tree** t, int num)
{
  if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
  } else {
    if(num > (*t)->num)
    {
      insertTree(&(*t)->sae, num);
    }
    if(num < (*t)->num)
    {
      insertTree(&(*t)->sad, num);
    }
  }
}
void Espelhar(tree* t){
	Tree * nt=createTree();
	if(t->sae!=NULL){
		IncluirEspelhado(&nt,t->num);
		Espelhar(t->sae);
	}
	if(t->sad!=NULL){
		IncluirEspelhado(&nt,t->num);
		Espelhar(t->sad);
	}
}

// questão 1 letra c.
int EBinaria(Tree *t){
int cont;	
	if (t->sad&&t->sae!=NULL){
		EBinaria(t->sad);
		EBinaria(t->sae);
		 cont=1;
	}
	
	if((t->sad!=NULL&&t->sae==NULL)||(t->sad!=NULL&&t->sae==NULL)){
		cont=0;
	}
	return cont;	

}



int main()
{ /*Tree * t= createTree();
   insertTree(& t, 10);
   insertTree(& t, 9);
   insertTree(& t, 11);
  int i= EBinaria(t);
     if (i==1)
     printf("e estritamente binaria \n");
     if(i==0)
     printf("e estritamente binaria\n");
     binaria(t);*/
     
   
   
    return 0;
}
