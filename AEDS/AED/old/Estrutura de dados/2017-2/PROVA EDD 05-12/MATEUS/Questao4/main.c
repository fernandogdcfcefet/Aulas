#include <stdio.h>
#include <stdlib.h>

typedef struct TipoNo
{
  int num;
  struct TipoNo* dir;
  struct TipoNo* esq;
} TipoNo;

TipoNo* createTipoNo()
{
    return NULL;
}

int TipoNoIsEmpty(TipoNo* t)
{
    return t == NULL;
}

void InserirTipoNo(TipoNo** t, int num)
{
  if(*t == NULL)
  {
    *t = (TipoNo*)malloc(sizeof(TipoNo));
    (*t)->esq = NULL;
    (*t)->dir = NULL;
    (*t)->num = num;
  } else {
    if(num < (*t)->num)
    {
      InserirTipoNo(&(*t)->esq, num);
    }
    if(num > (*t)->num)
    {
      InserirTipoNo(&(*t)->dir, num);
    }
  }
}

void ArvoreBusca (){

}

void Espelho (TipoNo** t){
    TipoNo no;
    if(*t == NULL){
        printf("Arvore vazia \n");
    }

    no.num=(*t)->num;

    while((*t)->esq->num =! NULL ){
        Espelho (&no);
    }
    while((*t)->dir->num =! NULL ){
        Espelho (&no);
    }

}

int EstriBin (TipoNo** t){
    int i,j;
    if(*t->esq =! NULL){
        i++;
        EstriBin (&t);
    }
    if(*t->dir =! NULL){
        j++;
        EstriBin (&t);
    }
    if(i-j==0)
    {
        return 1;
    }else return 0 ;
}
// 1 é verdadeiro e 0 é falso

int main()
{
    TipoNo* t = createTipoNo();

    InserirTipoNo(&t, 2);
    InserirTipoNo(&t, 1);
    InserirTipoNo(&t, 3);

    Espelho(&t);

    EstriBin (&t);

    return 0;
}
