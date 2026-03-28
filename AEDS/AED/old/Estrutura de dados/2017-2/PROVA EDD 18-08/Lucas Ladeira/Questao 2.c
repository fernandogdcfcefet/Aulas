#include<stdlib.h>

#define nAluno 2
#define nNotas 3

typedef struct{
	int matricula;
	char nome[40];
	float notas[3];
	float media[nAluno];
	
}Aluno;
Aluno a;
void Aprovado (a.media){
	if(media[nAluno]>=60) {
		puts(Aluno.nome);
	}
	
}

float MaiorMedia(){
	int i;
	float comp;
	for(i=0; i<nAluno; i++){
		if(i==0) comp=Aluno.media[i];
		if(comp<Aluno.media[i]) comp=Aluno.media[i];
	}
	return (comp);
}

int main(int argc, char** argv) {

	int i, j;
	float media[nNotas], total=0;
	for(j=0; j<nAluno; j++)
	{
		printf("Digite o nome:\n");
		gets(a.nome);
		printf("Digite matricula:\n");
		scanf("%d", &a.matricula);
		for(i=0; i<3; i++)
		{
			printf("Digite nota %d:\n ", i+1);
			scanf("%f", &a.notas[i]);
			total=total+a.notas[i];
		}
	a.media[i]=total/3;
	}
	Aprovado(a.media);
	printf("A maior media:%.2f \n", maiorMedia() );
	
	return 0;
}
