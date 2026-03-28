#include<stdio.h>
#include<string.h>
#define TAM 3
typedf strut{
char rua[20];

}endereco;
typedf strut{
struct endereco end;	
char nome[100];
int  telefone[13];
	

}pessoa;

void criente(pessoa d[tam]){
	
	int i,j;
	for(i=0;i<TAM;i++)
	{
		printf("Nome\n");
		scanf("%s",d[i].nome);
		printf("Rua\n");
		scanf("%s"d[i].end.rua);
		printf("Telefone\n");
		scanf("%d",&d[i].telefone);
		
	}
	for(i=0;i<TAM;i++)
	{
	  printf("Pessoas que moram na mesma rua de %s\n",d[i].nome);
	  for(j=0;i<TAM;i++)
	  {
		 if((strcmp(d[i].end.rua,d[j].end.rua)==o)&&(!strcmp(d[i].nome,d[j].nome))==0)
		 {
		 	printf("%S\n",d[j].nome);
		 }
	 }	
	}
}

int main()
{
	pessoa d[TAM];
	criente(d);
	
	
	
	return 0;
}
