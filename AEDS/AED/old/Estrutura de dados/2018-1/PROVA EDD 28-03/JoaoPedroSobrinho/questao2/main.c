#include <stdio.h>
#include <stdlib.h>
#define N 2
#define X 3

typedef struct Endereco{
    char rua[100];
    char cidade[100];
}Endereco;

typedef struct Aluno{
    char matricula[10];
    char nome[100];
    int notas[X];
    Endereco endereco;
}Aluno;

void LeInformacoes(Aluno *a);
Aluno MaiorMedia(Aluno *a);
void Aprovacoes(Aluno *a);

int main(){
    Aluno a[N], maiorMedia;
    LeInformacoes(a);
    printf("\n\nAluno de maior media e: %s\n\n", MaiorMedia(a).nome);
    Aprovacoes(a);
    return 0;
}

void LeInformacoes(Aluno *a){
    int i, j, nota;
    printf("\t\tInformacoes\n");
    for(i=0; i<N; i++){
        printf("Aluno %d\n", i+1);
        fflush(stdin);
        printf("Nome: ");
        gets(a[i].nome);
        fflush(stdin);
        printf("Matricula: ");
        gets(a[i].matricula);
        fflush(stdin);
        printf("Cidade: ");
        gets(a[i].endereco.cidade);
        fflush(stdin);
        printf("Rua: ");
        gets(a[i].endereco.rua);
        printf("Digite as notas\n");
        for(j=0; j<X; j++){
            printf("Nota %d: ",j+1);
            scanf("%d", &a[i].notas[j]);
            if(a[i].notas[j]<0 || a[i].notas[j]>10){
                printf("Valor errado!!!\n");
                j--;
            }
        }
    }
}

Aluno MaiorMedia(Aluno *a){
    int i, j, media=0, maiorMedia = 0, posicaoMmedia;
    for(i=0; i<N; i++){
        for(j=0; j<X; j++)
            media = media + a[i].notas[j];
        media = media/3;
        if(media > maiorMedia){
            maiorMedia = media;
            posicaoMmedia = i;
        }
        media = 0;
    }
    return a[posicaoMmedia];
}

void Aprovacoes(Aluno *a){
    int i, j, media = 0;
    printf("Alunos aprovados ou reprovados\n");
    for(i=0; i<N; i++){
        for(j=0; j<X; j++)
            media = media + a[i].notas[j];
        media = media/3;
        printf("%d", media);

        if(media<6)
            printf("Aluno %s REPROVADO\n", a[i].nome);
        else
            printf("Aluno %s APROVADO\n", a[i].nome);
        media = 0;
    }
}
