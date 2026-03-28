#include<stdio.h>
#include<string.h>
#define N 2
#define X 3

typedef struct{
    int matricula;
    char nome[50];
    float notas[X];
} Aluno;

void cadastro(Aluno *a){
    int i, j;
    for(i=0; i<N; i++){
        printf("\nNome: ");
        fflush(stdin);
        gets(a[i].nome);
        printf("\nMatricula: ");
        scanf("%d", &a[i].matricula);
        for(j=0;j<X; j++){
            printf("\nAno: ");
            scanf("%d", &a[i].notas[j]);
        }
    }
}

void aprovados(Aluno *a){
    int i, j;
    float m;
    for(i=0; i<N; i++){
        for(j=0;j<X; j++){
            m = (m*j+ a[i].notas[j])/(j+1);
        }
        if(m>=60)
            puts(a[i].nome);
    }
}

Aluno maiorMedia(Aluno *a){
    int i, j, pos;
    float M, aux;
    for(i=0; i<N; i++){
        for(j=0;j<X; j++){
            aux = (aux*j+ a[i].notas[j])/(j+1);
        }
        if(M<aux){
            M = aux;
            pos = i;
        }
    }
    return a[pos];
}

int main(){
    Aluno a[N];

    cadastro(a);
    aprovados(a);

    Aluno b = maiorMedia(a);

    return(0);
}


