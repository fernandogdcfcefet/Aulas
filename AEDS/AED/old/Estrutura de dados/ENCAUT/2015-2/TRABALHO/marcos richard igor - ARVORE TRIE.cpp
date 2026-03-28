#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct TipoNo{
  char letra;
  struct TipoNo *direita;
  struct TipoNo *esquerda;
  char restoCodigo[9];
} TipoNo;

TipoNo *criaArvore(){
  return NULL;
}

void tira1 (char str[]) {
	int i;
	for( i = 0; str[i]!='\0';i++){
		str[i]=str[i+1];
	}
}

int VerificaVazia(TipoNo *Arvore){
  if ( Arvore==NULL){
  	return 1;
  }else{
  	return 0;
  }
}

void inserir (TipoNo **no, char l, char* cod){
  if(*no==NULL)
  {
    *no = (TipoNo*)malloc(sizeof(TipoNo)); /* Aloca memória para a estrutura */
    (*no)->esquerda = NULL; /* Subárvore à esquerda é NULL */
    (*no)->direita = NULL; /* Subárvore à direita é NULL */
    (*no)->letra = l; /* Armazena a informação */
    strcpy((*no)->restoCodigo, cod);

	}else if((*no)->restoCodigo[0]!='\0'){

  	char auxL = (*no)->letra;
  	char auxResto[9];
  	strcpy(auxResto , (*no)->restoCodigo);
  	
  	(*no)->letra='\0';
  	(*no)->restoCodigo[0]='\0';
  	
  	inserir(&(*no), auxL, auxResto);
    inserir(&(*no), l,cod);


  	}else if (cod[0] == '0'){
		tira1(cod);
  	  	inserir (&(*no)->esquerda,l,cod);
  	}

  	else if(cod[0] == '1'){
  	  	tira1(cod);
  	  	inserir (&(*no)->direita,l,cod);
	}
}

void imprime(TipoNo* arv){
	if(arv->esquerda!=NULL){
    	printf("0-");
    	imprime(arv->esquerda);
	}

	if((arv->direita==NULL)&&(arv->esquerda==NULL)){
   		printf(" %c %s\n",arv->letra,arv->restoCodigo);
    }

	if(arv->direita!=NULL){
		printf("1-");
    	imprime(arv->direita);
	}
}

void imprimirArvore(TipoNo* arv){
	imprime(arv);
	printf("\n");
	getch();
}

void busca(TipoNo *arv, char le){  // aqui a busca mostra a posição da letra em relação ao no pai
	if(arv->esquerda!=NULL){
        if(arv->esquerda->letra == le)
		{
			printf("Letra Encontrada na esq\n");		
	    }
	    else{
			busca(arv->esquerda, le);
		}
	}

	if(arv->direita!=NULL){
        if(arv->direita->letra == le)
		{ 
			printf("Letra Encontrada na dir\n");		
	    }else{
			busca(arv->direita, le);
		}
	}    
}

int buscaBIN(TipoNo *arv, char *cod){   // aqui é feita a busca realmete	        
		if(cod[0]=='0')
		{		
			if(arv->esquerda!=NULL){
		      tira1(cod);
			  return buscaBIN(arv->esquerda, cod);	
			}    	    
       	}    	
    	
    	if(cod[0]=='1')
		{
		
			if(arv->direita!=NULL){
		     tira1(cod);
			 return buscaBIN(arv->direita, cod);	
			}	    
    	}
    	
    	if(strcmp(cod,arv->restoCodigo)==0){
            //printf("Letra presente: %c \n",arv->letra);
    	    return 1;	
		} else return 0;
}

void buscaPorCod(TipoNo *arv, char *cod, char L){ // aqui é feita a busca para exibir pro usuario (DEVE SER USADO PARA EVITAR QUE A STRING COD MUDE)
	
	if(VerificaVazia(arv)==1){
    	printf("Arvore VAZIA, nao ha o que retirar!\n\n");
    	return;
	}
	
	char c[9]; 
    strcpy(c,cod);
	
	if(buscaBIN(arv,c)==1){
		printf("Letra: %c Presente!\n",L);
		getch();
	}else{
		printf("Letra: %c AUSENTE!\n",L);
		getch();
	}
}

