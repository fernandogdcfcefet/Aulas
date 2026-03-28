#include <stdio.h>
#include <stdio.h>
#define MAXTAM 5

typedef int Apontador;
typedef int Chave;

   typedef struct {
        Chave Chave;
    }funcionario;

    typedef struct{
        funcionario f1[MAXTAM];
        Apontador Frente,Tras;
    }NovaFila;
    void FFVazia(NovaFila*Fila)
    {
        Fila->Frente=1;
        Fila-> Tras=Fila-> Frente;
    }
    int Vazia(NovaFila Fila)
    {
       return(Fila.Frente==Fila.Tras);

    }
    void Enfileira (funcionario f1,NovaFila*Fila)
    {
        if(Fila->Tras%MAXTAM+1==Fila->Frente)
            printf("Erro: Fila está Cheia\n");
        else
        Fila->f1[ Fila->Tras-1]=f1;
        Fila->Tras=Fila->Tras%MAXTAM+1;

    }
    void Desenfileira(NovaFila*Fila,funcionario*f1)
    {
        if(Vazia(*Fila))
            printf("Erro: Fila está Vazia\n");
        else
       {
        *f1 = Fila->f1[Fila->Frente-1];
       Fila-> Frente=Fila->Frente%MAXTAM+1;
       }


    }
int main(){
NovaFila UmaFila;
    funcionario F1={1};
    funcionario F2={2};
    funcionario F3={3};


   Apontador Frente,Tras;

    Insere(F1,&UmaFila);




}
