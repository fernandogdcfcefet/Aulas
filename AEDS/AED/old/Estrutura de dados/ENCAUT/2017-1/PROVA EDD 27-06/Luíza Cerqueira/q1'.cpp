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

void imprime (Tree* t){

	if (!treeIsEmpty(t)){
		imprime (t->sae); 
		printf ("%d \n",  t->num);
		imprime (t->sad); 
	}

}
//// QUESTÃO 1 A 
void Busca(Tree* t){

}

////QUESTÃO 1 B
void Espelho(Tree* t){
	Tree* te = createTree();
	if(te == NULL)
 	{
    te = (Tree*)malloc(sizeof(Tree));
    te->sae = NULL;
    te->sad = NULL;
    te->num = t->num;
  }
	
	if (t->sae!=NULL){
		insertTree(&te, t->sad->num);
		Espelho (te -> sae); 
	}
	if (t->sad!=NULL){
		insertTree(&te, t-> sae->num);
		Espelho (te -> sad); 
	}
	imprime (te); 
}

//// QUESTAO 1 C 

int Binaria (Tree* t){
	if (t!= NULL){
		Binaria(t->sae);
		if ((t->sad)&&(t->sae) == NULL) return 0;
		if (((t->sad)== NULL) && ((t->sae) != NULL)) return 1;
		if (((t->sae)== NULL) && ((t->sad) != NULL)) return 1;
		if ((t->sad)&&(t->sae) != NULL) return 0;
		Binaria (t->sad); 
	}
	//se retorna 0 é estritamente binária 
}

void caminhamento (Tree* t){
	if (t->sae!=NULL){
		caminhamento (t->sae);
	}
	if (t->sae!=NULL){
		caminhamento (t->sad);
	}
}

int main()
{
	Tree* t = createTree();
	insertTree (&t, 13);
	insertTree (&t, 14);
	insertTree (&t, 11);
	insertTree (&t, 12);
	
	if (Binaria(t) == 0 ){
		printf ("A arvore e estritamente binaria\n");
	}else{
		printf ("A arvore nao e estritamente binaria \n");
	}
	
	imprime(t); 
    return 0;
}
