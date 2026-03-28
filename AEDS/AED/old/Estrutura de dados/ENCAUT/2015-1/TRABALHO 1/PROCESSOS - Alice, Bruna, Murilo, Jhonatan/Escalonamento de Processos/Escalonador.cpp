#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#define TAM 5

typedef struct TipoCelula *TipoApontador;

typedef struct Processo
{
	int id, hora, exec, prioridade, executado;
	/*
	id = identificador do processo
	hora = o tempo que ele entra no sistema
	exec = o tempo de duração
	prioridade = a prioridade sobre outros processos
	executador = é um atributo auxiliar que é quanto o processo já foi executado.
	*/
}Processo;

typedef struct TipoCelula
{
	Processo processo;
	TipoApontador prox;
}TipoCelula; //Estrutura da Célula

typedef struct TipoFila
{
	TipoApontador frente, tras;
	int tam;
}TipoFila; //Estrutura da Fila

void Esvazia(TipoFila *minhaFila)
{
	minhaFila->frente=(TipoApontador)malloc(sizeof(TipoCelula));
	minhaFila->tras=minhaFila->frente;
	minhaFila->frente->prox=NULL;
	minhaFila->tam=0;
} //Procedimento para esvaziar a Fila

int VerificaVazia(TipoFila minhaFila)
{
	return (minhaFila.frente==minhaFila.tras);
} //Procedimento para Esvaziar uma Fila

void Enfileira(TipoFila *minhaFila, int i, int h, int e, int p)
{
	if(minhaFila->tam>=TAM)
	{
		printf("Lista de processos cheia!\n");
	}
	else
	{
		minhaFila->tras->prox=(TipoApontador) malloc(sizeof(TipoCelula));
		minhaFila->tras=minhaFila->tras->prox;
		minhaFila->tras->processo.id=i;
		minhaFila->tras->processo.hora=h;
		minhaFila->tras->processo.exec=e;
		minhaFila->tras->processo.prioridade=p;
		minhaFila->tras->processo.executado=0;
		minhaFila->tras->prox=NULL;
		minhaFila->tam++;
	}
} // Procedimento para enfileirar processos

void Desenfileira(TipoFila *minhaFila)
{
	TipoApontador A;
	if(VerificaVazia(*minhaFila)==1)
	{
		printf("Sua lista esta vazia!");
	}
	A=minhaFila->frente;
	minhaFila->frente=minhaFila->frente->prox;
	free(A);
	minhaFila->tam--;
} // Procedimento para desenfileirar processos

int Menu()
{
		printf("\n\tESCALONAMENTO DE PROCESSOS\n");
		printf("-------------------------------------------------\n");
		printf("1- Entre com a lista de processos\n");
		printf("2- Procedimento FIFO\n");
		printf("3- Procedimento SJF\n");
		printf("4- Procedimento SRT\n");
		printf("5- Sair\n");
		printf("\nOpcao: ");
}

void Organiza(TipoFila *minhaFila)
{
	TipoApontador antes=minhaFila->frente, aux=antes->prox;
	while(aux->prox!=NULL)
	{
		if((aux->processo.hora)>(aux->prox->processo.hora))
		{
			antes->prox=aux->prox;
			aux->prox=aux->prox->prox;
			antes->prox->prox=aux;
			antes=minhaFila->frente;
			aux=minhaFila->frente->prox;
		}
		else
		{
			aux=aux->prox;
			antes=antes->prox;
		}
	}	
} //Procedimento criado para organizar a fila por ordem de chegada, ou seja, ordenando por hora de chagada.

void OrganizaPrioridade(TipoFila *minhaFila)
{
	Organiza(minhaFila);
	TipoApontador antes=minhaFila->frente, aux=antes->prox;
	while(aux->prox!=NULL)
	{
		if((aux->processo.hora)==(aux->prox->processo.hora))
		{
			if((aux->processo.exec)==(aux->prox->processo.exec))
			{
				if((aux->processo.prioridade)<(aux->prox->processo.prioridade))
				{
					antes->prox=aux->prox;
					aux->prox=aux->prox->prox;
					antes->prox->prox=aux;
					antes=minhaFila->frente;
					aux=minhaFila->frente->prox;
				}
			}
			if((aux->processo.exec)>(aux->prox->processo.exec))
			{
				antes->prox=aux->prox;
				aux->prox=aux->prox->prox;
				antes->prox->prox=aux;
				antes=minhaFila->frente;
				aux=minhaFila->frente->prox;
			}
			else
			{
				aux=aux->prox;
				antes=antes->prox;
			}
		}
		else
		{
			aux=aux->prox;
			antes=antes->prox;
		} 
	}
} // Procedimento usado para organizar a fila por ordem de tamanho, e por prioridade se for o caso.

