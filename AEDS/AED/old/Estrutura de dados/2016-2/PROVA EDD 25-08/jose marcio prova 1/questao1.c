#include<stdio.h>
#include<stdlib.h>
#define num 2

void lermatriz(int matriz[num][num]){

int i,j;

for(i=0;i<num;i++){
    for(j=0;j<num;j++){

        printf("DIGITE O ELEMENTO DA LINHA %d e COLUNA %d:" , i+1 , j+1);
        fflush(stdin);
        scanf("%d", &matriz[i][j]);

    }
}

}

void imprimirmatriz(int matriz[num][num]){

int i,j;

for(i=0;i<num;i++){
    for(j=0;j<num;j++){

        printf("O elemento da linha %d e coluna %d eh: %d \n\n " , i+1 , j+1 , matriz[i][j]);

    }

}

}



int norma(int matriz[num][num], int aux){

int i,j,numero;
int soma[num];


for(i=0;i<num;i++){
    for(j=0;j<num;j++){
        soma[i] = soma[i] + matriz[i][j]; //trasforma as posicoes da matriz emuma linha em um elemento do vetor soma
    }
}

int aux = 0;
for(i=0;i<num;i++){
    if(soma[i] > aux){

        aux = soma[i];
    }

}

return aux;
}



int main(){

int matriz[num][num];
int numero, aux;

lermatriz(matriz);

printf("\n\n--------------------------------------------------------\n\n");

imprimirmatriz(matriz);

norma(matriz,aux);

numero = norma(matriz , aux);

printf("A soma de maior valor das linhas eh: %d" , numero);


return 0;
}
