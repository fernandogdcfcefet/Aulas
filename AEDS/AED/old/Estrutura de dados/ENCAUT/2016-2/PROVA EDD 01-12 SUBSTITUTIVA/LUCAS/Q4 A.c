



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


void caminhamentoCentral(Tree* t)
{


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


void Verifica (  int arvore , int n){

int i,j;
int aux ;

for (i=0; i<n; i++){
    for (j= 0;j<n; j--){
         if(num >(*t)->num){

            if insertTree(&(*t)->sad, num);
        }

if(*t == NULL)
  {
    *t = (Tree*)malloc(sizeof(Tree));
    (*t)->sae = NULL;
    (*t)->sad = NULL;
    (*t)->num = num;
      } else {

    }

}





