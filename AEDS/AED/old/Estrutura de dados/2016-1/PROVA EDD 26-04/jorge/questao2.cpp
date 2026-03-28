#include<stdio.h>
#include<conio.h>
void enfileira(Tipoitem item,TipoFila*Fila){
while(Fila->Tras%MAXTAM+1!=Fila->Frente-1){
Fila->item{Fila->Tras-1}=x;
 Fila->Tras=Fila->Tras%MAXTAM+1;
	}
}
void imprime(TipoFila*Fila){
	tipoapontador aux;
	While(aux!=Fila->Tras%MAXTAM+1==Fila->Frente){
	printf(Fila->item[aux].Chave);
}
}
int main(){
	getch();
	return 0;
}
