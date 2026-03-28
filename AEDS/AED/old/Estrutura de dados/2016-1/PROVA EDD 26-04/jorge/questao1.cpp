#include<stdio.h>
#include<conio.h>
#include<iostream>
#define MAXTAM 5

void retiraTodos(TipoLista*Lista,Tipoitem item[MAXTAM]){
	int i;
	if(Vazia(*Lista)){
 printf(" posição nao existe");
	}
	else{
	for(i=0;i<MAXTAM;i++){
	 retira(&lista,item[i]);
	}
}
}
 void insereOrdenado(Tipoitem x,TipoLista*lista){
 	int i,j,aux;
 	for(i=1;i<MAXTAM-1;i--){
 	for(j=0;j<i;j++){
    if(vet[j]>vet[j+1]){
 	aux=vet[j];
 	vet[j]=vet[j+1];
 	vet[j+1]=aux;
			 }
		 }
	 }
 }
int main(){
	TipoLista lista;
	FLVazia(&lista);
	insereOrdenado( x,&lista);
	retiraTodos(&lista,x);
	getch();
	return 0;
}
