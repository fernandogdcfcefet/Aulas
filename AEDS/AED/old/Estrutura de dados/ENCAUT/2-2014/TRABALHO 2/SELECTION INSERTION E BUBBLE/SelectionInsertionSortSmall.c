#include<stdio.h>
#include<time.h>


//constantes

#define TAM 50

#define PopUp 	   0
#define PopDown    1
#define SetaInicio 2
#define SetaFinal  3
#define Destaque1  4
#define Destaque2  5
#define MovUp 	   6
#define MovDown    7

int EFEITOS [7];
int SPEED = 10;
int AUTO = 0;




void tela (char* L,int time)
{
	int i=0;
	
	system("cls");
	
	printf("\n\n\n\t ");
	
	//escreve a letra que esta levantada "Up"
	
	
	for(i=0;i < ( EFEITOS[PopUp] + EFEITOS[MovUp] );i++)
		printf(" ");
		
	if(EFEITOS[PopUp]>=0)
		printf("%c",L[EFEITOS[PopUp]]-32 );
		
	printf("\n\t ");
	/////////////////////////////////////////
	
	
	
	//escreve a cadeia de letras ocultando a alta e a baixa "Up e Down" e destacando as marcadas
	for (i=0;L[i]!='\0';i++)
	{
		if ((i != EFEITOS[PopUp]) && (i != EFEITOS[PopDown]))
		{
			if ((i == EFEITOS[Destaque1]) || (i == EFEITOS[Destaque2]))
				printf("%c",L[i]-32);
			else
				printf("%c",L[i]);
		}
		else
			printf(" ");

	}
	printf("\n\t ");
	////////////////////////////////////////////////////////////////////////////////////////////
	
	
	
	//escreve a letra baixa "Down" e/ou o inicio da seta
	for(i=0;i < ( EFEITOS[PopDown] + EFEITOS[MovDown] );i++)
		printf(" ");

	if(EFEITOS[PopDown]>=0)
		printf("%c",L[EFEITOS[PopDown]]-32 );
		
	printf("\n\t ");
	/////////////////////////////////////////////////////
	
	
	
	//escreve o caminho da seta e a própria seta
	if (EFEITOS[SetaInicio] < EFEITOS[SetaFinal])//Verifica se a seta esta invertida
	{
		for(i=0;i < ( EFEITOS[SetaInicio] );i++)
			printf(" ");
			
		printf("|");
	
		
		for(;i < (EFEITOS[SetaFinal] - 1);i++)
			printf("_");
	
		printf("%c",24);
	}
	else if(EFEITOS[SetaInicio] > EFEITOS[SetaFinal])
	{
		for(i=0;i < ( EFEITOS[SetaFinal] );i++)
			printf(" ");
			
		printf("%c",24);
	
		for(;i < (EFEITOS[SetaInicio] - 1);i++)
			printf("_");
	
		printf("|");
	}
	// se a o inicio da seta coincidir com o final, a seta não é mostrada
	////////////////////////////////////////////
	
	
	// Calcula o tempo de espera em microsegundos multiplicando o tempo passado como argumento e a velocidade definida no inicio.
	if (AUTO==1)
		Sleep(time*SPEED);   // O tempo passado como argumento varia para que algumas animações tenham melhor visualização   
	else                           
		getch();
		
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	
}
// função comum de ordenação por inserção

void Insertion (char* A)
{	
	int i, j;
	char x=' ';
	
	A[0]=' ';
	
	// Animação
	EFEITOS[Destaque1] = 0;
	EFEITOS[PopDown] = -1;
	////////////////////////
		
	for ( i=2; A[i]!='\0'; i++)
	{
		x = A[ i ] ;
		j = i- 1;
		
		// Animação
		EFEITOS[Destaque2] = i;
		EFEITOS[SetaInicio] = i;
		EFEITOS[SetaFinal] = j; 
		tela(A,50);
		
		A[0] = x;/*sentinela*/
		A[ i ]=' ';
		
		// Animação
		EFEITOS[PopUp] = 0;// Nova letra a ser levantada
		EFEITOS[MovUp] = i;
		tela(A,50);
		
		while(x < A[ j ])
		{
			// Animação
			EFEITOS[SetaFinal] = j;
			EFEITOS[Destaque2] = j;
			tela(A,50);
			
			A[j+1] = A[ j ] ;
			A[j]=' ';
			
			// Animação
			tela(A,50);
			///////////
			
			j--;
			
		}
		// Animação
		while(EFEITOS[MovUp]>j+1)
		{
			EFEITOS[MovUp]--;
			tela(A,15);
		}
		///////////////
		
		A[j+1] = x;
		A[0]=' ';
		
		// Animação
		tela(A,100);
		///////////
	}
}


