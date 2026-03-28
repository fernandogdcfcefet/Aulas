typedef int TipoChave;
typedef struct{
    TipoChave Chave;
} TipoItem;
typedef struct TipoCelula *TipoApontador;
typedef struct TipoCelula{
    TipoItem Item;
    TipoApontador Prox;
} TipoCelula;
typedef struct{
    TipoApontador Primeiro, Ultimo;
} TipoLista;

void FLVazia(TipoLista *Lista){
    Lista->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->ULtimo = Lista->Primeiro;
    Lista->Primeiro->Prox = NULL;
}

int Vazia(TipoLista Lista){
return(Lista.Primeiro==Lista.Ultimo);
}

void Insere(TipoItem x, TipoLista *Lista){
    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    Lista->Ultimo->Item = x;
    Lista->Ultimo->Prox = NULL;
}

void Retira(TipoApontador p, TipoLista *Lista, TipoItem *Item){
    TipoApontador q;
    if(Vazia(*Lista) || p==NULL || p->Prox==NULL){
        printf("ERRO: Lista vazia ou posicao nao existe \n");
        return;
    }
    q = p->Prox;
    *Item = q->Item;
    p->Prox = q->Prox;
    if(p->Prox==NULL) Lista->Ultimo = p; free(q);
}



void RetiraTodos(TipoLista *Lista, TipoItem Item){ //LETRA A
    if(Vazia(*Lista)){
        printf("ERRO: Lista vazia");
        return;
    }
    TipoApontador aux = Lista->Primeiro;
    TipoItem aux2;
    while(aux->Prox!=NULL){
        if(aux->Item==Item){                 //testa a igualdade do elemento
            Retira(aux, &Lista, &aux2);      //retira o elemento igual
        }
    aux = aux->Prox;
    }
}


void InsereOrdenado(TipoItem x, TipoLista *Lista){  //LETRA B

    Lista->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    Lista->Ultimo = Lista->Ultimo->Prox;
    TipoApontador aux = Lista->Primeiro;

    while(aux->Item < x){
        if(x<aux->Prox->Item){
                aux->Item = x;

        }
        aux=aux->Prox;
    }
    Lista->Ultimo->Prox = NULL;

}

int main()
{
    return 0;
}
