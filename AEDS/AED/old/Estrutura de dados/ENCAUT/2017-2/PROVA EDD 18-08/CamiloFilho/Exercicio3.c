#include<stdio.h>
#include<string.h>
#define L 5

typedef struct{
    char nome[50];
    int idade;
    int CPF;
}Autor;

typedef struct{
    char titulo[30];
    Autor autor;
    int ano;
} Livro;

void cadastro(Livro *l){
    int i;
    for(i=0; i<L; i++){
        printf("\nTitulo: ");
        fflush(stdin);
        gets(l[i].titulo);
        printf("\nAutor: ");
        fflush(stdin);
        gets(l[i].autor.nome);
        printf("\nIdade autor: ");
        scanf("%d", &l[i].autor.idade);
        printf("\nCPF autor: ");
        scanf("%d", &l[i].autor.CPF);
        printf("\nAno: ");
        scanf("%d", &l[i].ano);
    }
    //puts(l[0].titulo);
    //printf("%d%d%d", l[0].autor.idade,l[0].autor.CPF, l[0].ano);
}

char busca(char titulo[], Livro *l){
    int i;
    char s = 'n';
    for(i=0; i<L; i++){
        if(strcmp(l[i].titulo,titulo)==0){
            printf("\nTitulo: ");
            puts(l[0].titulo);
            printf("Autor: ");
            puts(l[0].autor.nome);
            printf("\nIdade autor: %d\nCPF autor: %d\nAno: %d", l[0].autor.idade,l[0].autor.CPF, l[0].ano);
            //s = 's';
        }
    }
    return s;
}

int main(){
    Livro l[L];

    cadastro(l);

    busca("rede", l);

   // if(strcmp(busca("rede", l) , 'n')==0)
   //     printf("\nNao encontrado.\n");

    return(0);
}