void Selection (char* A)
{
	int min,i,j;
	char aux;
	for (i=0;A[i]!='\0';i++)
	{
		min = i;
		
		// Animação
		EFEITOS[Destaque1] = i;
		EFEITOS[Destaque2] = i;
		EFEITOS[PopUp] = i;// Nova letra a ser levantada
		EFEITOS[PopDown] = -1;// Impede qualquer letra de começar abaixada
		EFEITOS[SetaInicio] = i;
		
		for (j=i;A[j]!='\0';j++)
		{
			// Animação
			EFEITOS[SetaFinal] = j;   // Move a seta e destaca a letra que está sendo checada
			EFEITOS[Destaque2] = j;
			
			if (A[min]>A[j])
			{
				min = j;
				
				// Animação
				tela(A,50);
				printf("%c",7);
				EFEITOS[PopDown] = j;   // animação demorada no momento em que a letra menor é encontrada
				tela(A,50);
			}
			else
				// Animação
				tela(A,20);      // se a letra não for menor a seta avança rapido (20)
		}
		tela(A,50);
		if(A[min]!=A[i])
		{
			// Animação
			EFEITOS[Destaque2] = min;
			
			int k, a , b;
			
			a=i;
			b=min;
			
			// Animação
			for(k=1;k<=(b-a);k++)
			{
				EFEITOS[MovUp]=k;
				EFEITOS[MovDown]=-k;
				tela(A,15);
			}
			
			tela(A,50);
			
			EFEITOS[MovUp]=0;
			EFEITOS[MovDown]=0;
			
			EFEITOS[PopDown] = -2;
			EFEITOS[PopUp] = -2;
			/////////////////////////
			
			aux = A[min];
			A[min] = A[i] ;
			A[i] = aux;
			
			
			
		}
		// Animação
		tela(A,80);
		
	}
}

void Bubble (char* A)
{
	
	char aux;
	int i, j, r;
	
	EFEITOS[PopUp]=-1;
	EFEITOS[PopDown]=-1;
	
	for(i=0;A[i]!='\0';i++)
	{  
		
		for(j=0; A[j+i+1]!='\0'; j++) 
		{
			EFEITOS[Destaque1]=j;
			
			EFEITOS[Destaque2]=j+1;
			
			tela(A,15);
			
			if(A[j]>A[j+1])
			{
				EFEITOS[PopUp]=j;
				EFEITOS[PopDown]=j+1;
				tela(A,50);
				
				EFEITOS[MovUp]=1;
				EFEITOS[MovDown]=-1;
				tela(A,50);
				
				EFEITOS[MovUp]=0;
				EFEITOS[MovDown]=0;
				EFEITOS[PopUp]=-1;
				EFEITOS[PopDown]=-1;
				
				aux = A[j];
				A[j] = A[j+1];
				A[j+1] = aux;
				 
				tela(A,50);
				
			}
		}
	}
}



int main ()
{
	char A[TAM],op=' ',sp;                 //={'a','s','d','x','f','n','g','j','i','p','m','t','w','e','c','u','b','r','h','q'};
	int i;
	
	system("color 0a");

    /////////////      MENU        //////////////////////////////////////////////////////////////////
    while(1==1)
    {
	    printf("\t\t.:: Representacao animada de Ordenacao ::.\n\n  Digite (I) - Insertion Sort\n         (S) - Selection Sort\n         (B) - Bubble Sort\n\n\t| ");
		scanf("%c",&op);
		getc(stdin);
		
		if (((op!='i'&&op!='I')&&(op!='s'&&op!='S'))&&((op!='b'&&op!='B')))
		{
			printf("  Letra invalida! #########");
			getch();
			system("cls");
		}
		else
			break;
	}

	printf("\n\n  Digite a palavra ou sequencia de numeros (Maximo 25 caracteres):\n\n\t| ");
	scanf("%s",A);
	getc(stdin);
	
	printf("\n\n  Animacao automatica? (s = Sim / 'OutraTecla' = Nao): \n\n\t| ");
	scanf("%c",&sp);
	getc(stdin);
	
	if(sp=='s')
	{
		AUTO=1;
		printf("\n\n  Digite a velocidade da animacao (entre 1 e 10):\n\n\t| ");
		scanf("%d",&SPEED);
		SPEED=11-SPEED;
	}
	else
		AUTO=0;

	
	//////////////////////////////////////////////////////////////////////////////////////////////
	
	if((op=='i')||(op=='I'))
	Insertion (A);
	
	if((op=='b')||(op=='B'))
	Bubble (A);
	
	if((op=='s')||(op=='S'))
	Selection (A);
	
	printf("\n\n");
	
	for (i=0;A[i]!='\0';i++)
		printf("%c",A[i]);
		
	getch();
}
