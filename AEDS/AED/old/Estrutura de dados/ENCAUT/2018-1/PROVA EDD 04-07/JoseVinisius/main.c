#include <stdio.h>
#include <stdlib.h>

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
/* Numero 1 letra A
Primeiramente uma arvore binaria de pesquisa e definida como os valores maior que ficam a direita de um nó e os valores menor a esquerda do nó.

*/
int NaoArvoreBin(ArvBin *raiz){
    int valor = 0;
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0; //Caso seja uma arvore com raiz de zero elemento ou chegou-se ao fim dos nós temos que ela obedece o conceito de Arvores binaria.
    }
    if((*raiz)->dir != NULL){
    //Aqui eu faço uma comparação para saber se o valor a direita do nó e menor que o valor do nó, o que e contra a regra de uma arvore binaria. Se sim retorno 1.
    if((*raiz)->info > (*raiz)->dir->info)
        return 1;
        valor += NaoArvoreBin(&((*raiz)->dir));
    }
    //Aqui eu faço uma comparação para saber se o valor a esquerda do nó e maior que o valor do nó, o que e contra a regra de uma arvore binaria. Se sim retorno 1.
   if((*raiz)->esq != NULL){
        if((*raiz)->info < (*raiz)->esq->info)
        return 1; //Caso sim returno com 1 simbolizando não obedece ao conceito de arvore binaria.
        valor += NaoArvoreBin(&((*raiz)->esq));
    }
    if(valor >= 1){
        return 1; //Caso algum nó desbedeça a regra retorne verdadeiro simbolizando que não e uma arvBin.
    }else
    return 0;
    //*/
}
/* 1 letra b espelho
*/
void espelho(ArvBin *raiz){
    struct No *aux = (*raiz)->dir;
    (*raiz)->dir = (*raiz)->esq;
    (*raiz)->esq = aux;
}
/* 1 c */

int estritamenteBIN(ArvBin *raiz){
      int valor = 0;
    if(raiz == NULL){
        return 0;
    }
    if(*raiz == NULL){
        return 0;
    if(((*raiz)->dir == NULL) && ((*raiz)->esq == NULL)){ //Aqui verifico se não chegeui ao fim em uma folha.
        return 0;
    }
    if(((*raiz)->dir != NULL) && ((*raiz)->esq != NULL)){//Verifico se no meu nó os valores a esquerda e a direita e diferente de null
        valor += estritamenteBIN(((*raiz)->dir));
        valor += estritamenteBIN(((*raiz)->esq));
    }
    else{ return 1;}
    if(valor >= 1){
        return 1;
    }
    return 0;
    }
}

int main(){
    int N = 8, dados[8] = {50,100,30,20,40,45,35,37};

    ArvBin* raiz = cria_ArvBin();

    int i;
    for(i=0; i < N; i++)
        insere_ArvBin(raiz,dados[i]);
        espelho(&(*raiz));
       int t =  NaoArvoreBin(&(*raiz));
       printf("%d", t); //Aqui com espelho mostra que e cotraria a tese de arvore binaria.
       int b = estritamenteBIN(&(*raiz));
       printf("\n %d", b);


    return 0;
}
