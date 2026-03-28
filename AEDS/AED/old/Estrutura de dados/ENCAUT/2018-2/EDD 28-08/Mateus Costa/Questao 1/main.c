#include <stdio.h>
#include <stdlib.h>
#define N 3
typedef struct{

    char nome[60];

}compromisso;

typedef struct{

    int dia,mes,ano;

}data;
/*int proximoC(int data*,char compromisso[N]){




return 0;

}*/

int main()
{
    compromisso a[N];
    data p[N];
    int i;

    for(i=0;i<N;i++){
        printf("\nDigite o nome do seu compromisso: ");
        fflush(stdin);
        gets(a[i].nome);
        printf("\ndigite o dia: ");
        scanf("%d",&p[i].dia);
        printf("\ndigite o mes: ");
        scanf("%d",&p[i].mes);
        printf("\ndigite o ano: ");
        scanf("%d",&p[i].ano);
    }

      for(i=0;i<N;i++){
            printf("\n%s \n%d %d %d",a[i].nome,p[i].dia,p[i].mes,p[i].ano);
      }
    //proximoC(&p,a);

    return 0;
}
