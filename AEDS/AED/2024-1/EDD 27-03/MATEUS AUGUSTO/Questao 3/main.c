#include <stdio.h>
#include <stdlib.h>
#define TAM 3


typedef struct
{
    char rua;
    int numero;
} endereco;

typedef struct
{
    char nome;
    endereco end;
    int telefone;

} pessoa;

void preenche(pessoa *p)
{
    printf("Nome:\n");
  scanf("%s",&p->nome);

    printf("Rua:\n");
   scanf("%s", p->end.rua);
    printf("Nmr\n");
    scanf("%d",p->end.numero);
    printf("telefone:\n");
    scanf("%d",p->telefone);



}
void imprime(pessoa *p)
{

    printf("Nome:%s\n",p->nome);

    printf("Rua:%s\n",p->end.rua);

    printf("Nmr:%d\n",p->end.numero);

    printf("telefone:%d\n",p->telefone);

}

int main()
{

    pessoa d[TAM];
    int i,j;



    for (i=0; i<TAM; i++)
    {
        preenche(&d[i]);
    }

    for (i=0; i<TAM; i++)
    {
        imprime(&d[i]);

    }

    for (i=0; i<TAM; i++)
    {

        pritnf("pessoas que moram na msm rua de %s\n", d[i].nome);
        for (j=0; j<TAM; j++)
        {
            if(strcmp(d[i].end.rua,d[j].end.rua)==0) && (!(strcmp(d[i].end.rua,d[j].end.rua))==0)
            {


                printf("%s\n",d[j].nome);

            }



        }

    }




    return 0;
}
