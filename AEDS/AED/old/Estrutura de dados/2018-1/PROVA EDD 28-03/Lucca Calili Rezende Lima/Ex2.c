#include <stdio.h>
#include <stdlib.h>
#define N 3
#define X 4

typedef struct{
    char rua;
    char cidade;
}Endereco;

typedef struct{
int matricula;
char nome;
Endereco endereco;
int notas[X];

}Aluno;

void entrar_com_dados(Aluno aluno[N]){

    for(int i=0;i<N;i++){
        for(int j=0;j<X;j++){

            printf("\nmatricula:\n");
            scanf("%d", & aluno[i].matricula);

            printf("\nEndereco(rua, cidade):\n");
            scanf("%d", & aluno[i].endereco.cidade);
            scanf("%d", & aluno[i].endereco.rua);

            printf("\nnotas:\n");
            scanf("%d", & aluno[j].notas);
        }
    }
}

char maior_media_geral(Aluno aluno[N]){
        char aluno_maior_media;
        float nota=0;
        float media[N];
        for(int i=0;i<N;i++){

            for(int j=0;j<X;j++){
                   nota = nota + aluno[i].notas[j];
            }
            media[i] = nota/X;

            nota =0;
        }

       for(int i=0;i<N;i++){
       if(media[i]<=media[i+1]){
       aluno_maior_media = aluno[i].nome;
       }

       }
    return aluno_maior_media;
}

void aprovado(Aluno aluno[N]){

       char aluno_maior_media;
        float nota=0;
        float media[N];
        for(int i=0;i<N;i++){

            for(int j=0;j<X;j++){
                   nota = nota + aluno[i].notas[j];
            }
            media[i] = nota/X;

            nota =0;
        }

             for(int i=0;i<N;i++){
                    if(media[i]>=6){
                        printf("aprovado");
                    }else{
                    printf("nao aprovado");
                    }

             }

}



int main()
{
    Aluno aluno[N];
    printf("Hello world!\n");
    return 0;
}
