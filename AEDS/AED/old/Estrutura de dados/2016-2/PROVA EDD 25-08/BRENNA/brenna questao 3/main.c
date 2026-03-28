#include<stdio.h>
#include<conio.h>
#define TAM 3
typedef struct{
  char rua[30];


}endereco;


typedef struct{
  char nome[30];
  int telefone;
  endereco end;


}pessoa;



  int main(){
     pessoa d[TAM];
     int i,j;
     for (i=0;i<TAM;i++){
        printf("NOME:\n");
        scanf("%s",&d[i].nome);
        fflush(stdin);
        printf("rua:\n");
        scanf("%s",&d[i].end.rua);
         fflush(stdin);
        printf("telefone:\n");
        scanf("%d",&d[i].telefone);
         fflush(stdin);
        }
        for(i=0;i<TAM;i++){
            printf("pessoas %s\n" ,d[i].nome);
            for(j=0;j<TAM;j++)
                {
                    if((strcmp(d[i].end.rua,d[j].end.rua)==0)&& (!(strcmp(d[i].nome,d[j].nome))==0))//essa linha faz a comparação se duas pessoas moram na mesma rua e possuem nomes diferentes
                        {
                            printf("%s\n",d[j].nome);

                    }

                }




        }


















return 0;

}
