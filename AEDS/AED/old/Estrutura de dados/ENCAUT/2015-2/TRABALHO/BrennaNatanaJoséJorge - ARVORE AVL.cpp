#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<stdlib.h>
#include<math.h>

typedef struct no {
	int valor, nivel, bal, altura; //valor=numero q será inserido
	no *esq, *dir;
}no;

typedef  no* tipoapontador ;

void balanceia(tipoapontador*);
void calcularbal(tipoapontador*);
int calcularaltura(tipoapontador);
void listarnivel (tipoapontador,int);
int retira(int,tipoapontador*);


 int insere(int valor,tipoapontador* x){
 	tipoapontador* aux;
 	aux=x;
 	int i=1;//inocio do nivel
	while(*aux!=NULL){
		i++;
	 	if(valor < (*aux)->valor){
	 		aux=&(*aux)->esq;
		 }
		 else{
		 	aux=&(*aux)->dir;
		 }
 	}
 	(*aux) = (tipoapontador) malloc(sizeof(no));
	(*aux)->valor = valor;
	(*aux)->nivel = i;
	(*aux)->bal = 0;
	(*aux)->esq=NULL;
	(*aux)->dir=NULL;//criando o nó da arvore


	calcularaltura(*x);
 	calcularbal(x);
 	listarnivel(*x,1);

}


tipoapontador rotacaoRR(tipoapontador y)
{
	tipoapontador x = y->dir;
	y->dir =x->esq;
	x->esq = y;
	return x;
}


tipoapontador rotacaoLL(tipoapontador y)
{
	tipoapontador x = y->esq;
	y->esq=x->dir;
	x->dir = y;
	return x;
}

void balanceia(tipoapontador *x){
		printf("\n");

	if((*x)->bal==2){
		if((*x)->esq->bal==-1){
			printf("R");
		    (*x)->esq=rotacaoRR((*x)->esq);

		}
		printf("L");
		*x=rotacaoLL(*x);
	}
	else if((*x)->bal==-2){
		if((*x)->dir->bal==1){
		    (*x)->dir=rotacaoLL((*x)->dir);
		    printf("L");
		}
		printf("R");
		*x=rotacaoRR(*x);

	}


}

int calcularaltura(tipoapontador a){
	int he,hd;
	if(a==NULL){
		return 0;
	}
	he=calcularaltura(a->esq);
	hd=calcularaltura(a->dir);

	if(hd>he){
		a->altura=hd+1;
		return hd+1;

	}
	else{
		a->altura=he+1;
		return he+1;
	}

}

void calcularbal (tipoapontador *x){

	int he,hd,bal;

	if((*x)->esq!=NULL){
		calcularbal(&(*x)->esq);
		he=calcularaltura((*x)->esq);

	}
	else
		he=0;


	if((*x)->dir!=NULL){
		calcularbal(&(*x)->dir);
		hd=calcularaltura((*x)->dir);
	}
	else
	    hd=0;

	bal=he-hd;
	(*x)->bal=bal;

	if(bal>1||bal<-1){
		balanceia(x);
	}

}

int busca(int valor1,tipoapontador x){
	tipoapontador aux=x;
	while(aux!=NULL){
		if(aux->valor==valor1){
			return 1;
		}
		else if(valor1>aux->valor){
		aux=aux->dir;
		}
		else if(valor1<aux->valor){
			aux=aux->esq;
		}
	}
	return 0;
}

void escreve(tipoapontador r) {
  if (r != NULL) {
    escreve(r->esq);

	printf("\n%d  nivel=(%d) altura=(%d) balanceamento=(%d)", r->valor,r->nivel,r->altura, r->bal);
    escreve(r->dir);
  }
}

void listarnivel (tipoapontador x,int n)
{
	if(x!=NULL){
		x->nivel=n;
		listarnivel(x->esq,n+1);
		listarnivel(x->dir,n+1);
	}
}


int retira(int x,tipoapontador *r){//retorna 0 se n conseguiu deletar, e 1 se conseguiu

	tipoapontador *aux=r;

	while((*aux)->valor!=x && (*aux)!=NULL){//buscando o valor na arvore para tentar retirar

		if((*aux)->valor>x)
			aux=&(*aux)->esq;
		if((*aux)->valor<x)
			aux=&(*aux)->dir;
	}

	if((*aux)==NULL)//nó n encontrado
		return 0;
	else// Nó encontrado
	{
		tipoapontador *filho=NULL;
		tipoapontador rest=NULL;
		// procurar qual filho irá substitui-lo
		if((*aux)->esq!=NULL){// tentar olhar na sub arvore esquerda

			filho=&((*aux)->esq);
			while((*filho)->dir!=NULL)//procurando o maior filho na subarvore esquerda
			{
				filho=&(*filho)->dir;
			}
			rest=(*filho)->esq;
		}
		else if(filho=&((*aux)->dir)){//tentar olhar na sub arvore direita

			filho=&((*aux)->dir);
			while((*filho)->esq!=NULL)//procurando o menor filho na subarvore direita
			{
				filho=&(*filho)->esq;

			}
			rest=(*filho)->dir;
		}

		if(filho!=NULL){//Se existe um filho para substituir

			//Substituindo pelo filho escolhido
			(*filho)->esq=(*aux)->esq;
			(*filho)->dir=(*aux)->dir;
			free(*aux);
			*aux=*filho;
			*filho=NULL;
		}
		else{// Se não existe um filho para substituir  (é uma folha)
			free(*aux);
			*aux=NULL;
		}
		calcularaltura(*r);
 		calcularbal(r);
 		listarnivel(*r,1);
		return 1;
	}

}


int main(){
	tipoapontador raiz=NULL;
	insere(3,&raiz);
	insere(4,&raiz);
	insere(5,&raiz);
//	escreve(raiz);
//	getch();
	insere(2,&raiz);
//	escreve(raiz);
//	getch();
	insere(1,&raiz);
//	escreve(raiz);
//	getch();
	insere(7,&raiz);
//	escreve(raiz);
//	getch();
	retira(6,&raiz);
//	escreve(raiz);
//	getch();
	insere(9,&raiz);
	insere(8,&raiz);
	insere(10,&raiz);
//	calcularaltura(raiz);

	escreve(raiz);

//	printf("\n\n%d",busca(3,raiz));



}



