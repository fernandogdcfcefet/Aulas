#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define ALFABETO 27          

typedef struct nodo* raiz;

typedef struct nodo // 1)
{
	int end;                // na raiz é usado para salvar a quantidade de palavras
	int pos;
	int numGalhos; 
	raiz galho[ALFABETO];  
}nodo;

raiz conferir (raiz topo, char* palavra) // 2)  reaproveitada em inserir, buscar e remover.
{
	raiz ponto = topo; 
	int i = 0;
	
	while((palavra[i]) != '\0')
	{
		int num = palavra[i]-97; //***
		
		if (ponto->galho[num] == NULL)
		{
			return ponto;
		}
		else
		{
			ponto = ponto->galho[num];
		}
		i++;
		
	}
	return ponto;
}

void iniciaTopo(raiz a) // 3)
{
	int i;
	for(i=0;i<ALFABETO;i++)
	{
		a->galho[i]=NULL;
	}
	a->numGalhos=0;
	a->end = 1;
	a->pos = -1;		
}

void inicia(raiz a) // 4)
{
	int i;
	for(i=0;i<ALFABETO;i++)
	{
		a->galho[i]=NULL;
	}
	a->numGalhos=0;
	a->end=0;		
}


int estaVazio (raiz topo) // 5)
{
	return(topo->end==1);
}

void insere (raiz topo, char* palavra) // 6)
{
	raiz ponta = conferir(topo,palavra);
	
	int pos = ponta->pos; 
	
	if (palavra[pos+1]=='\0')
	{ 
		if(ponta->end!=0)
		{
			printf("Essa palavra ja existe no dicionario");
		}
		else
		{
			ponta->end = !0;
			topo->end++;
			
			printf("\n Palavra %s foi adicionada ao dicionario.",palavra);
		}
		
	}
	else
	{
		int num;
		
		while(palavra[pos+1]!='\0')
		{
			num = palavra[pos+1]-97;
			ponta->numGalhos++;
			ponta->galho[num] = (raiz)malloc(sizeof(nodo));
			ponta = ponta->galho[num];
			inicia(ponta);
			ponta->pos = pos+1;
			ponta->end = 0;
			pos++;
		}
		
		ponta->end = 1;
		
		int i=0;
		
		topo->end++;
		
		printf("\n Palavra %s foi adicionada ao dicionario.",palavra);
		
		
	}	
}



int remover (raiz topo, char* palavra) // 7)
                                      // procura a palavra no dicionario, se existir, 
                                      //a palavra será deletada e o retorno será true se nao será false.
{
	if(estaVazio(topo))
	{
		printf("Dicionario esta vazio!");
		
		return 0;
	}
	
	raiz ponta = conferir(topo,palavra);
	
	int pos = ponta->pos;
	
	if ((ponta->end==0)||(palavra[pos+1]!='\0')) // verifica se a ultima palavra foi encontrada 
	                                           // e se existe um fim nesta palavra
	{
		printf("\nEssa palavra não esta registrada no dicionario.\n");
		
		return 0;
	}
	else							// palavra encontrada no dicionario
	{
		if(ponta->numGalhos!=0)		
		{
			ponta->end=0;
			
		}
		else			
		{
			int num=0;
			do
			{
				num = palavra[pos]-97;
				palavra[pos]='\0';
				ponta=conferir(topo,palavra);
				free(ponta->galho[num]);
				ponta->galho[num]=NULL;
				ponta->numGalhos--;
				printf(".");
				
			}while((ponta->end==0) && (ponta->numGalhos==0));  // verifica se a palavra pertence à outra palavra
			
		}
		
		topo->end--;
		
		printf("\n  Palavra deletada!");
		
		return 1;
		
	}

}


int tamanhodicio(raiz topo) // 8)
{
	return(topo->end-1);
}

void busca (raiz topo, char* palavra) // 9)            
{
	
	raiz P = conferir(topo,palavra);
	
	if(P==topo)
	{
		if(estaVazio(topo)!=0)
			printf("O dicionario encontra-se vazio!\n");
		else
			printf("\n Não existe esta palavra no dicionario.\n");

	}
	else
	{
			if((P->end!=0)&&(palavra[P->pos+1]=='\0'))
			{     
				printf("\nPalavra %s encontrada.",palavra);
			}
			else
			{
				
				printf("\n Não existe esta palavra no dicionario.\n");
			}
	}
	
			
	
}

int main () // 10)
{
	int op=0;
	
	char c[20],d[30];
	
	nodo a;
	iniciaTopo(&a);
	 
	while(op!=-1)
	{
		printf("Digite a opcao:\n\n1-Cadastrar Palavra\n\n2-Remover\n\n3-Pesquisar\n\n4-Quantidade de Palavras\n\n (outro valor)-Sair\n\n");
		scanf("%d",&op);
		
		switch(op)
		{
		case (1):
			printf("\nDigite a palavra: ");
			scanf("%s",c);
			insere(&a,c);
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
			printf("Numero de palavras no dicionario: %d",tamanhodicio(&a));
			getch();
		break;
		
		default:
		
			printf("\nObrigado por usar nosso dicionario");
			
			getch();
			op=-1;
		break;
		}
		system("cls");
	}
		printf("Danke 3,14R\n");
		system("pause");
		
		
		
}


