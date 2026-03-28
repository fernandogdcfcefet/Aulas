#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct processo *apontador;

typedef struct processo
{
    int pid,tempo,prioridade;
    apontador prox, ant;
}processo;

typedef struct
{
    apontador frente,tras;
    int tam;
}fila;

void inicializa(fila *minhafila)
{
    minhafila->frente = (apontador) malloc(sizeof(processo));
    minhafila->tras = minhafila->frente;
    minhafila->tras->prox = NULL;
    minhafila->tras->ant = NULL;
    minhafila->tam = 0;
}

void enfilera(fila *minhafila, int Pid,int T,int P)
{
	apontador aux;
    minhafila->tras->prox = (apontador)malloc(sizeof(processo));
    minhafila->tras->pid = Pid;
    minhafila->tras->tempo = T;
    minhafila->tras->prioridade = P;
    aux = minhafila->tras;
    minhafila->tras = minhafila->tras->prox;
    minhafila->tras->ant = aux;
	minhafila->tras->prox = NULL;
    minhafila->tam++;

}

int vazia(fila minhafila)
{
    return ((minhafila.frente == minhafila.tras)&&(minhafila.tam ==0));
}

void desenfilera(fila *minhafila)
{
    if(vazia(*minhafila))
    {
    	printf("\nFila VAZIA\n");
    }
    else
	{
        apontador q = minhafila->frente;
        minhafila->frente = minhafila->frente->prox;
        minhafila->frente->ant = NULL;
        free(q);
        minhafila->tam--;
    }
}

void troca(apontador *a,apontador *b)
{
    apontador aux = *a;
    *a = *b;
    *b = aux;
}

void FIFO(fila *minhafila)
{
    apontador aux = minhafila->frente;
    int i, tempExe = 0, s[minhafila->tam];
    while(aux->prox != NULL)
	{
		if((aux->pid)<10)
		{
			printf("\nPID: 00%d  -  Tempo: %d s  -  Prioridade: %d",aux->pid,(aux->tempo)/1000,aux->prioridade);
			aux = aux->prox;
		}
		else
		{
			printf("\nPID: 0%d  -  Tempo: %d s  -  Prioridade: %d",aux->pid,(aux->tempo)/1000,aux->prioridade);
			aux = aux->prox;
		}
    }
    aux = minhafila->frente;
    s[0]=aux->tempo;
    aux = aux->prox;
    for(i=1; i<minhafila->tam; i++)
    {
    	s[i]= s[i-1] + aux->tempo;
		aux = aux->prox;
		tempExe+= s[i];
    }
    printf("\n\nTempo de execucao total: %d s: ", (tempExe+s[0])/1000);
    printf("\n\n");
}

void SJF(fila *minhafila)
{
    int i,j,tempExe = 0, s[minhafila->tam];
    apontador aux = minhafila->frente, vet[minhafila->tam];
    for(i=0;i<minhafila->tam;i++)
	{
        vet[i] = aux;
        aux = aux->prox;
    }
	for(i=0;i<minhafila->tam;i++)
	{
            for(j=0;j<minhafila->tam;j++)
			{
                    if(vet[i]->tempo<vet[j]->tempo)
					{
                        troca(&vet[i] , &vet[j]);
                    }
                    if(vet[i]->tempo == vet[j]->tempo)
                    {
                    	if(vet[i]->prioridade > vet[j]->prioridade)
						{
                        	troca(&vet[i],&vet[j]);
                    	}
                    }
            }
    }
	for(i=0;i<minhafila->tam;i++)
	{
		if((vet[i]->pid)<10)
		{
			printf("\nPID: 00%d  -  Tempo: %d s  -  Prioridade: %d",vet[i]->pid,(vet[i]->tempo)/1000,vet[i]->prioridade);
		}
		else
		{
			printf("\nPID: 0%d  -  Tempo: %d s  -  Prioridade: %d",vet[i]->pid,(vet[i]->tempo)/1000,vet[i]->prioridade);
		}

    }
    aux = vet[0];
    s[0]=aux->tempo;
    for(i=1; i<minhafila->tam; i++)
    {
    	aux = vet[i];
    	s[i]= s[i-1] + aux->tempo;
		tempExe+= s[i];
    }
    printf("\n\nTempo de execucao total: %d s: ", (tempExe+s[0])/1000);
    printf("\n\n");
}