void FIFO(TipoFila minhaFila)
{
	int tempo;
	if(VerificaVazia(minhaFila)==1)
	{
		printf("\nSua fila de processos esta vazia!\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		int tempo=0;
		Organiza(&minhaFila);
		TipoApontador aux=minhaFila.frente;
		printf("\n\tProcedimento FIFO - Lista de Processos\n\n");
		while(aux->prox!=NULL)
		{
			aux=aux->prox;
			if(tempo<aux->processo.hora)
			{
				tempo=aux->processo.hora-1;
			}
			tempo=tempo+(aux->processo.exec);
			printf("ID: %d  Hora: %d  Duracao: %d  Prioridade: %d\n", aux->processo.id, aux->processo.hora, aux->processo.exec, aux->processo.prioridade);
		}
		printf("\n\nO tempo total de execucao foi: %d unidades de tempo.\n\n", tempo);
		system("pause");
		system("cls");
	}
}

void SJF(TipoFila minhaFila)
{
	int tempo;
	if(VerificaVazia(minhaFila)==1)
	{
		printf("\nSua fila de processos esta vazia!\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		int tempo=0, i;
		OrganizaPrioridade(&minhaFila);
		TipoApontador aux=minhaFila.frente;
		printf("\n\tProcedimento SJF - Lista de Processos\n\n");
		while(aux->prox!=NULL)
		{
			aux=aux->prox;
			if(tempo<aux->processo.hora)
			{
				tempo=aux->processo.hora-1;
			}
			tempo=tempo+(aux->processo.exec);
			printf("ID: %d  Hora: %d  Duracao: %d  Prioridade: %d\n", aux->processo.id, aux->processo.hora, aux->processo.exec, aux->processo.prioridade);
		}
		printf("\n\nO tempo total de execucao foi: %d unidades de tempo.\n\n", tempo);
		system("pause");
		system("cls");
	}
}

void SRT(TipoFila minhaFila)
{
	if(VerificaVazia(minhaFila)==1)
	{
		printf("\nSua fila de processos esta vazia!\n\n");
		system("pause");
		system("cls");
	}
	else
	{
		int tempo=0, i, j, k;
		OrganizaPrioridade(&minhaFila);
		TipoApontador aux=minhaFila.frente->prox;
		printf("\n\tProcedimento SRT - Lista de Processos\n\n");
		while(aux!=NULL)
		{
			for(k=aux->processo.executado;k<(aux->processo.exec);k++)
			{	
				aux->processo.executado++;		
				printf("ID: %d  Hora: %d  Duracao Total: %d  Executado: %d\n", aux->processo.id, aux->processo.hora, aux->processo.exec, aux->processo.executado);
				tempo++;		
				if(aux->prox!=NULL)
				{
					if(tempo>=aux->prox->processo.hora)
					{
						if(aux->processo.exec - aux->processo.executado >aux->prox->processo.exec)
						{
							printf("\n");
							aux=aux->prox;
							k=aux->processo.executado;
							k--;
						}
					}
					
				}
			}
			printf("\n");
			aux=aux->prox;
			
		}
		aux=minhaFila.frente->prox;
		while(aux!=NULL)
		{
			for(k=aux->processo.executado;k<(aux->processo.exec);k++)
			{	
				aux->processo.executado++;		
				printf("ID: %d  Hora: %d  Duracao Total: %d  Executado: %d\n", aux->processo.id, aux->processo.hora, aux->processo.exec, aux->processo.executado);
				tempo++;
				
				if(aux->prox!=NULL)
				{
						if((aux->processo.exec - aux->processo.executado)<(aux->prox->processo.exec-aux->prox->processo.executado))
						{
							printf("\n");
							aux=aux->prox;
						}
				}
			}
			printf("\n");
			aux=aux->prox;
		}
		printf("\nO tempo total de execucao foi: %d unidades de tempo.\n\n", tempo);
		system("pause");
		system("cls");
	}
}

int main()
{
	//system("color 5E");
	TipoFila ML;
	Esvazia(&ML);
	VerificaVazia(ML);
	int op=0;
	
	while(op!=5)
	{
		Menu();
		scanf("%d",&op);
		system("cls");
		if (op==1)
		{
			Enfileira(&ML, 1, 7, 5, 1);
			Enfileira(&ML, 2, 1, 3, 2);
			Enfileira(&ML, 3, 5, 9, 1);
			Enfileira(&ML, 4, 8, 6, 1);
			Enfileira(&ML, 5, 1, 2, 5);
				
			printf("\nDados armazenados com sucesso.\n\n");
			system("pause");
			system("cls");
		}	
		if (op==2)
		{
			FIFO(ML);
		}
		if(op==3)
		{
			SJF(ML);
		}
		if(op==4)
		{
			SRT(ML);
		}
	}
	
	return 0;
}
