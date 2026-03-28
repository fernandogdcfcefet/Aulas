#include <stdio.h>
#include <stdlib.h>

typedef struct Tree *seta;
typedef struct Tree{
  int num;
  seta sad;
  seta sae;
}Tree;

Tree* createTree()
{
    return NULL;
}

int treeIsEmpty(seta t)
{
    return t == NULL;
}

void insertTree(seta* t, int num)
{
  if(*t == NULL)
  {
    *t = (seta)malloc(sizeof(Tree));
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

/*int verificarArvore(seta t, int *n){
    if(!treeIsEmpty(t)){
        if( ((t->sad == NULL) && (t->sae->num < t->num)) || ((t->sae == NULL) && (t->sad->num > t->num)) || ((t->sae->num < t->num) && (t->num < t->sad->num))) {
        verificarArvore(t->sae, &*n);
        verificarArvore(t->sad, &*n);
            return *n;
        }
        else *n = 0;
        return 0;
    }
return 0;
}*/

void percorrerArvore(seta t){
    if(!treeIsEmpty(t)){
        percorrerArvore(t->sae);
        printf("%d ",t->num);
        percorrerArvore(t->sad);
    }
}

seta espelharArvore(seta *t){
    if(!treeIsEmpty(*t)){
        seta aux = (*t)->sad;
        (*t)->sad = (*t)->sae;
        (*t)->sae = aux;
        espelharArvore(&(*t)->sae);
       //printf("%d ",(*t)->num);
        espelharArvore(&(*t)->sad);
    }
    return *t;
}

int estritamenteBinaria(seta t,int *n){
    if(!treeIsEmpty(t)){
        if(treeIsEmpty(t->sae) == treeIsEmpty(t->sad)){
            estritamenteBinaria(t->sae, &*n);
            estritamenteBinaria(t->sad, &*n);
            return *n;
            }
            else *n = 0;
            return 0;
    }
return 0;
}

int main()
{
    seta t = createTree();
    seta s = createTree();
    insertTree(&t, 3);
    insertTree(&t, 1);
    insertTree(&t, 2);
    insertTree(&t, 5);
    insertTree(&t, 4);
    insertTree(&t, 0);
    insertTree(&t, 6);
    insertTree(&t, 7);
    int n=1;
    if(estritamenteBinaria(t, &n))
        printf("E estritamente binaria\n\n");
    else printf("nao eh estritamente Binaria\n");
    percorrerArvore(t);
    //if(verificarArvore(t, &n))
      //  printf("\n\n\nE arvore binaria\n\n");
    //else printf("\n\n\nnao eh arvore Binaria\n");
    espelharArvore(&t);
    //if(verificarArvore(t, &n))
      //  printf("\n\n\nE arvore binaria\n\n");
    //else printf("\n\n\nnao eh arvore Binaria\n");
    printf("\n");
    percorrerArvore(t);

    return 0;
}
