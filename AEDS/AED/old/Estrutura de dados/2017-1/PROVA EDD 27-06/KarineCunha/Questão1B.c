//Uma arvore espelho inverte sad por sae
void Espelho(Tree *t){
    Tree *aux;
    if(t==NULL){
        printf("A arvore esta vazia");
    }
     if(t->sae != NULL){
        aux->sae = t->sae;
        t->sae = t->sad;
        t->sad = aux->sae;
        CaminhoArvore(t->sae);

    }
    if(t->sad !=NULL){
        CaminhoArvore(t->sad);
    }

}
