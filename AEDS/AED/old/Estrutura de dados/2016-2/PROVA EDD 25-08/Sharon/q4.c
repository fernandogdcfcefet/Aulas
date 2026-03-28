#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int divisao(int dividendo, int divisor, int *resto)
{
     /*int quociente=0;
     quociente=dividendo/divisor;
     resto=dividendo-(quociente*divisor);*/
     *resto=(dividendo%divisor);
     return dividendo/divisor;
}

int main()
{
    int dividendo=0, divisor=0,resto=0;

    printf("Informe o dividendo\t");
    scanf("%d",&dividendo);

    printf("Informe o divisor\t");
    scanf("%d",&divisor);


    printf("Resultado: %d Resto: %d",divisao(dividendo,divisor,&resto),resto); // não esta pegando o resto

    getch();
    return 0;

}
