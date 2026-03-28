//Para uma arvore ser estritamente binaria o sae e o sad tem que ser null ou os dois tem que ser diferente de null
int VerificaArvoreEstritamenteBinaria(Tree *a)
{
    if(a==NULL){
        printf("A arvore está vazia");
    }else{
        if(((a->sad && a->sae)== NULL) || (a->sad && a->sad)!=NULL){
            printf("A arvore e estritamente binaria");
            return 0;}
        else return 1;
    }

}
