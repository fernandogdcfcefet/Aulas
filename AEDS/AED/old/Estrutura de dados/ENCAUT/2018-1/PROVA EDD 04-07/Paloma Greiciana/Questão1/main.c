#include <stdio.h>
#include <stdlib.h>
#define VERDADEIRO 1 //para a função estritamenteBinária
#define FALSO 0

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

int Busca(ArvBin *raiz){ // função que mostra se a árvore é ou não de busca
        if(*raiz != NULL &&((((*raiz) > (*raiz)->esq) && ((*raiz) < (*raiz)->dir)) || ((*raiz) > (*raiz)->esq &&  (*raiz)->dir==NULL) || ((*raiz) < (*raiz)->dir &&  (*raiz)->esq==NULL))){   //condição para que uma árvore seja de busca (esq<meio<dir)

          Busca(&((*raiz)->esq));    //compara todos os
          Busca(&((*raiz)->dir));                       //nós da árvore até encontrar um nó que não obedece essa condição
        }
    if(raiz == NULL){
        return 0;
    }

 }

ArvBin* Espelha( ArvBin *raiz){ //função que espelha a árvore
       if(raiz == NULL) //se a raiz for nula não se espelha uma árvore
        return;
       if(*raiz == NULL)
        return;

        struct NO* aux; //cria-se uma variável auxiliar para permitir a troca entre esquerda e direita ao se espelhar a árvore
        aux=(*raiz)->esq;
        (*raiz)->esq=(*raiz)->dir;
        (*raiz)->dir=aux;
        printf("%d\n",(*raiz)->info);
        Espelha(&((*raiz)->esq)); //todos os nós da árvore devem ser espelhados
        Espelha(&((*raiz)->dir));


}

int estritamenteBinaria(ArvBin *raiz){   //função que analisa se a árvore é estritamente binária
     if(*raiz == NULL)
        return FALSO;
     if(*raiz!=NULL){
            if((*raiz)->dir == NULL && (*raiz)->esq==NULL){   //se a árvore tiver apenas um nó, é esritamente binária
               return VERDADEIRO;
            }
            if((*raiz)->esq ==NULL || (*raiz)->dir==NULL){  //se simplesmente a esquerda for NULL ou a direita,não é estritamente binária
               return FALSO;
            }
            if((*raiz)->esq!=NULL && (*raiz)->dir!=NULL){  //se a esquerda e a direita forem difernetes de NULL deve-se analisar os demais nós
                estritamenteBinaria((*raiz)->esq);
                estritamenteBinaria((*raiz)->dir);
                return VERDADEIRO;
            }
     }
     return;
}


int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);

    int a= Busca(raiz);
    printf ("%d\n",a);

    preOrdem_ArvBin(raiz);
    printf("\n\n\n");
    Espelha(raiz);
    int b=estritamenteBinaria(raiz);
    printf("%d\n",b);
    //libera_ArvBin(raiz);

    return 0;
}
