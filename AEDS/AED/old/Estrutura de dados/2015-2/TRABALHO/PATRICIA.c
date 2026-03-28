//http://forum.clubedohardware.com.br/topic/1095629-fun%C3%A7%C3%A3o-de-buscar-arvore-patricia/
#include <stdio.h>
#include <stdlib.h>
#define numMaxBits 8

typedef struct no{
    int bit;
    char info;
    struct no *esq;
    struct no *dir;
} tipoNo;

int pegaBit(char info, int pos){
    return (info >> 7-pos) & 1;
}

void imprimeLetraBin(char,int);

tipoNo *insere(tipoNo *arv, char info) {
    tipoNo *novo, *novoFilho, *retorno;
    int posBit;

    if (arv == NULL) {
        novo = malloc(sizeof(tipoNo));
        novo->info = info;
        novo->bit = -1;
        novo->esq = NULL;
        novo->dir = NULL;
        retorno = novo;
    }else{
        if (arv->bit == -1){
            posBit = 0;
        while ((posBit < numMaxBits) && (pegaBit(arv->info, posBit) == pegaBit(info, posBit)))
            posBit++;
        if (posBit < numMaxBits) {
            novoFilho = malloc(sizeof(tipoNo));
            novoFilho->info = info;
            novoFilho->bit = -1;
            novoFilho->esq = NULL;
            novoFilho->dir = NULL;
            novo = malloc(sizeof(tipoNo));
            novo->info = info;
            novo->bit = posBit;
        if (pegaBit(info,posBit) == 0) {
            novo->esq = novoFilho;
            novo->dir = NULL;
        }else {
            novo->dir = novoFilho;
            novo->esq = NULL;
        }
            retorno = novo;
        }else
            retorno = NULL;
        }else{
        if (pegaBit(info, arv->bit) == 0){
            novo = insere(arv->esq, info);
        if (novo != NULL) {
        if (novo->bit < arv->bit)
            retorno = novo;
        else{
        if(novo->esq == NULL)
            novo->esq = arv->esq;
        else
            novo->dir = arv->esq;
            arv->esq = novo;
            retorno = NULL;
        }
        }else{
            retorno = arv;
        }
        }else{
            novo = insere(arv->dir, info);
        if (novo != NULL){
            if (novo->bit < arv->bit)
                retorno = novo;
            else{
            if (novo->esq == NULL)
                novo->esq = arv->dir;
            else
                novo->dir = arv->dir;
                arv->dir = novo;
                retorno = NULL;
            }
            }else{
                retorno = arv;
            }
        }
        }
    }

    return retorno;
}
    tipoNo *inserePatricia(tipoNo *arv, char info) {
    tipoNo *novo, *retorno;
    novo = insere(arv, info);
    if (novo == NULL)
        retorno = arv;
    else {
        if (novo->bit != -1)
        if (novo->esq == NULL) {
            novo->esq = arv;
        }else {
            novo->dir = arv;
}
    retorno = novo;
}
return retorno;
}

tipoNo *removePatricia(tipoNo *arv, char info) {
    tipoNo *retorno;
    if (arv == NULL){
        retorno = NULL;
    }else{
        if (arv->bit == -1){
	        if (arv->info == info){

	        	printf("\n NO REMOVIDO : %c",arv->info);
	            free(arv);
	            retorno = NULL;
	        }else{
	            retorno = arv;
	        }
        }else{
            if (pegaBit(info, arv->bit) == 0){
                arv->esq = removePatricia(arv->esq, info);
            if (arv->esq == NULL){
                retorno = arv->dir;

                if(arv!=NULL){
	                printf("    No de bits incomuns removidos: ");
	                imprimeLetraBin(arv->info,arv->bit);
				}

                free(arv);
            }else{
                retorno = arv;
            }
            }else{
                arv->dir = removePatricia(arv->dir, info);
            if (arv->dir == NULL){
                retorno = arv->esq;

                if(arv!=NULL){
	                printf("    No de bits incomuns removidos: ");
	                imprimeLetraBin(arv->info,arv->bit);
				}

                free(arv);
            }else{
                retorno = arv;
            }
}
}
}
    return retorno;
}

void caminhaEmOrdem(tipoNo *arv) {

		if(arv!=NULL)
		{


				caminhaEmOrdem(arv->esq);

				if(arv->bit==-1)
				{

					printf("\n no |%s| -- \n\n",&arv->info);

		        }
	        	else{
	        		printf("  %s Total de bits = ",&arv->info);
			        imprimeLetraBin(arv->info,0);
		        	printf(" Parte diferente separada: ");
		        	imprimeLetraBin(arv->info,arv->bit);
		        	printf("\n-----\n");
	        	}

				caminhaEmOrdem(arv->dir);
		}
}

void imprimeLetraBin(char letra, int ini) {
	int i;
    //printf("%c = ", letra);
    for(i=ini; i < numMaxBits; i++)
        printf("%d", pegaBit(letra,i));
    printf("\n");
}

int main()
{

    tipoNo *arvore = NULL;
    int op=0;
    char letra;

    while(op!=-1)
    {
    	printf("------------------ MENU -------------------");
        printf("\n\n\tDigite: \n 1 - Inserir\n 2 - Remover\n 3 - Mostrar Nos\n    :");
        scanf("%d",&op);

        system("cls");

        if(op==1)
        {
            printf("\n\n\tDigite a letra a ser inserida: ");
            scanf("%s",&letra);
            arvore=inserePatricia(arvore, letra);

        }
        else if(op==2)
        {
            printf("\n\n\tDigite a letra a ser removida: ");
            scanf("%s",&letra);
            arvore=removePatricia(arvore, letra);
            getch();
        }
        else if(op==3)
        {
            caminhaEmOrdem(arvore);
            getch();
        }

        system("cls");

    }
/*
arvore = inserePatricia(arvore, 'B');
arvore = inserePatricia(arvore, 'C');
arvore = inserePatricia(arvore, 'J');
arvore = inserePatricia(arvore, 'H');
printf("\n====================================================");
printf("\n INSERIDO");
getch();
system("cls");
printf("\n====================================================");
printf("\n");
caminhaEmOrdem(arvore);
printf("\n");
printf("\n");
printf("\n====================================================");
printf("\n VALORES EM ARVORE");
getch();
system("cls");
printf("\n====================================================");
arvore = removePatricia(arvore, 'J');
printf("\n====================================================");
printf("\n REMOVENDO A LETRA J");
getch();
system("cls");
printf("\n====================================================");
printf("\n");
caminhaEmOrdem(arvore);
printf("\n");
printf("\n");
printf("\n====================================================");
printf("\n VALORES EM ARVORE");
getch();
system("cls");
printf("\n====================================================");
arvore = removePatricia(arvore, 'C');
arvore = removePatricia(arvore, 'B');
printf("\n====================================================");
printf("\n REMOVENDO A LETRA B e C");
getch();
system("cls");
printf("\n====================================================");
printf("\n");
caminhaEmOrdem(arvore);
printf("\n");
printf("\n");
printf("\n====================================================");
printf("\n VALORES EM ARVORE");
getch();
system("cls");
printf("\n====================================================");
arvore = removePatricia(arvore, 'H');
printf("\n====================================================");
printf("\n REMOVENDO A LETRA H");
getch();
system("cls");
printf("\n====================================================");
printf("\n");
caminhaEmOrdem(arvore);
printf("\n");
printf("\n");
printf("\n====================================================");
printf("\n VALORES EM ARVORE");
getch();
system("cls");
*/
return 0;
}

