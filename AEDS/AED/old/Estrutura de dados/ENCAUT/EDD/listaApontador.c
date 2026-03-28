#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define TAM 3

int compara(char str1[],char str2[]){
    int i;
    for(i=0;str1[i]!='\0';i++){
        if(str1[i]>str2[i]){
            return -1;
        }else if(str1[i]<str2[i]){
            return 1;
        }
    }
    return 0;
}

typedef struct{
    char rua[50];
}endereco;

typedef struct {
    char nome[50];
    endereco end;
    int telefone;
}pessoa;

int main(){
        pessoa d[TAM];
        int i,j;

        for(i=0;i<TAM;i++){
            printf("nome\n");
            scanf("%s",&d[i].nome);
            printf("rua\n");
            scanf("%s",&d[i].end.rua);
//            printf("telefone\n");
//            scanf("%d",&d[i].telefone);
            system("cls");
        }
        for(i=0;i<TAM;i++){
            printf("Pessoas que moram na mesma rua de %s\n",d[i].nome);
            for(j=0;j<TAM;j++){
//                printf("%s:%s %s:%s\n",d[i].nome,d[i].end.rua,d[j].nome,d[j].end.rua);
                if(strcmp(d[i].end.rua,d[j].end.rua)==0&&!strcmp(d[i].nome,d[j].nome)==0){
                    printf("%s\n",d[j].nome);
                }
            }
            printf("\n");
        }
}