void insereLetra(TipoNo **no, char l, char* cod){   //pra poder parar de "comer" as letras dos codigos pre defidos.
	char codEnvia[9], codTeste[9];
    strcpy(codEnvia,cod);
    strcpy(codTeste,cod);
    
    if(VerificaVazia(*no)==1){   //verifica se a arvore esta vazia.
		printf("LETRA (%c) INSERIDA COM SUCESSO\n\n",l);
		inserir(&(*no),l,codEnvia);
		return;
	}
    
	if(buscaBIN((*no), codTeste)==1){
		printf("LETRA (%c) JA INSERIDA\n\n",l);
	}else{
		printf("LETRA (%c) INSERIDA COM SUCESSO\n\n",l);
		inserir(&(*no),l,codEnvia);
	}
}


void retirar(TipoNo **arv, char *cod){
	if(strcmp((*arv)->restoCodigo,cod)==0){
		printf("Letra: %c excluida\n",(*arv)->letra);
		*arv=NULL;
		
	}
	else if (cod[0] == '0'){
				tira1(cod);
  	  	   	     retirar(&(*arv)->esquerda,cod);
  	  	   	}

  	else if(cod[0] == '1'){
  	  	   		tira1(cod);
  	  	   	 	 retirar (&(*arv)->direita,cod);
		   }
}

void retiraLetra (TipoNo **arv, char *cod){
	
    if(VerificaVazia(*arv)==1){
		printf("Arvore VAZIA, nao ha o que retirar!\n\n");
		return;
    }
	char codEnvia[9], codTeste[9];
	strcpy(codEnvia,cod);
	strcpy(codTeste,cod);
	
	if (buscaBIN((*arv),codEnvia)==0){
		printf("Letra Inexistente\n");
		
	} else retirar (&(*arv),codTeste);
}

int main(){
    char A[]="11010"; char J[]="10100"; char S[]="10111";
    char B[]="01011"; char K[]="10011"; char T[]="00100";
    char C[]="11000"; char L[]="01111"; char U[]="11001";
    char D[]="11111"; char M[]="01010"; char V[]="11101";
    char E[]="10010"; char N[]="10110"; char W[]="10000";
    char F[]="00001"; char O[]="00000"; char X[]="00010";
    char G[]="11011"; char P[]="10001"; char Y[]="01100";
    char H[]="01110"; char Q[]="10101"; char Z[]="00011";
    char I[]="11110"; char R[]="00110";
    
    TipoNo* arvore = criaArvore(); /* cria uma árvore */
    retiraLetra(&arvore,E);
    buscaPorCod(arvore,G,'G');
    
	if(VerificaVazia(arvore)==1){   //verifica se a arvore esta vazia.
		printf("Arvore VAZIA\n\n");
	}else{
		printf("Arvore CHEIA\n\n");
	}

	insereLetra(&arvore, 'A',A);
	imprimirArvore(arvore);

    insereLetra(&arvore, 'B',B);
    imprimirArvore(arvore);

	insereLetra(&arvore, 'C',C);
	imprimirArvore(arvore);

	insereLetra(&arvore, 'D',D);
	imprimirArvore(arvore);

	insereLetra(&arvore, 'E',E);
	imprimirArvore(arvore);
	
	insereLetra(&arvore, 'F',F);
	imprimirArvore(arvore);
	


	
    buscaPorCod(arvore,A,'A');	

	buscaPorCod(arvore,E,'E');

    buscaPorCod(arvore,F,'F');
    
    buscaPorCod(arvore,G,'G');

    printf("\n");
    

	insereLetra(&arvore, 'G',G);
	imprimirArvore(arvore);
	
	
	buscaPorCod(arvore,G,'G');
	printf("\n");
	
	retiraLetra(&arvore,A);
	printf("\n");
	imprimirArvore(arvore);
	
	retiraLetra(&arvore,E);
	printf("\n");
	imprimirArvore(arvore);
	
    buscaPorCod(arvore,A,'A');
    buscaPorCod(arvore,E,'E');
    printf("\n");
    
	insereLetra(&arvore, 'A',A);
	imprimirArvore (arvore);
	
	insereLetra(&arvore, 'E',E);
	imprimirArvore (arvore);		
    
    buscaPorCod(arvore,A,'A');
    buscaPorCod(arvore,E,'E');
    return 0;

}


