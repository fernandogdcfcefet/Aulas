#include <stdio.h>
#include <stdlib.h>


/*------------------------------------------------------------------------------
2- a) função recursiva que imprimir os elementos na ordem em que se encontram
armazenados (isto é, A[0], A[1], . . ., A[n]);
------------------------------------------------------------------------------*/
void imprimeVetor (int A[], int n)
{
   if (n > 0)
   {
      printf("%d ", A[0]);
      imprimeVetor (&A[1], n-1);
   }
}

/*------------------------------------------------------------------------------
2- b) função recursiva que imprimir os elementos na ordem inversa
(isto é, A[n-1], A[n-2], . . ., A[0]);
------------------------------------------------------------------------------*/
void imprimeInvertido (int A[], int n)
{
   if (n > 0)
   {
      printf("%d ", A[n-1]);
      imprimeInvertido (A, n-1);
   }
}

/*------------------------------------------------------------------------------
2- c) função recursiva que calcula o somatório do valor de todos os elementos;
------------------------------------------------------------------------------*/
int somatorio(int A[], int n)
{
   if (n == 0)
      return 0;
   else
      return (A[0] + somatorio(&A[1], n-1));
}

/*------------------------------------------------------------------------------
2- d) função recursiva que Calcula a média do valor de todos os elementos.
------------------------------------------------------------------------------*/
float media(int A[], int n)
{
  float resultado;
  if (n == 0)
     return 0;
  else
     resultado = (A[0] + media(&A[1],n-1)* (n-1)) ;

  return (resultado/n);

}

/*------------------------------------------------------------------------------
3- Função recursiva para testar se um determinado número inteiro foi ou não
armazenado em um vetor.
------------------------------------------------------------------------------*/
int procuraElemento (int A[], int n, int x)
{
   int elem = 0;
   if (n == 0)
      return 0;
   else
   {
      if (x == A[0])
         elem = 1;
      else
         elem = procuraElemento (&A[1], n-1, x);

      return elem;
   }
}

/*------------------------------------------------------------------------------
4- Função recursiva para contabilizar o número de comparações com elementos do
vetor que são realizadas por ela durante a pesquisa a um elemento.
------------------------------------------------------------------------------*/
int numerosDeComparacoes (int A[], int n, int x)
{
   if (n > 0)
   {
      if (x == A[0])
         return 1;
      else
         return (1 + numerosDeComparacoes(&A[1], n-1, x));
   }
   else
      return 0;
}

/*------------------------------------------------------------------------------
5- Função recursiva para verificar se uma palavra é palíndromo
------------------------------------------------------------------------------*/
int palindromo (char A[], int i, int f)
{
   if (i >= f)
        return 1;
   if(A[i] == A[f])
        palindromo(A, i+1, f-1);
   else
        return 0;
}

/*------------------------------------------------------------------------------
Faça uma função recursiva para calcular (e imprimir) os elementos da seguinte
sequência: 1 + 1/2 + 1/3 + ... + 1/n
------------------------------------------------------------------------------*/
float sequencia (int n)
{
    if (n == 1)
        return 1;
    else
        return 1.0/n + sequencia(n-1);
}

int main()
{
    int A [] = {1, 2, 3, 4, 5};
    int n = 5;

    char palavra[] = "aabaa";

    imprimeVetor (A, n);
    printf("\n");
    imprimeInvertido (A, n);
    printf("\n%d", somatorio(A, n));
    printf("\n%f", media(A, n));

    printf("\n\nProcura elemento");
    printf("\n%d", procuraElemento (A, n, 3));

    printf("\n\nVerifica Palíndromo");
    printf("\n%d", palindromo (palavra, 0, 4));

    printf("\n\nSequencia");
    printf("\n%f", sequencia (5));


    return 0;
}
