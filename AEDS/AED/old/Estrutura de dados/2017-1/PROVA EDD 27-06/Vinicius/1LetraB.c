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

void invertTree(Tree* t){
    if(t->sae!=NULL){
        t->sae = t->sad;
        invertTree(t->sae);
    }
    if(t->sad!=NULL){
        t->sae = t->sad;
        invertTree(t->sad);
    }
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

    invertTree(t);
}
