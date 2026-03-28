#include <stdio.h>
#include <stdlib.h>

void siftDown( int vet[], int start, int end)
{
    int root = start,aux,i;

    while ( root*2+1 < end ) {
        int child = 2*root + 1;//pega a segunda posiçãp como filho
        if ((child + 1 < end) && vet[child]<vet[child+1]) {//cada pai tem dois filhos, nessa função compara qual filho é o meior e o seleciona
            child++;
        }
        if (vet[root]< vet[child]) {// nessa parte ele verica e o pai é menor que o filho, caso se seja ele efetua a troca
            aux=vet[child];
            vet[child]=vet[root];
            vet[root]=aux;
            root = child;// o filho passa a ser o pai para continuar a construção da árvore
            getch();
            for(i=0;i<end;i++){//imprime a árvore
                    if(i==0)
                        printf("     ");
                    if(i==1)
                        printf("   ");
                    if(i==2){
                        printf(" ");
                    }
                        printf(" %d ",vet[i]);

                    if(i==0||i==2||i==6){
                        printf("\n");
                    }
            }
            printf("\n\n\n\n\n");
        }
        else
          return;
    }
}

void heapsort( int vet[], int n)
{
    int cont=6,start, end, aux,i,vet1[7];
    for (start = (n-2)/2; start >=0; start--) {// essa parte pega a raiz mais distante, qua seria o ultimo possível pai
        siftDown( vet, start, n);
    }

    for (end=n-1; end > 0; end--) {// realiza a troca entre o elemento já ordenado com o último
        aux=vet[end];
        vet[end]=vet[0];
        vet[0]=aux;
        getch();
        for(i=0;i<=end;i++){//imprime a árvore
                    if(i==0)
                        printf("     ");
                    if(i==1)
                        printf("   ");
                    if(i==2)
                        printf(" ");

                    if(i==end){//o x ocupa o lugar do elemento que foi retirado, que está ordenado
                        printf(" X\n\n");
                    }
                    else{
                        printf(" %d ",vet[i]);
                    }

                        cont++;


                    if(i==0||i==2||i==6){
                        printf("\n");
                    }
            }
            for(i=0;i<7;i++){//imprime o vetor durante a execulsão, mostrando os elementos ordenados
                            if(i>=end){

                                printf("[%d]",vet[i]);
                            }
                            else{
                                printf("[ ]");
                            }
                        }

            printf("\n\n\n\n\n");
        siftDown(vet, 0, end);
    }
}
int main(){
int tam,i;
printf("Informe o tamanho do vetor \n");
scanf("%d",&tam);
int vet[tam];
    for(i=0;i<tam;i++){
        printf("Digite um numero  >> ");
        scanf("%d",&vet[i]);
    }
    printf("\n");
    for(i=0;i<tam;i++){
    printf(" %d ",vet[i]);
    }
    printf("\n\n");
    getch();
    heapsort(vet,tam);
    printf(" %d ",vet[i]);
    for(i=0;i<tam;i++){
    printf(" %d ",vet[i]);
    }
    printf("\n");
    system("pause");
}

