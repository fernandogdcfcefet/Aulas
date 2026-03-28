#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10
char c[]={'*','-','>','?',1,2,3,4,5,6};

void desenha(int vet[]){
    int i,j;
    system("cls");
    for(i=0;i<TAM;i++){
        switch (vet[i]){
                case 1:
                    printf("%d\t",vet[i]);
                break;
                case 2:
                    printf("%d\t",vet[i]);
                break;
                case 3:
                    printf("%d\t",vet[i]);
                break;
                case 4:
                    printf("%d\t",vet[i]);
                break;
                case 5:
                    printf("%d\t",vet[i]);
                break;
                case 6:
                    printf("%d\t",vet[i]);
                break;
                case 7:
                    printf("%d\t",vet[i]);
                break;
                case 8:
                    printf("%d\t",vet[i]);
                break;
                case 9:
                    printf("%d\t",vet[i]);
                break;
                case 10:
                    printf("%d\t",vet[i]);
                break;
            }
        for(j=0;j<vet[i];j++){
            switch (vet[i]){
                case 1:
                    printf("%c",c[0]);
                break;
                case 2:
                    printf("%c",c[1]);
                break;
                case 3:
                    printf("%c",c[2]);
                break;
                case 4:
                    printf("%c",c[3]);
                break;
                case 5:
                    printf("%c",c[4]);
                break;
                case 6:
                    printf("%c",c[5]);
                break;
                case 7:
                    printf("%c",c[6]);
                break;
                case 8:
                    printf("%c",c[7]);
                break;
                case 9:
                    printf("%c",c[8]);
                break;
                case 10:
                    printf("%c",c[9]);
                break;
            }
        }
        printf("\n");
    }
//    _sleep(300);
    getchar();
}
void bubblesort(int vet[]){
    int i,j,aux;
    desenha(vet);
    for(i=0;i<TAM;i++){
        for(j=i;j<TAM;j++){
            if(vet[i]>vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
                desenha(vet);
            }
        }
    }
}

int main()
{
//    int vet[] ={10,4,6,8,9,2,3,5,1,7};
    int vet[] ={10,9,8,7,6,5,4,3,2,1};
//    int vet[] ={1,2,3,4,5,6,7,8,9,10};
    system("COLOR FC");
    bubblesort(vet);
    return 0;
}
