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

int treeIsBinary(Tree* t){ // A FUNÇÃO RETORNA ZERO EM CASO NEGATIVO
                           // E DIFERENTE DE ZERO EM CASO POSITIVO
    if(t->sae!=NULL && t->sad!=NULL)
        return treeIsBinary(t->sae)+1;
    if(t->sae==NULL && t->sad!=NULL)
        return 0;
    if(t->sae!=NULL && t->sad==NULL)
        return 0;
}

/*
 00 00 00 00 00 00 10 10 10 10 10 11 11 11 11 010 010 010 0110 0110 0111
 A  A  A  A  A  A  C  C  C  C  C  B  B  B  B  D   D   D   F    F    E

 A = 00
 B = 11
 C = 10
 D = 010
 E = 0111
 F = 0110

*/

int main(){
    Tree* t = createTree();
    insertTree(&t, 10);
    insertTree(&t, 3);
    insertTree(&t, 5);
    insertTree(&t, 2);
    insertTree(&t, 12);
    insertTree(&t, 13);
    insertTree(&t, 11);

    int result = treeIsBinary(t);
	if(result==0)
    	printf("Nao e arvore binaria.\n");
    else
    	printf("E arvore binaria.\n");
    return 0;
}
