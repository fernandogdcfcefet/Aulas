#include <stdio.h>
#include <stdio.h>

typedef int Chave;
    typedef struct {
        Chave Chave;
    }func;
    typedef struct Celula *Apontador;
    typedef struct Celula{
        func f1;
        Apontador Prox;
    }Celula;
    typedef struct{
        Apontador Primeiro,Ultimo;
    }NovaLista;
    void FLVazia(NovaLista*Lista)
    {
        Lista->Primeiro=(Apontador) malloc(sizeof(Celula));
        Lista-> Ultimo=Lista-> Primeiro;
        Lista->Primeiro->Prox=NULL;
    }
    int Vazia(NovaLista Lista)
    {
       return(Lista.Primeiro==Lista.Ultimo);

    }
    void Insere(func x,NovaLista*Lista)
    {
        Lista->Ultimo->Prox=(Apontador) malloc(sizeof(Celula));
        Lista-> Ultimo=Lista-> Ultimo->Prox;
        Lista->Ultimo-> f1=x;
        Lista->Primeiro->Prox=NULL;
    }
    void Retira (Apontador p,NovaLista*Lista,func *f1)
    {
        Apontador q;
        if(Vazia(*Lista)|| p==NULL ||p->Prox==NULL){
            printf("Erro: Lista Vazia ou posicao não existe");
            return;
        }
        q=p->Prox;
        *f1 = q->f1;
        p->Prox=q->Prox;
         if (p->Prox==NULL)
            Lista->Ultimo=p;
         free(q);


    }
int main(){

    Chave chave;
    func F1={1};
    func F2={2};
    func F3={3};

    Apontador;
    NovaLista UmaLista;
    Insere(F2,&UmaLista);




}
