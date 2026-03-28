#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 3



typedef struct {
    int cod;
/* outros componentes */
} Item;

typedef struct {
    Item CP[MAXTAM] ; //CP igual a campo
    int Frente , Tras ,tam; 
} Fila ;

void FFVazia(Fila *F )
{   
   
    F->Frente = 1;
    F->Tras = F->Frente; 
     F->tam=0;
}

int Vazia(Fila F )
{   
    F.tam=0; 
    return ( F.Frente == F.Tras ) ;
}

void Enfileira (Item x , Fila *F )
{
    if ( F->tam == MAXTAM) 
        printf ( " Erro f i la est a cheia\n" ) ;
    else {
        F->CP[ F->Tras] = x;
        F->Tras = F->Tras % MAXTAM + 1; 
        F->tam++;
    }
}

void Desenfileira(Fila *F , Item *armazena)
{
    if (Vazia(*F ) )
        printf ( "Erro f i la esta vazia\n" ) ;
    else {
        *armazena = F->CP[ F->Frente];
        F->Frente = F->Frente % MAXTAM + 1;
        F->tam--;
    }
}


void imprime( Fila *F){ 
int i;
if(Vazia(*F)){
	printf(" A fila esta vazia");
} else { /*
	for(i=0;i<F->tam + 1;i++){
		printf("COD: %i \n",F->CP[i].cod);
		*/ 
		
		
		for(i=F->tam;i>0;i--){
		printf("COD: %i \n",F->CP[i].cod);
	}
}
}



int main()
{  

Fila f1; 

Item i1={2};
Item i2={2};
Item i3={2}; 
Item i4={2};

FFVazia(&f1);
printf("A pilha esta vazia---> %d \n",Vazia(f1));

Enfileira(i1,&f1);
Enfileira(i2,&f1);
Enfileira(i3,&f1); 
Enfileira(i4,&f1); 


printf("A pilha esta vazia---> %d \n",Vazia(f1));

imprime(&f1);





    return 0;
}
