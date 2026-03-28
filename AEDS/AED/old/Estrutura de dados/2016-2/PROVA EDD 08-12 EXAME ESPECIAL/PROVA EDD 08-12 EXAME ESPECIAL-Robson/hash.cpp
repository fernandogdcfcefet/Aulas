#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 5
#define INICIOARRANJO 0


typedef struct {
	int chave;
	char nome[30];
}TipoItem;

typedef struct {
	TipoItem item [MAXTAM];
	int tam;
}TipoTabela;

int fun_hash(char str[]){
	int i, cont=0;
	for(i=0;i!='\0';i++){
		cont+=str[i];		
	}
	return (cont % MAXTAM);	
}
void cria_hash(TipoTabela *table){
	int i;
	table->tam=INICIOARRANJO;
	for(i=0;i<MAXTAM;i++){
		table->item[i].chave = 0;		
	}
	
}

void insere(TipoItem x, TipoTabela *h){
	h->item[fun_hash(x.nome)] = x;
}

int busca(TipoItem x, TipoTabela h){
	int i;
	for(i=0;i<MAXTAM;i++){
		if(fun_hash(x.nome) == i && h.item->chave !=0){
			printf("elemento encontrado");
			return fun_hash(x.nome);	
		} 		
	}
	return 1;
}
int main(){
	 return 0;	
}


