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

//Questão 1 letra a

/*int EBinaria(Tree * t){
    printf("oi \n");
	int raiz;
     raiz=t->num;
    if((t->sae->num)<raiz)
    {  printf("oi 2 \n");
        if((t->sad->num)>raiz){
          printf("oi 3\n");
		  EBinaria(t->sad);
		  printf("oi 4\n");	
	    } printf("oi 5\n");
	    EBinaria(t->sae);
	    printf("oi 6\n");
	    return 1;
	    
    }
    else return 0;
    

	
}*/
//Questão 1 letra B
void InsereE(Tree** t, int num)
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
void CriarEspelho(Tree* t){
	 printf("oi \n");
	 Tree* espelho = createTree();
	 int num;
	 while (t->num !=NULL){
	 	printf("oi 2\n");
	 	int n=t->num;
	 	InsereE(&espelho, n);
	 	printf("oi 3\n");
	 	CriarEspelho(t->sad);
	 	printf("oi 4\n");
	 	CriarEspelho(t->sae);
        printf("oi5 \n");	 	 	
	 }
}











int main()
{
    Tree* t = createTree();
    insertTree(&t, 12);
    insertTree(&t, 11);
    insertTree(&t, 15);
    insertTree(&t, 14);
    insertTree(&t, 9);
  //  printf("%d ",EBinaria(t));
    CriarEspelho(t);
    return 0;
}