void SRT(fila *minhafila)
{
    int i,j, op,tempExe = 0, quantum, s[minhafila->tam];
    apontador aux = minhafila->frente, vet[minhafila->tam];
    for(i=0;i<minhafila->tam;i++)
	{
        vet[i] = aux;
        aux = aux->prox;
    }
	for(i=0;i<minhafila->tam;i++)
	{
            for(j=0;j<minhafila->tam;j++)
			{
                    if(vet[i]->prioridade > vet[j]->prioridade)
					{
                        troca(&vet[i],&vet[j]);
                    }
                    if(vet[i]->prioridade == vet[j]->prioridade)
                    {
                    	if(vet[i]->tempo<vet[j]->tempo)
						{
                        	troca(&vet[i],&vet[j]);
                    	}
                    }
            }
    }
    for(i=0;i<minhafila->tam;i++)
	{
		if((vet[i]->pid)<10)
		{
			printf("\nPID: 00%d  -  Tempo: %d s  -  Prioridade: %d",vet[i]->pid,(vet[i]->tempo)/1000,vet[i]->prioridade);
		}
		else
		{
			printf("\nPID: 0%d  -  Tempo: %d s  -  Prioridade: %d",vet[i]->pid,(vet[i]->tempo)/1000,vet[i]->prioridade);
		}
    }
    aux = vet[0];
    s[0]=aux->tempo;
    for(i=1; i<minhafila->tam; i++)
    {
    	aux = vet[i];
    	s[i]= s[i-1] + aux->tempo;
		tempExe+= s[i];
    }
    printf("\n\nTempo de execucao total: %d s: ", (tempExe+s[0])/1000);
    printf("\n\n");
}

int main()
{
    int op,pid=1,t,p;
    fila mf;
	inicializa(&mf);
	while(op!=5)
	{
		system("cls");
		printf("\n-------------------------------------------------\n");
		printf("\tESCALONAMENTO DE PROCESSOS\n");
		printf("-------------------------------------------------\n");
		printf("1- Entre com a lista de processos\n");
		printf("2- Algoritmo FIFO\n");
		printf("3- Algoritmo SJF\n");
		printf("4- Algoritmo SRT\n");
		printf("5- Sair\n");
		printf("\nOPCAO: ");
		scanf("%d",&op);
		if(op == 1)
		{
			system("cls");
			printf("\n-------------------------------------------------\n");
			printf("\tLISTA DE PROCESSOS\n");
			printf("-------------------------------------------------\n");
			if (pid<10)
			{
				printf("\nPROCESSO (PID): 00%d", pid);
				printf("\nTEMPO DE EXECUCAO: ");
				scanf("%d", &t);
				t=t*1000;
				printf("PRIORIDADE: ");
				scanf("%d", &p);
				enfilera(&mf, pid, t, p);
				pid++;
			}
			else
			{
				printf("\nPROCESSO (PID): 0%d", pid);
				printf("\nTEMPO DE EXECUCAO: ");
				scanf("%d", &t);
				t=t*1000;
				printf("PRIORIDADE: ");
				scanf("%d", &p);
				enfilera(&mf, pid, t, p);
				pid++;
			}
		}
		if(op == 2)
		{
			system("cls");
			printf("\n-------------------------------------------------\n");
			printf("\tFIRST IN - FIRST OUT\n");
			printf("-------------------------------------------------\n");
        	FIFO(&mf);system("pause");
		}
		if(op == 3)
		{
			system("cls");
			printf("\n-------------------------------------------------\n");
			printf("\t\tSHORTEST JOB FIRST\n");
			printf("-------------------------------------------------\n");
        	SJF(&mf);
        	printf("\n\n");
			system("pause");
		}
		if(op == 4)
		{
			system("cls");
			printf("\n-------------------------------------------------\n");
			printf("\tSHORTEST REMAINING TIME\n");
			printf("-------------------------------------------------\n");
        	SRT(&mf);
        	printf("\n\n");
        	system("pause");
		}
	}
return 0;
}
