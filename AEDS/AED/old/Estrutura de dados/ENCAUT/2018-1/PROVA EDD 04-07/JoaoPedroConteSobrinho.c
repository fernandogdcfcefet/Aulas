#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct NO* ArvBin;

struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
};

ArvBin* cria_ArvBin(){
    ArvBin* raiz = (ArvBin*) malloc(sizeof(ArvBin));
    if(raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

void libera_ArvBin(ArvBin* raiz){
    if(raiz == NULL)
        return;
    libera_NO(*raiz);//libera cada nó
    free(raiz);//libera a raiz
}

int insere_ArvBin(ArvBin* raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* novo;
    novo = (struct NO*) malloc(sizeof(struct NO));
    if(novo == NULL)
        return 0;
    novo->info = valor;
    novo->dir = NULL;
    novo->esq = NULL;

    if(*raiz == NULL)
        *raiz = novo;
    else{
        struct NO* atual = *raiz;
        struct NO* ant = NULL;
        while(atual != NULL){
            ant = atual;
            if(valor == atual->info){
                free(novo);
                return 0;//elemento já existe
            }

            if(valor > atual->info)
                atual = atual->dir;
            else
                atual = atual->esq;
        }
        if(valor > ant->info)
            ant->dir = novo;
        else
            ant->esq = novo;
    }
    return 1;
}

struct NO* remove_atual(struct NO* atual) {
    struct NO *no1, *no2;
    if(atual->esq == NULL){
        no2 = atual->dir;
        free(atual);
        return no2;
    }
    no1 = atual;
    no2 = atual->esq;
    while(no2->dir != NULL){
        no1 = no2;
        no2 = no2->dir;
    }
    // no2 é o nó anterior a r na ordem e-r-d
    // no1 é o pai de no2
    if(no1 != atual){
        no1->dir = no2->esq;
        no2->esq = atual->esq;
    }
    no2->dir = atual->dir;
    free(atual);
    return no2;
}
// http://www.ime.usp.br/~pf/algoritmos/aulas/binst.html
int remove_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* ant = NULL;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            if(atual == *raiz)
                *raiz = remove_atual(atual);
            else{
                if(ant->dir == atual)
                    ant->dir = remove_atual(atual);
                else
                    ant->esq = remove_atual(atual);
            }
            return 1;
        }
        ant = atual;
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

int estaVazia_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return 1;
    if(*raiz == NULL)
        return 1;
    return 0;
}

int totalNO_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = totalNO_ArvBin(&((*raiz)->esq));
    int alt_dir = totalNO_ArvBin(&((*raiz)->dir));
    return(alt_esq + alt_dir + 1);
}

int altura_ArvBin(ArvBin *raiz){
    if (raiz == NULL)
        return 0;
    if (*raiz == NULL)
        return 0;
    int alt_esq = altura_ArvBin(&((*raiz)->esq));
    int alt_dir = altura_ArvBin(&((*raiz)->dir));
    if (alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return(alt_dir + 1);
}

int consulta_ArvBin(ArvBin *raiz, int valor){
    if(raiz == NULL)
        return 0;
    struct NO* atual = *raiz;
    while(atual != NULL){
        if(valor == atual->info){
            return 1;
        }
        if(valor > atual->info)
            atual = atual->dir;
        else
            atual = atual->esq;
    }
    return 0;
}

void preOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        printf("%d\n",(*raiz)->info);
        preOrdem_ArvBin(&((*raiz)->esq));
        preOrdem_ArvBin(&((*raiz)->dir));
    }
}

void emOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        emOrdem_ArvBin(&((*raiz)->esq));
        printf("%d\n",(*raiz)->info);
        emOrdem_ArvBin(&((*raiz)->dir));
    }
}

void posOrdem_ArvBin(ArvBin *raiz){
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        posOrdem_ArvBin(&((*raiz)->esq));
        posOrdem_ArvBin(&((*raiz)->dir));
        printf("%d\n",(*raiz)->info);
    }
}

/*
Função para espelhar a arvore binária,
toda arvore sera espenhada, ou seja,
depois dessa funcao a arvore ficara uma
bagunça, por isso ela é chamada por ultimo.
*/
int espelho(ArvBin *raiz){
    ArvBin* raizAux = cria_ArvBin();
    if(raiz == NULL)
        return;
    if(*raiz != NULL){
        espelho(&((*raiz)->esq));
        raizAux = (*raiz)->esq;
        espelho(&((*raiz)->dir));
        (*raiz)->esq = (*raiz)->dir;
        (*raiz)->dir = raizAux;
    }
}

/*
Função para verificar se uma arvore
é uma arvore binária de busca, ou seja
se ela tem os dois lados e se seu lado direito
tem os elementos maiores que a raiz e se
o lado esquerdo tem os elementos menores que a raiz
*/
int verificaArvoreBusca(ArvBin *raiz){
    if(raiz == NULL)
        return TRUE;
    if((*raiz)->esq == NULL && (*raiz)->dir != NULL)
        return FALSE;
    if((*raiz)->dir == NULL && (*raiz)->esq != NULL)
        return FALSE;
    if((*raiz)->dir > (*raiz) || (*raiz)->esq < (*raiz)){
        return TRUE;
    }else{
        verificaArvoreBusca(&((*raiz)->esq));
        verificaArvoreBusca(&((*raiz)->dir));
    }
}

/*
Função para verificar se uma arvore
é uma arvore estritamente binaria
está comentada porque nao funciona
assim nao influencia no andamento das
demais letras
*/
/*
int verificaArvoreEstritamenteBinaria(ArvBin *raiz){
    if(raiz == NULL)
        return TRUE;
    else{
        verificaArvoreEstritamenteBinaria(&((*raiz)->esq));
        if((*raiz)->esq == NULL && (*raiz)->dir != NULL)
            return FALSE;
        else if((*raiz)->dir == NULL && (*raiz)->esq != NULL)
            return FALSE;
        else
            verificaArvoreEstritamenteBinaria(&((*raiz)->dir));
    }
}
*/
int main(){
    int N = 8, dados[8] = {4,2,6,1,3,5,10,8};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);


    printf("Letra A:\n");
    if(verificaArvoreBusca(raiz) == 1)
        printf("Arvore de busca\n");
    else
        printf("Nao Arvore de busca\n");
    printf("\n------------------------------------------------\n\n");


    printf("Letra C:\nProblema no codigo\n");
    /*if(verificaArvoreEstritamenteBinaria(raiz) == 1)
        printf("Arvore de busca\n");
    else
        printf("Nao Arvore de busca\n");*/
    printf("\n------------------------------------------------\n\n");

    printf("Letra B:\n");
    printf("Nao espelhada: \n");
    preOrdem_ArvBin(raiz);//Mostra arvore antes de espelhar
    espelho(raiz);
    printf("\nEspelhada: \n");
    preOrdem_ArvBin(raiz);//Mostra arvore espelhada

    libera_ArvBin(raiz);

    return 0;
}
