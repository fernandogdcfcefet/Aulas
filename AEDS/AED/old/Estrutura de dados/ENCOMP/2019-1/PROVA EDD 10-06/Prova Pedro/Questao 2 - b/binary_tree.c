/* www.GeeksBR.com */

/* Implementação de árvore binária */

#include <stdio.h>
#include <stdlib.h>

/* Cada nó armazena três informações:
   nesse caso um número (num),
   ponteiro para subárvore à direita (sad)
   e ponteiro para subárvore à esquerda (sae).*/
typedef struct tree
{
    int num;
    struct tree* sad;
    struct tree* sae;
} Tree;

/* A estrutura da árvore é representada por um ponteiro
   para o nó raiz. Com esse ponteiro, temos acesso aos
   demais nós. */

/* Função que cria uma árvore */
Tree* createTree()
{
    /* Uma árvore é representada pelo endereço do nó raiz,
       essa função cria uma árvore com nenhum elemento,
       ou seja, cria uma árvore vazia, por isso retorna NULL. */
    return NULL;
}

/* Função que verifica se uma árvore é vazia */
int treeIsEmpty(Tree* t)
{
    /* Retorna 1 se a árvore for vazia e 0 caso contrário */
    return t == NULL;

}

/* Função que mostra a informação da árvore */
void caminhamentoCentral(Tree* t)
{
    /* Essa função imprime os elementos de forma recursiva */

//  printf("<"); /* notação para organizar na hora de mostrar os elementos */
    if(!treeIsEmpty(t)) /* se a árvore não for vazia... */
    {
        /* Mostra os elementos com caminhamento central*/
        caminhamentoCentral(t->sae); /* mostra a sae (subárvore à esquerda) */
        printf("%d ", t->num); /* mostra a raiz */
        caminhamentoCentral(t->sad); /* mostra a sad (subárvore à direita) */
    }
//  printf(">"); /* notação para organizar na hora de mostrar os elementos */
}

/* Função que insere um dado na árvore */
void insertTree(Tree** t, int num)
{
    /* Essa função insere os elementos de forma recursiva */
    if(*t == NULL)
    {
        *t = (Tree*)malloc(sizeof(Tree)); /* Aloca memória para a estrutura */
        (*t)->sae = NULL; /* Subárvore à esquerda é NULL */
        (*t)->sad = NULL; /* Subárvore à direita é NULL */
        (*t)->num = num; /* Armazena a informação */
    }
    else
    {
        if(num < (*t)->num) /* Se o número for menor então vai pra esquerda */
        {
            /* Percorre pela subárvore à esquerda */
            insertTree(&(*t)->sae, num);
        }
        if(num > (*t)->num) /* Se o número for maior então vai pra direita */
        {
            /* Percorre pela subárvore à direita */
            insertTree(&(*t)->sad, num);
        }
    }
}

/* Função que verifica se um elemento pertence ou não à árvore */
int isInTree(Tree* t, int num)
{

    if(treeIsEmpty(t))   /* Se a árvore estiver vazia, então retorna 0 */
    {
        return 0;
    }

    /* O operador lógico || interrompe a busca quando o elemento for encontrado */
    return t->num==num || isInTree(t->sae, num) || isInTree(t->sad, num);
}

/* Função para liberar a memória alocada pela árvore */
Tree* freeTree(Tree** t)
{
    /* Essa função também usa implementação recursiva */
    if(!treeIsEmpty(*t)) /* se a árvore não for vazia... */
    {
        /* Tem que liberar as subárvores primeiro para que o acesso
           não seja perdido. */
        freeTree(&(*t)->sae); /* libera a subárvore à esquerda */
        freeTree(&(*t)->sad); /* libera a subárvore à direita */
        free(*t);
    }

    /* Retorna uma árvore vazia, ou seja, NULL */
    return NULL;
}

/*Retorna o ponteiro antecessor ao número passado como parâmetro*/
Tree** antecessor(int num,Tree** raiz){
    if(*raiz==NULL){
        return NULL;
    }else if(num==(*raiz)->num){
        return raiz;
    }else if(num>(*raiz)->num){
        return antecessor(num,&((*raiz)->sad));
    }else if(num<(*raiz)->num){
        return antecessor(num,&((*raiz)->sae));
    }
}

