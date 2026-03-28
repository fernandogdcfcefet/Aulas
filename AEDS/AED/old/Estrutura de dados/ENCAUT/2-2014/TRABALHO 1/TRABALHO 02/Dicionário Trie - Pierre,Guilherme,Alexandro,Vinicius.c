#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ALFABETO 27    

typedef struct nodo* point;

typedef struct nodo
{
	int fim;                // na cabeca é usado para salvar a quantidade de palavras
	int pos;
	int numfilhos;
	char *sig;
	point filho[ALFABETO];
	
}nodo;

point checar (point cabeca, char* word)    //funcao responssavel por checar a letra mais proxima da palavra desejada no dicionario, retornando um apontador para essa letra
{
	point aux = cabeca;
	int i = 0;
	
	while((word[i]) != '\0')                //percorre a string dada. 
	{
		int num = word[i]-97;               //transforma a letra em um numero correspondente para ser usado na busca   a=0 b=1 c=2 ...
		
		if (aux->filho[num] == NULL)        //verifica se a letra procurada existe
		{
			return aux;
		}
		else
		{
			aux = aux->filho[num];          // Avança pelas letras corretas do dicionario
		}
		i++;
		
	}
	return aux;
}

void iniciaCabeca(point a)                   // esssa função é um especifica para a raiz ou "cabeca" do dicionario, é usada na hora de começar um dicionario novo.
{
	int i;
	for(i=0;i<ALFABETO;i++)                  //inicia os filhos da cabeca como NULL
	{
		a->filho[i]=NULL;
	}
	a->numfilhos=0;
	a->fim = 1;
	a->pos = -1;							// A cabeca tem posição -1 nas palavras enquanto as primeiras letras tem posição 0,1,2...
}

void inicia(point a)                        // Iniciação das letras comuns do dicionario. Comandos parecidos com a iniciação da cabeça,
{											// porém não define uma posição inicial
	int i;
	for(i=0;i<ALFABETO;i++)
	{
		a->filho[i]=NULL;
	}
	a->numfilhos=0;
	a->fim=0;		
}


int estaVazio (point cabeca)               //verifica se o dicionario esta vazio
{
	return(cabeca->fim==1);
}

void insere (point cabeca, char* letras, char* sig)           //insere uma palavra no dicionario e um significado para essa palavra 
{
	point ponta = checar(cabeca,letras);                     // Variavel auxiliar 'ponta' usa a função checar para descobrir se sa existe parte da palavra no dicionario ou ele completa.
	
	int pos = ponta->pos;                                    // a letra mais proxima da palavra que se quer inserir tem sua posição marcada, essa posição é salva em 'pos'
	
	if (letras[pos+1]=='\0')                                 // verifica se a posição da letra mais proxima bate com a ultima letra da palavra. 
	{
		if(ponta->fim!=0)                                    // e se essa letra é fim de uma palavra. Se sim, então essa palavra ja existe totalmente no dicionario.
		{
			printf("Essa palavra ja existe no dicionario");
		}
		else                         //caso a palavra exista mas sua ultima letra n esta definida como fim, sabemos que a palavra existe dentro de uma outra palavra como um prefixo. EX: abacate existe dentro de abacateiro.                             
		{
			ponta->fim = !0;         // definimos essa letra como um fim e garantimos que essa palavra seja considerada dentro do dicionario.
			
			ponta->sig = sig;        // adiciona o significado dado à palavra.
			
			cabeca->fim++;           // aumenta-se o contador de palavras do dicionario
			
			printf("\n Palavra %s adicionada.",letras);
		}
		
	}
	else                                                  // caso a palavra não exista totalmente no dicionario,
	{
		int num;
		
		while(letras[pos+1]!='\0')                        //varremos a parte da palavra que não exite no dicionario, para adicionar as novas letras
		{
			num = letras[pos+1]-97;
			ponta->numfilhos++;
			ponta->filho[num] = (point)malloc(sizeof(nodo));
			ponta = ponta->filho[num];
			inicia(ponta);
			ponta->pos = pos+1;
			pos++;
		}
		
		ponta->fim = !0;                                  //Mesma finalização de palavra da linha 85
		
		ponta->sig = sig;
		
		cabeca->fim++;
		
		printf("\n Palavra %s adicionada.",letras);
		
	}	
}



