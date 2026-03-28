#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<iostream>
#define TAM 3
typedef struct{
	char rua[30];
	char bairro[30];
	int numero;
	char cidade[30];
	int cep;
}endereco;
typedef struct{
	char nome[20];
	int telefone;
	endereco end;
}pessoa;
int main(){
	endereco end;
	pessoa d[TAM ];
	getch();
	return 0;
}
