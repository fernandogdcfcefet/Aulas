#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int pot(int k, int n)
{

    if(n == 0) return 1;
    else if(n == 1) return k;
         else return k* pot(k,n-1);
}
int main()
{
    setlocale(LC_ALL,"Portuguese");

    int k,n;

    printf("Insira o valor de k: ");
    scanf("%d",&k);
    printf("Insira o valor de n: ");
    scanf("%d",&n);
    printf("%d\n",pot(k,n));
    system("pause");
    return 0;
}