int remover (point cabeca, char* letras)					      // procura a palavra no dicionario, caso exista, a palavra é deletada e o retorno é true, caso contrario o retorno é false.
{
	if(estaVazio(cabeca))
	{
		printf("Dicionario vazio!");                             //verifica se o dicionario esta vazio para evitar checagem desnecessaria.
		
		return 0;
	}
	
	point ponta = checar(cabeca,letras);
	
	int pos = ponta->pos;
	
	if ((ponta->fim==0)||(letras[pos+1]!='\0'))				     // verifica se a ultima letra foi encontrada e se ela esta marcada como o fim de uma palavra (checa o contrario)
	{
		printf("\nEssa palavra não existe no dicionario.\n");
		
		return 0;
	}
	else														// palavra encontrada no dicionario
	{
		if(ponta->numfilhos!=0)									// se existir uma cadeia de letras a frente dessa palavra, nada é deletado e a ultima letra deixa de ser um fim.
		{
			ponta->fim=0;
			
		}
		else													// caso essa letra não tenha sequência, então a palavra começa a ser deletada pela ponta, até encontrar uma letra que tmb pertenca a outra palavra.
		{
			int num=0;
			do
			{
				num = letras[pos]-97;
				letras[pos]='\0';
				ponta=checar(cabeca,letras);
				free(ponta->filho[num]);
				ponta->filho[num]=NULL;
				ponta->numfilhos--;
				printf(".");
				
			}while((ponta->fim==0) && (ponta->numfilhos==0));  // verifica se a letra pertence à outra palavra   (se ela é o fim de uma palavra e se ela tem uma bifurcação)
			
		}
		
		cabeca->fim--;                                        //diminui o contador de palavras
		
		printf("\n  Palavra '%s' deletada!",letras);
		
		return 1;
		
	}

}


int dicionarioTam(point cabeca)
{
	return(cabeca->fim-1);
}

void busca (point cabeca, char* letras)                        //Busca palavras no dicionario ou prefixos existentes
{
	
	point P = checar(cabeca,letras);                           //P vai receber a ultima letra mais proxima da palavra no dicionario
	
	printf("\n");
	
	if(P==cabeca)                                              //se P for a propria cabeça, sabemos que não ha nenhuma letra em comum no dicionario
	{
		if(estaVazio(cabeca)!=0)
			printf(" Dicionario Vazio!\n");
		else
			printf("\n Não existe nada parecido no dicionario.\n");

	}
	else                                                        
	{
			if((P->fim!=0)&&(letras[P->pos+1]=='\0'))          //verifica se a semelhança encontrada corresponde com toda a palavra, ou melhor, a palavra existe por completo no dicionario
			{      //return P->sig;
				printf(" %s Significa: %s",letras,P->sig);     // se sim mostra-se o significado salvo.
			}
			else                                               // senão apresenta a semelhaça dessa palavra com outras do dicionario
			{
				char *c=(char*)calloc(100,sizeof(char));
				int i;
				
				for(i=0;i<=P->pos;i++)
				{
					c[i]=letras[i];	
				}
				printf("\n Palavra nao encontrada. O valor %s  esta presente em outras palavras.\n",c);  
				
			}
	}		
	
}

int main ()
{
	int op=0;
	
	char c[20],d[30];
	
	nodo a;
	iniciaCabeca(&a);
	 
	while(op!=-1)                         //Menu de opções do dicionario
	{
		printf("Digite a opção:\n\n1-Adicionar\n\n2-Deletar\n\n3-Buscar\n\n4-Informa numero de palavras salvas\n\n (-1)-Sair\n\n");
		scanf("%d",&op);
		
		switch(op)
		{
		case (1):
			printf("\nDigite a palavra: ");
			scanf("%s",c);
			printf("\nDigite a Descricao: ");
			scanf("%s",d);
			insere(&a,c,d);
			getch();
		break;
		
		case (2):
		
			printf("\nDigite a palavra: ");
			scanf("%s",c);
			remover(&a,c);
			getch();
		break;
		
		case 3:
		
			printf("\nDigite a palavra: ");
			scanf("%s",c);
			busca(&a,c);
			getch();
		break;
		case 4:
			printf("Numero de palavras no dicionario: %d",dicionarioTam(&a));
			getch();
		break;
		
		default:
		
			printf("\nDigite a palavra: ");
			scanf("%s",c);
			remover(&a,c);
		break;
		}
		system("cls");
	}
	
	system("pause");
		
		
		
}


