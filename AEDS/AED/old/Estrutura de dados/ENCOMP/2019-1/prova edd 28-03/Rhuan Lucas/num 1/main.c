#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Data;

//typedef struct{
//char desc1[61];
 //   Data data1;
//}
void compromisso(Data dia1,int vetcom[10], char desc1[61]){
    int cont;
    Data cdata;
    for(cont=0;cont<vetcom;cont++){
        dias(dia1);
        printf("dia: %d/%d/%d\ncompomisso: %s\n",cdata.dia,cdata.mes,cdata.ano,desc1[cont]);
    }
}

int dias(int x, int y, int z){
    int aux=0;
    aux=x;
    aux+=(y*30);
    aux+=(z*365);
    return aux;
}

int main()
{
    char desc[61];
    Data compData;
    int i, vet[10];
    for(i=0;i<vet;i++){

    printf("Data: ");
    scanf("%d",&compData.dia);
    scanf("%d",&compData.mes);
    scanf("%d",&compData.ano);
    getchar();
    printf("Descreva o compromisso: ");
    gets(desc);

    }
    compromisso(compData,vet,desc);

    return 0;
}
