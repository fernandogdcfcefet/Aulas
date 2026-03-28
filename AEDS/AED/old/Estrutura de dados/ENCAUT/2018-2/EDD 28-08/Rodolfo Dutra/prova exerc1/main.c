#include <stdio.h>
#include <stdlib.h>
#define tam 60

typedef struct
{
   int dia;
   int mes;
   int ano;

}dat;

void leitura(char desc[tam])
{
    int i;
    dat compro[tam];
    for(i=0;i<tam;i++)
    {
        printf("Digite o nome do compromisso: ");
        gets(desc);

        printf("\nDigite a dia: ");
        scanf("%d",&compro[i].dia);

        printf("\nDigite o mes: ");
        scanf("%d",&compro[i].mes);

        printf("\nDigite o ano: ");
        scanf("%d",&compro[i].ano);
    }


}

void proximo(dat compro)
{

}



int main()
{
    char desc[tam];
    dat compro[tam];
    int i;

    leitura(desc[tam]);
    proximo(compro[tam]);

    return 0;
}
