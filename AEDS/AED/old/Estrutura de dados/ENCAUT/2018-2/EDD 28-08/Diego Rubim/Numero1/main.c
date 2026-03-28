#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N (5)(60)
void LeVetor(string N)
{
    int i;
    for(i=0;i<N;i++)
    {
    printf("Digite seu compromisso com descrição:\n");
    scanf("%s",&N[i]);
    printf("Digite o dia de seu compromisso:\n");
    gets(dia.data[i+1]);
    puts(dia.data[i+1]);
    printf("Digite o mes de seu compromisso:\n");
    gets(mes.data[i+1]);
    puts(mes.data[i+1]);
    printf("Digite o ano de seu compromisso:\n");
    gets(ano.data[i+1]);
    puts(ano.data[i+1]);
    }
}
int compromisso(int data[1], string N)
{
    return N[1];

}
typedef struct {
    int dia[2],mes[2],ano[4];
}Data;

int main()
{
    int s;
    Data data1,data2,data3,data4,data5;
    LeVetor(N);
    s = compromisso(data1,N);
    return 0;
}
