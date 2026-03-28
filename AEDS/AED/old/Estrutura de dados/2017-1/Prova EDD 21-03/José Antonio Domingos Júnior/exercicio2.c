#include<stdio.h>
#include<conio.h>
#include<string.h>
#define N 3
#define X 3

typedef struct{
    char nome[50];
    char matricula[6];
    float notas[X];
}Aluno;

void imprime(float media, char nome){

    if(media>=60){
        puts(nome);


    }

}

float maiorMedia(float notas[X], int X){

    int i;
    float media, soma, maior;
    for(i=0;i<X; i++){
            soma=0;
            media= 0;
    printf("\n\t\tInforme a nota do aluno na prova %d:\t", i+1);
    scanf("%f", &notas[i]);
        soma+= (notas[i])
        media=(soma/X);
        if(i==0){
            maior= media;
        }
        else{
            if(media>maior){
                maior= media;
            }
        }
    }

    return maior;

}