/*Retorna o valor mais a direita de uma árvore*/
int maisDireita(Tree* raiz){
    if(raiz->sad!=NULL){
        return maisDireita(raiz->sad);
    }else{
        return raiz->num;
    }
}
/*Retira o elemento o número se existir*/
void retira(int num,Tree** raiz){
    Tree** retirado= antecessor(num,raiz);/*Retorna o ponteiro para o elemento que será retirado*/
    if(retirado==NULL){
        printf("Elemento nao esta na arvore\n");
        return;
    }
    Tree* aux=*retirado;
    if((*retirado)->sad!=NULL&&((*retirado)->sae!=NULL)){/*Se o retirado tem dois filhos*/
        Tree** trocado= antecessor(maisDireita((*retirado)->sae),retirado);/*Retorna o ponteiro para o elemento que será trocado*/
        if((*trocado)->sae==NULL){/*Se o trocado não tiver filho*/
            (*trocado)->sad= (*retirado)->sad;
            if(*trocado!=(*retirado)->sae)/*Se o trocado for o filho do retirado poderia gerar um ciclo*/
                (*trocado)->sae= (*retirado)->sae;
            (*retirado)=(*trocado);
            *trocado=NULL;
        }else{/*Se o trocado tiver filho*/
            (*trocado)->sad= (*retirado)->sad;
            (*retirado)=(*trocado);
            *trocado=(*trocado)->sae;
            (*retirado)->sae=aux->sae;/*O retirado agora é o antigo trocado*/
        }
    }else if((*retirado)->sad!=NULL){/*Se o retirado tiver apenas um filho a direita*/
        *retirado=(*retirado)->sad;
    }else if((*retirado)->sae!=NULL){/*Se o retirado tiver apenas um filho a esquerda*/
        *retirado=(*retirado)->sae;
    }else{/*Se o retirado não tiver filhos*/
        *retirado=NULL;
    }
    free(aux);
}

void estritamenteBinaria(Tree* t, int *verdade){

     if(!treeIsEmpty(t))
    {
        if(t->sad != NULL && t->sae == NULL){
           *verdade = 1;

        }else if(t->sae != NULL && t->sad == NULL){
            *verdade = 1;
        }
        estritamenteBinaria(t->sae,verdade);

        estritamenteBinaria(t->sad,verdade);
    }



}

int main()
{
    Tree* t = createTree(); /* cria uma árvore */
    int verdade = 0;

    insertTree(&t, 50);
    insertTree(&t, 70);
    insertTree(&t, 80);
    insertTree(&t, 30);
    insertTree(&t, 20);
    insertTree(&t, 40);
    insertTree(&t, 35);
    insertTree(&t, 43);
    insertTree(&t, 10);
    insertTree(&t, 25);
    insertTree(&t, 42);
    insertTree(&t, 41);


    caminhamentoCentral(t); /* Mostra os elementos da árvore em pré-ordem */

    estritamenteBinaria(t,&verdade);

    if(verdade == 1){
        printf("\nNao e estritamente binaria\n");
    }else{
        printf("\nE estritamente binaria\n");
    }


    retira(43,&t);/*Retira um elemento da árvore*/


    if(treeIsEmpty(t)) /* Verifica se a árvore está vazia */
    {
        printf("\n\nArvore vazia!!\n");
    }
    else
    {
        printf("\n\nArvore NAO vazia!!\n");
    }

    if(isInTree(t, 15))   /* Verifica se o número 15 pertence a árvore */
    {
        printf("\nO numero 15 pertence a arvore!\n");
    }
    else
    {
        printf("\nO numero 15 NAO pertence a arvore!\n");
    }

    if(isInTree(t, 22))   /* Verifica se o número 22 pertence a árvore */
    {
        printf("\nO numero 22 pertence a arvore!\n\n");
    }
    else
    {
        printf("\nO numero 22 NAO pertence a arvore!\n\n");
    }

    t=freeTree(&t); /* Libera a memória alocada pela estrutura árvore */
//
    if(treeIsEmpty(t)) /* Verifica se a árvore está vazia */
    {
        printf("\n\nArvore vazia!!\n");
    }
    else
    {
        printf("\n\nArvore NAO vazia!!\n");
    }
//caminhamentoCentral(t); /* Mostra os elementos da árvore em pré-ordem */
    system("pause");
    return 0;

}

