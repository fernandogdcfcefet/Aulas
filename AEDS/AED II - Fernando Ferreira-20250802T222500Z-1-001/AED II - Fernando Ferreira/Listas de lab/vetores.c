/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

/**
 * Procedimento para imprimir um vetor de tamanho n
*/
void imprimeVetor (int v[], int n) 
{
    for (int i = 0; i < n; i++)
        printf("%d ", v[i]);
}


int main()
{
    printf("Hello World");
    
    int nota [10];      //declaração de um vetor de 10 posições (índice: 0 à 9)
    nota[0] = 10;       //atribuição do valor 10 na primeira posição do vetor (índice = 0)
    int a = nota[0];    //atribuindo à variável "a" o valor da primeira posição do vetor
    
    // Outras maneiras de inicializar vetores
    int num[5] = {10, 20, 30, 40, 50};      //declara e inicializa um vetor de 5 posições
    int v[] = {3, 4, 5};                    //declara e inicializa um vetor de 3 posições
    
    // inicialização do vetor
    for (int i = 0; i < 10; i++)
        nota[i] = 0;
    
    // imprimindo o vetor
    for (int i = 0; i < 10; i++)
        printf("%d ", nota[i]);
    
    // atribuindo valores para o vetor pelo teclado
    for (int i = 0; i < 10; i++)
        scanf("%d", &nota[i]);
    
    imprimeVetor(nota, 10);


    return 0;
}
