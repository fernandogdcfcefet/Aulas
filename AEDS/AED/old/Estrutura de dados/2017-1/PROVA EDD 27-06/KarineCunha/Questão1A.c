//  A arvore é considerada uma arvore de busca quando o valor a direita é maior e o da esquerda é menor.
int VerificaArvoreDeBusca(Tree *a){
	if(a!=NULL){
        if((a->num < a->sad->num)&&(a->num > a->sae->num))
            return 0;
        else return 1;
	}else {
	    printf("A arvore esta vazia");
        return 1;
	}
}
// Considerando 0 (verdadeiro) 1(Falso)
