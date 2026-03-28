 #include <stdio.h>
 #include <stdlib.h>

 typedef struct{
     int dia, mes, ano;
} DATA;

int main(){
    int i;
    int TAM=0;

    printf("\nDigite o valor de TAM: ");
    scanf("%d", &TAM);

    DATA *datas = (DATA*)malloc(sizeof(DATA) * TAM);
    if (datas == NULL){
        printf ("** Erro: Memoria Insuficiente **"); exit(0);
    }
    for(i=0;i<TAM;i++){
        datas[i].dia = rand()%28 + 1;
        datas[i].mes = rand()%12 + 1;
        datas[i].ano = 2000 + rand()%18;
    }
    for(i=0;i<TAM;i++)
        printf("Dia: %d/%d/%d\n",datas[i].dia,datas[i].mes,datas[i].ano);

    free(datas);
    return 0;
}


