#include <stdio.h>
#include <stdlib.h>

typedef struct tree{
  int num;
  struct tree* sad;
  struct tree* sae;
} Tree;

Tree* createTree() {
    return NULL;
}

int treeIsEmpty(Tree* t) {
    return t == NULL;
}

void insertTree(Tree** t, int num) {
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

void Imprime(Tree* t) {
    if(t == NULL)
        return;
    Imprime(t->sae);
    printf("%d\n", t->num);
    Imprime(t->sad);
}

int EstritamentBinaria(Tree* t) {           // Faz parte da letra C
    int dir = 0, esq = 0;
    if(t->sad != NULL) {
        EstritamentBinaria(t->sad);
        dir = 1;
    }

    if(t->sae != NULL) {
        EstritamentBinaria(t->sae);
        esq = 1;
    }
    return (dir + esq != 1) ? 1 : 0;
}

void Verifica(Tree* t) {                // Letra C da Prova
    if(EstritamentBinaria(t) == 0)
        printf("A arvore nao e estritamente binaria\n");
    else
        printf("A e estritamente binaria\n");
}

void EspelhaArvore(Tree* t) {
   // Tree* Aux = createTree();

}

int main() {
    Tree* t = createTree();
    insertTree(&t, 5);
    insertTree(&t, 4);
    insertTree(&t, 3);
    insertTree(&t, 7);
    insertTree(&t, 12);
    Verifica(t);
    return 0;
}
