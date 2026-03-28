#include<stdio.h>
#include<string.h>

#define X 3
#define N 3

typedef struct{
    int matricula;
    char nome[40];
    int notas[X];
}Aluno;

void Aprovados(Aluno a[]){
    int i, j, med;
    printf("Alunos Aprovados");
    for(i=0; i<N; i++){
        for(j=0, med=0; j<X; j++){
            med = (med + a[i].notas[j])/(j+1);
        }
        if(med>=60)
            printf("%s\n", a[i].nome);
    }
}

Aluno mMedia(Aluno a[]){
    int i, j, pos, aux, med;
    for(i=0, aux=0; i<N; i++){
        for(j=0, med=0; j<X; j++){
            med = (med + a[i].notas[j])/(j+1);
        }
        if(med>aux){
            aux = med;
            pos = i;
        }
    }
    return a[pos];
}

int main(){
    Aluno a[N];
    int i,j;
    for(i=0; i<N; i++){
        printf("Nome: ");
        scanf("%s", a[i].nome);
        printf("Matricula: ");
        scanf("%d", a[i].matricula);
        for(j=0; j<X; j++){
            printf("Nota %d: ", (j));
            scanf("%d", a[i].notas[j]);
        }
    }
    Aprovados(a);
    printf("Maior Media: %s\n", mMedia(a).nome);

    return 0;
}
