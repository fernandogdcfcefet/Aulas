#include<stdio.h>
#include<conio.h>
#define MAXTAM 100
typedef int TipoApontador;

typedef int TipoChave;
typedef struct
{
	TipoChave Chave;
} TipoItem;
typedef struct {
	TipoItem Item[MAXTAM];
	TipoApontador Topo;

 } TipoPilha;
void FPVazia (TipoPilha *Pilha)
{
	Pilha ->Topo =0;
}

int Vazia (TipoPilha Pilha)
{
	return (Pilha.Topo ==0);
}

void Empilha ( TipoItem x, TipoPilha *Pilha)
{
	if (Pilha ->Topo ==MAXTAM)
	printf("erro ");
	else {
		Pilha ->Topo ++;
		Pilha ->Item [Pilha -> Topo -1] =x;
	}
}
void Desempilha (  TipoPilha *Pilha,TipoItem *Item)
{
	if (Vazia(*Pilha))
	printf("erro ");
	else {

		*Item = Pilha->Item [Pilha -> Topo -1];
		Pilha ->Topo --;
	}
}
int Tamanho( TipoPilha Pilha)
{
	return (Pilha.Topo);
}

void imprime( TipoPilha Pilha)
{
	int i;
	for(i=0;i<Pilha.Topo;i++)
	{
//		aux =Pilha.Topo;
		printf("%d\n",Pilha.Item[i].Chave);

//	 aux = aux ++;
    }

    printf("\n\n\n");
}






 int main(){
 	TipoPilha pilha1,pilha2,pilha3;
 	TipoItem item1,item2,item3;
 	 item1.Chave= 1;
	 FPVazia(&pilha1);
	 Vazia(pilha1);
 	 Empilha(item1,&pilha1);
 	 imprime(pilha1);
 	 item2.Chave= 2;
	 FPVazia(&pilha2);
 	 Vazia(pilha2);
 	 Empilha(item2,&pilha1);
 	 imprime(pilha1);
 	 item3.Chave= 3;
	 FPVazia(&pilha3);
 	 Vazia(pilha3);
 	 Empilha(item3,&pilha1);
 	 imprime(pilha1);
 	 Desempilha(&pilha1,&item3);
 	 Empilha(item3,&pilha3);
 	 imprime(pilha1);
 	 Desempilha(&pilha1,&item2);
 	 Empilha(item2,&pilha2);
 	 imprime(pilha1);
 	 Desempilha(&pilha3,&item3);
 	 Empilha(item3,&pilha2);
 	 imprime(pilha1);
 	 Desempilha(&pilha1,&item1);
 	 Empilha(item1,&pilha3);
 	 imprime(pilha1);
 	 Desempilha(&pilha2,&item3);
 	 Empilha(item3,&pilha1);
 	 imprime(pilha1);
 	 Desempilha(&pilha2,&item2);
 	 Empilha(item2,&pilha3);
 	 imprime(pilha1);
 	 Desempilha(&pilha1,&item3);
 	 Empilha(item3,&pilha3);
 	 imprime(pilha1);

 	 return 0;




 }
